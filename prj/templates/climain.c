/* NAppGUI C++/Cli Console Application */
    
#include "coreall.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    unref(args);
    core_start();
    System::Console::WriteLine("Hello world from System!");
    bstd_printf("Hello world from NAppGUI!\n");
    core_finish();
    return 0;
}
