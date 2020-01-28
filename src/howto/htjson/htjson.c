/* JSON download and parsing */
    
#include "draw2dall.h"
#include "httpreq.h"
#include "json.h"

/*---------------------------------------------------------------------------*/

typedef struct _product_t Product;
typedef struct _pjson_t PJson;

struct _product_t
{
    uint32_t type;
    String *code;
    String *description;
    Image *image64;
    real32_t price;
};

struct _pjson_t
{
    int32_t code;
    uint32_t size;
    ArrPt(Product) *data;
};

/*---------------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
    Stream *json = NULL;
    PJson *pjson = NULL;

    unref(argc);
    unref(argv);
    draw2d_start();

    /* Data binding */
    dbind(Product, uint32_t, type);
    dbind(Product, String*, code);
    dbind(Product, String*, description);
    dbind(Product, Image*, image64);
    dbind(Product, real32_t, price);
    dbind(PJson, int32_t, code);
    dbind(PJson, uint32_t, size);
    dbind(PJson, ArrPt(Product)*, data);

    /* WebService request */
    json = http_dget("serv.nappgui.com", 80, "/dproducts.php", NULL);

    /* JSON Parsing and stream close */
    if (json != NULL)
    {
        /* Json knows how to parse 'dbind' data types */
        pjson = json_read(json, NULL, PJson);
        stm_close(&json);
    }
    else
    {
        bstd_printf("WebService Error.");
    }

    if (pjson != NULL)
    {
        bstd_printf("JSON readed. Code: %d\n", pjson->code);
        bstd_printf("Readed %d products\n", pjson->size);
    
        arrpt_foreach(product, pjson->data, Product)
            uint32_t width, height;
            image_size(product->image64, &width, &height);
            bstd_printf("%2d %-20s %8.2f Image:%dx%dpx\n", product_i + 1, tc(product->code), product->price, width, height);
        arrpt_end()

        /* 'dbind' knows how to destroy registered data types */
        dbind_destroy(&pjson, PJson);
    }
    else
    {
        bstd_printf("JSON Processing Error.");
    }

    draw2d_finish();
    return 0;
}

