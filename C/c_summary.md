# Summary C Programming
----

## Programming Environment
During this tutorial, we will use Linux. If you use Windows as your operating system, please install [*Windows Subsystem for Linux*](https://docs.microsoft.com/en-us/windows/wsl/install-win10).

### Editor vs IDE
While a fully fledged IDE offers many conveniences, for smaller programs and projects [*Visual Studio Code*](https://code.visualstudio.com/) is often enough. 

It's open source and available on all platforms (including BSD). Together with [*Microsoft's C/C++ plugin*]((https://code.visualstudio.com/docs/languages/cpp)), we have everything at hand to start coding.

### Compiler

For C, there are two main compilers available: GNU C Compiler (gcc) and Clang (We're going to ignore MSVC). Which one to choose often breaks down to personal preference.

Small hint: install both on your system. If you have a problem compiling your code, switch compilers. They output different error messages, which can be helpful when you're debugging.

__Compiler usage:__

gcc: 
```bash
gcc <input_file.c> -o <output_file>
```

clang:
```bash
clang <input_file.c> -o <output_file>
```

Both compilers support a variety of flags. To learn more read their manual pages with

```
man gcc
```
and 
```
man clang
```
Note: during the tutorial, we will use __clang__.

## Helpful lecture

### General

If you want to read about or find a C function: 

[cplusplus](https://www.cplusplus.com/)

### Linux

[The Linux Programming Interface](https://nostarch.com/tlpi)
\
"The Linux Programming Interface" is also very useful for the Operation Systems class ;)

To view manual pages, use \
```man command``` \
on your terminal or, in browser, visit [manual pages from Arch Linux](https://man.archlinux.org/)

### Windows
[C Runtime Library Reference](https://docs.microsoft.com/de-de/cpp/c-runtime-library/c-run-time-library-reference?view=msvc-160)

## Introduction to C

### Structue of a C program

```C
// 1.) Include Header files.
#include <HEADERFILE.h>

// 2.) Global variables
type name

// 3.) Functions
returntype function_name(parameter) {
    
    function body
}
```
__Header Files__ include predefined functions and macros. \
__Global Variables__ have a global scope, e.g. they can be accessed from all functions after declaration.

### Hello World!

Let's get started with our first C program. We're going to display a simple "Hello World" on the command line.

```C
#include <stdio.h>

int main() {
    printf("Hello World! \n");
    
    return 0;
}
```
After typing it out in our editor and saving it as ``hello_world.c``, we can compile it with
```
gcc hello_world.c -o hello_world
```
Finally, we can run it on the command line.
```bash
$ ./hello_world
Hello World!
```

The ``printf`` function is defined in the header file ``stdio.h``, which is provided by our compiler.

You can include your own header files with
```c
#include "FILENAME.h"
```
but more on that later.

Note: it's usual to return 0 if a function executes successfully and 1 if the function fails. If you want to build a program across platforms, use ``EXIT_SUCCESS`` and ``EXIT FAILURE`` as return values to avoid operating system specific confusions.

### Variables

The C language provides four basic arithmetic type specifiers:
<ul>
    <li> char </li>
    <li> int </li>
    <li> float </li>
    <li> double </li>
</ul>

These can be combined with modifiers
<ul>
    <li>signed</li>
    <li>unsigned</li>
    <li>short</li>
    <li>long</li>
</ul>

You can view the full list on [Wikipedia](https://en.wikipedia.org/wiki/C_data_types).

``char`` values respond to their  [ASCII encoded value](https://www.ascii-code.com/).

As an example:
```c
char a = 'A';
```
would resolve to 65.

If you're unsure about the size of a certain datatype, you can use 
```c
int size = sizeof(TYPE)
```

For an example, check out ``get_sizes.c`` in the example folder.

## Constants

In C, variables are mutable. For example:
```c
int i = 2;
i = 3;
```
is valid.

In opposite to that, __constants__ are immutable.

There are two ways to define a constant.
The old one:
```c
#define VAT 19.0
```

The newer one, which we will use:
```c
const float VAT = 19.0;
```
For an example, check out ``constants.c`` in the example folder.

## Operators

For a complete list, check out the [cppreference](https://en.cppreference.com/w/cpp/language/expressions#Operators).

### Arithmetic operators
| Operator name  | Syntax       |
| :------------- | :----------: |  
| Addition       | ``a + b``    |  
| Substraction   | ``a - b``    |
| Multiplication | ``a * b``    |
| Division       | ``a / b``    |
| Modulo         | ``a % b``    |

Increment and Decrement operands can be applied pre- and postfix. \
Pre-increment/decrement means the values get incremented/decremented before being used in an expression. \
Post-increment/decrement means the values get incremented/
decremented after being used in an expression.

| Operator name  | Syntax       |
| :------------- | :----------: |
| Pre-increment  | ``++a``      |
| Post-increment | ``a++``      |
| Pre-decrement  | ``--a``      |
| Post-decrement | ``a--``      |

### Comparison operators
| Operator name  | Syntax       |
| :------------- | :----------: |
| Equal to       | ``a == b``   |
| Not equal to   | ``a != b``   |

### Logical operators
| Operator name  | Syntax       |
| :------------- | :----------: |
| NOT            | ``!a``       |
| AND            | ``a && b``   |
| OR             | ``a \|\| b``   |

Note: these are __not__ bitwise operators.

## Basic functions

### __printf__

Calling ``printf(param)`` prints the passed
parameter to *stdout*.

```c
printf("prints this to stdout");
```
Strings have to be put in double quotes.
In C, a string is series of ``char`` values.

If we want to print the value of a variable, we have to use ``%``, the escape sign. It's followed by a specifier that signals what data type we want to print.

```c
#include <stdio.h>

int main() {
    int i = 5;
    float f = 5.6;

    printf("Value of i: %d, Value of f: %f", i, j);
}

```

| specifier      | output       |
| :------------- | :----------: |
| d or i         | signed decimal integer| 
| c              | character    |
| s              | strings      |
| f              | float        |
| %              | writing ``%%`` prints a single ``%``| 

For a full list of specifier, see [cplusplus](https://www.cplusplus.com/reference/cstdio/printf/).

### Escape sequences

``\n`` is a line break on unix like systems. \
``\r\n`` is used for a line break in Windows.

You can find a complete list of escape sequences [here](https://en.wikipedia.org/wiki/Escape_sequences_in_C).

### getchar

The function ``getchar()`` reads a single char from the keybord buffer and maps it to the ASCII table.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a char:\n");
    
    char c = getchar();
    
    printf("You've entered: %c \n", c);

    return EXIT_SUCCESS;
}
```
You can find the example code in ``getchar_example.c`` in the example directory.

### scanf

The function ``scanf()`` reads from the keyboard buffer until returned.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    
    printf("How old are you? \n");

    scanf("%i", &age);

    printf("You're %i years old \n", age);

    return EXIT_SUCCESS;

}
```
You can find the example code in ``scanf_example.c`` in the example directory.

## Calling a function

```c
#include <stdio.h>
#include <stdlib.h>

int add(int num_1, int num_2) {
    int result;

    result = num_1 + num_2;

    return result;
}

int main() {
    int result;
    
    result = add(7,6);

    printf("Result = %d\n", result);

    return EXIT_SUCCESS;
}
```

To execute a function, we can simply call it in ``main()``. 

You can find the example code in ``func_call.c`` in the example directory.

## Scope 

Depending on the variable type, their scope differs.

__local variables__ are contained inside functions. They're valid between being declared and the end of the function.

__global variables__ are declared outside of functions, usually after the ``include`` statements (see chapter 'Structure of a C Program'). They can be accessed from any point of our program (inside the same file).

__extern variables__ are variables defined, globally, in another file.

__local static variables__ are being defined and initialized once, yet they keep their value between the function being called.

To understand this concept better, check out ``variable_example.c`` in the variables subdirectory of examples.

## If/else statement

```c
if (expression evalutes to true) {
    execute instructions 
} else {
    execute instructions
}
```
If/else statements always follow the same pattern:

If an expression evalutes to __true__, the instructions inside the brackets will be executed. If the expression evalutes to __false__, the instructions defined inside the else brackets will be executed.

Note: If statements can be standalone.

For an example, check out ``if_expression.c`` in the example_code directory.  

## Switch/case
Using the switch/case construct is another option to execute instructions conditionally. \
It's preferable to use them when you have to check for multiple
conditions.

```c
#include <stdlib.h>
#include <stdio.h>

int main() {

    int number;
    printf("Please enter a number:\n");
    scanf("%d", &number);

    switch(number) {
        case 1: 
            printf("number equals one\n");
            // IMPORTANT: insert a break statement, else it 
            // will "fall through"
            break;
        case 2:
            printf("number equals two\n");
            break;
        default:
            printf("number equals %i\n", number);    
    }

    return EXIT_SUCCESS;
}
```
If you do not insert a break statement, you will "fall through", which means it will continue with the next case. This can be wanted behavior at some points, usually you don't want to forget your break statement though!

## for-loop

```c
for (start_value; condition; increment) {
    instruction
}
```
