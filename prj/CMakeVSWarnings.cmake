# CMake Visual Studio additional Warnings
# This file is part of NAppGUI-SDK project
# See README.txt and LICENSE.txt

# Visual Studio Additional Warnings: Extracted from here:
# https://msdn.microsoft.com/en-us/library/23k5d385(v=vs.140).aspx
#
# 'Manual' activation of compiler warning disabled by default in -W4
#  We don't use -Wall for compile problems in VS2017
# https://developercommunity.visualstudio.com/content/problem/174539/objbaseh-error-when-compiling-with-permissive-and.html
#
#------------------------------------------------------------------------------
macro(setVisualStudioWarnings)
set(AdditionalDefinitions
	# Warning level
    "/W4"
    "/wd4530"
	"/wd4514"
	"/wd4625"
	"/wd4626"

    # Additional warning over W4
    # (level 4) enumerator 'identifier' in a switch of enum 'enumeration' is not explicitly handled by a case label.
    "/w44061"

    # (level 4) enumerator 'identifier' in a switch of enum 'enumeration' is not handled
    "/w44062"

    # (level 3) 'operator/operation': unsafe conversion from 'type of expression' to 'type required'
    "/w44191"

    # (level 4) 'identifier': conversion from 'type1' to 'type2', possible loss of data
    "/w44242"

    # (level 4) 'operator': conversion from 'type1' to 'type2', possible loss of data
    "/w44254"

    # (level 4) 'function': no function prototype given: converting '()' to '(void)'
    "/w44255"

    # (level 4) 'function': member function does not override any base class virtual member function
    "/w44263"

    # (level 1) 'virtual_function': no override available for virtual member function from base 'class'; function is hidden
    "/w44264"

    # (level 3) 'class': class has virtual functions, but destructor is not virtual
    "/w44265"

    # (level 4) 'function': no override available for virtual member function from base 'type'; function is hidden
    "/w44266"

    # (level 3) 'operator': unsigned/negative constant mismatch
    "/w44287"

    # (level 4) nonstandard extension used : 'var' : loop control variable declared in the for-loop is used outside the for-loop scope
    "/w44289"

    # (level 4) 'operator': expression is always false
    "/w44296"

    # (level 2) 'conversion': truncation from 'type1' to 'type2'
    "/w44302"

    # (level 1) 'variable' : pointer truncation from 'type' to 'type'
    "/w44311"

    # (level 1) 'operation' : conversion from 'type1' to 'type2' of greater size
    "/w44312"

    # (level 4) 'type' : use of undefined type detected in CLR meta-data - use of this type may lead to a runtime exception
    "/w44339"

    # (level 1) behavior change: 'function' called, but a member operator was called in previous versions
    "/w44342"

    # (level 1) behavior change: 'member1' called instead of 'member2'
    "/w44350"

    # 'this' : used in base member initializer list
    "/w44355"

    # (level 4) 'action': conversion from 'type_1' to 'type_2', signed/unsigned mismatch
    "/w44365"

    # (level 3) layout of class has changed from a previous version of the compiler due to better packing
    "/w44370"

    # (level 3) layout of class may have changed from a previous version of the compiler due to better packing of member 'member'
    "/w44371"

    # (level 4) signed/unsigned mismatch
    "/w44388"

    # (level 2) 'function': function signature contains type 'type'; C++ objects are unsafe to pass between pure code and mixed or native
    "/w44412"

    # (level 4) missing type specifier - int assumed. Note: C no longer supports default-int
    "/w44431"

    # (level 4) 'class1' : Object layout under /vd2 will change due to virtual base 'class2'
    "/w44435"

    # (level 4) dynamic_cast from virtual base 'class1' to 'class2' could fail in some contexts
    "/w44437"

    # (level 3) top level '__unaligned' is not implemented in this context
    "/w44444"

    # (level 4) a forward declaration of an unscoped enumeration must have an underlying type (int assumed)
    "/w44471"

    # (level 1) 'identifier' is a native enum: add an access specifier (private/public) to declare a managed enum
    "/w44472"

    # (level 4) 'function': unreferenced inline function has been removed
    "/w44514"

    # (level 4) 'type name': type-name exceeds meta-data limit of 'limit' characters
    "/w44536"

    # (level 1) expression before comma evaluates to a function which is missing an argument list
    "/w44545"

    # (level 1) function call before comma missing argument list
    "/w44546"

    # (level 1) 'operator': operator before comma has no effect; expected operator with side-effect
    "/w44547"

    # (level 1) expression before comma has no effect; expected expression with side-effect
    "/w44548"

    # (level 1) 'operator': operator before comma has no effect; did you intend 'operator'?
    "/w44549"

    # (level 1) expression has no effect; expected expression with side-effect
    "/w44555"

    # (level 3) '__assume' contains effect 'effect'
    "/w44557"

    # (level 4) informational: catch(�) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught
    "/w44571"

    # (level 4) 'identifier' is defined to be '0': did you mean to use '#if identifier'?
    "/w44574"

    # (level 3) 'symbol1' has already been initialized by another union member in the initializer list, 'symbol2'
    "/w44608"

    # (level 3) #pragma warning: there is no warning number 'number'
    "/w44619"

    # (level 4) 'derived class': default constructor could not be generated because a base class default constructor is inaccessible
    "/w44623"

    # (level 4) 'derived class': copy constructor could not be generated because a base class copy constructor is inaccessible
    "/w44625"

    # (level 4) 'derived class': assignment operator could not be generated because a base class assignment operator is inaccessible
    "/w44626"

    # (level 1)	digraphs not supported with -Ze. Character sequence 'digraph' not interpreted as alternate token for 'char'
    "/w44628"

    # (level 3)	'instance': construction of local static object is not thread-safe
    "/w44640"

    # (level 4)	'symbol' is not defined as a preprocessor macro, replacing with '0' for 'directives'
    "/w44668"

    # (level 4)	'symbol' : no directional parameter attribute specified, defaulting to [in]
    "/w44682"

    # (level 3)	'user-defined type': possible change in behavior, change in UDT return calling convention
    "/w44686"

    # (level 1)	'function': signature of non-private member contains assembly private native type 'native_type'
    "/w44692"

    # (level 4)	'function': function not inlined
    #"/w44710"

    # (level 3)	storing 32-bit float result in memory, possible loss of performance
    "/w44738"

    # (level 4)	section name 'symbol' is longer than 8 characters and will be truncated by the linker
    "/w44767"

    # (level 3)	'symbol' : object name was truncated to 'number' characters in the debug information
    "/w44786"

    # We consider it as Compiler optimization
    # (level 4) 'bytes' bytes padding added after construct 'member_name'
    # "/w44820"

    # (level 2)	conversion from 'type1' to 'type2' is sign-extended. This may cause unexpected runtime behavior
    "/w44826"

    # (level 4) trigraph detected: '??%c' replaced by '%c'
    "/w44837"

    # (level 1)	wide string literal cast to 'LPSTR'
    "/w44905"

    # (level 1)	string literal cast to 'LPWSTR'
    "/w44906"

    # (level 1)	'declarator': a GUID can only be associated with a class, interface, or namespace
    "/w44917"

    # (level 1)	illegal copy-initialization; more than one user-defined conversion has been implicitly applied
    "/w44928"

    # (level 4)	we are assuming the type library was built for number-bit pointers
    "/w44931"

    # (level 1)	reinterpret_cast used between related classes: 'class1' and 'class2'
    "/w44946"

    # 'function': profile-guided optimizations disabled because optimizations caused profile data to become inconsistent
    "/w44962"

    # (level 4)	'symbol': exception specification does not match previous declaration
    "/w44986"

    # (level 4)	nonstandard extension used: 'throw (...)'
    "/w44987"

    # (level 4)	'symbol': variable declared outside class/function scope
    "/w44988"
)
endmacro()
