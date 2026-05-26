- PL/I supports a variety of operations, including data processing, numerical computation, and scientific computing. It features structured programming, recursion, and extensive handling of data types such as fixed-point and floating-point numbers, character strings, and bit strings.

- malloc is a function in C that allocates a specified number of bytes of memory on the heap and returns a pointer to it, while free is used to deallocate that memory when it is no longer needed. Both functions are essential for dynamic memory management in C programming.

- Heap memory is a large region of memory used for dynamic allocation, where data whose size or lifetime isn't known until runtime is stored. Unlike stack memory, heap memory must be manually managed by the programmer, as it does not automatically deallocate when a function returns.

- memory leak is a situation of forgetting to call free() when we are done of memory.

- In computer science, garbage collection is a form of automatic memory management. The garbage collector attempts to reclaim memory that was allocated by the program, but is no longer referenced; such memory is called garbage.

- Garbage collection also refers to the heap space becoming fragmented after multiple malloc() and free() calls

- A runtime library is a set of pre-written routines that a program calls during execution to perform common tasks like memory management, input/output, and error handling, acting as an intermediary between the program and the operating system. It is linked to the program either at compile time or during execution and provides essential services that simplify development and improve performance

- A typeless language is a programming language that does not enforce strict data types for variables, allowing for more flexibility in how data is used and manipulated. This can simplify coding but may also lead to errors if not managed carefully.

- A pointer in C is a variable that stores the memory address of another variable, allowing for direct memory manipulation and efficient data handling. Pointers are declared using the asterisk (*) symbol and can be initialized with the address of a variable using the ampersand (&) operator.

- Lint programming refers to the automated checking of source code for programmatic and stylistic errors using a tool called a linter. This process helps improve code quality by identifying issues before the code is deployed.

- many small component approact to solve an overall set of problem

1. programs
2. data types, operators and expressions
3. control flow, if else while for
4. function and program structure, external variables, scope rules
5. pointers and address artithmetic
6. structures and unions
7. standard C I/O libraries
8. interface b/w C and Unix

- Rosetta Stone is an ancient Egyptian stone bearing inscriptions in several languages and scripts; their decipherment led to the understanding of hieroglyphic writing.

- Modulus refers to the operation that finds the remainder when one number is divided by another, often represented as "a % b" where "a" is the dividend and "b" is the divisor. For example, in the expression "5 % 2", the result is 1, since 5 divided by 2 leaves a remainder of 1.

- and &&
- not !
- or ||

- single quotes are single character while double quotes are character array.

- To run C code on Debian, you'll need to install a C compiler like gcc and then use the gcc command to compile your C code into an executable. You can install gcc by running sudo apt-get install build-essential in the terminal. Once installed, you can compile your C code by navigating to the directory containing your C file and running gcc -o output_file_name input_file_name.c. This will create an executable named output_file_name that you can run with ./output_file_name.

- ampersand in front of variable is a way to tell C language to give the address of the variable, rather than the value of the variable

- stdin is file that is read through until EOF

- stdout is where printf is going

- stderr is where error message is thrown

- The difference between Unicode and UTF is that Unicode is a standard character set, while UTF is the encoding used to translate that set into data a computer can store.

- Unicode is like a giant catalog or directory. It assigns a unique number (called a code point) to every character, emoji, and symbol from every language. It defines what the character is, but not how it is saved as bits and bytes.

- UTF (Unicode Transformation Format) is the actual implementation or "packaging". It defines how those code point numbers are converted into a sequence of binary bytes for storage or transmission

- '\n' character is a single character, despite containing two letters, as C prefers the obvious meaning independent of its particular character set, same can be observed as it uses the single quotes.

- expressions connected by `&&` or `||` are evaluated left to right.

- size of an array in C cannot be adjusted using an array declaration while the program is running.

- A segmentation fault, or segfault, is an error that occurs when a program tries to access a memory location it is not allowed to access, often leading to the operating system terminating the program to prevent further issues. This typically happens due to programming errors, such as accessing memory outside allocated bounds or using uninitialized pointers.

- Python, JS, PHP creats multicharacter thing called string constant

- In C single quotes are a character and double quotes are a character array or sting constant, and neither behaves like a string in python.

- In vanilla C, a character is a byte (8 bits).

- The C char type is just a number - representing 1 byte, indicating values upto 255.

- `ord()` function in python shows the ASCII value of character.

```py
>>> print("A", ord("A"))
A 65
>>> print("😀", ord("😀"))
😀 128512
```

- Hence C cannot represents emoji as chars

- float number is a 32-bit quantity, amouting to seven significant digits

- C data types:

1. int
2. float
3. char
4. short
5. long
6. double (double length of float)

- python3 returns the float when doing divisions of integers

- for loop in C contains three parts, first is perfomed when loop is entered, second part is the condition that control the loop and the third part is the re-evaluation step

- in mordern language, there are two kinds of loops, determinant and non determinant.

- Determinant loops are predictable, non-determinant loops are unpredictable until they actually run!

- In C-like languages the for and while loop are indeterminant, while in PHP or Python foreach loop is determinant.

- putchar is a function in C that writes a single character to the standard output (usually the console). It returns the character written as an unsigned char cast to an int, or EOF if an error occurs.

- relational `!=` not equal to has higher precedence over `=` equal to, thus surrounding it proper parantheses is required to prevent undesired consequences.

- `%f` is used for both float and double, `%.0f` is used to supress printing of non-existent fraction part.

- form of a function:

```
name (argument list, if any)
argument declarations, if any
  declarations
  statements
```

- function variables has local scope, which means two different functions can use the same variable without any conflict

- by default, single value argument are passed 'by value' and `&` is used in order to pass it 'by reference'.

- the `%s` format specification in `printf` expects a string terminating with a `\0`.

- The extern keyword is for declarations (telling the compiler a variable exists elsewhere), not for function parameters or local variable declarations.

- Definition refers to the place where the variable is actually created or assigned storage

- Declaration refers to the place where the nature of the variable (type) is stated but no storage is allocated

- In computing, endianness is the order in which bytes within a word data type are transmitted over a data communication medium or addressed in computer memory, counting only byte significance compared to earliness. Endianness is primarily expressed as big-endian (BE) or little-endian (LE). 

-  Form feed (\f or \ddd) sends a command that causes the printer to eject the current page and start printing on a new page. In modern computing, it's rarely used for actual printing, but it still appears in text formatting and document processing.

- External and static variables are initialzed to zero by default

- Explicitly initialized automatic variables are initialised each time the function they are in is called.

- unary - Consisting of or involving a single element or component, there is unary - but no unary +. These only work with one operand.

- relational operators have lower precedence than arithmetic operators

- the modulus operator can't be applied on `float` or `double`

```c
int count = 5;
++count;              // Increment (unary)
!flag;                // Logical NOT (unary)
~bits;                // Bitwise NOT (unary)
sizeof(int);          // Size of (unary)
&variable;            // Address of (unary)
*pointer;             // Dereference (unary)
```
- `char` and `int` are intermixed in arithmetic expression, thus every `char` is automatically converted into an `int`

- sequence of conversion for each arithmetic operations:

1. `char` and `short` are converted into `int` and `float` is converted into `double`.
2. then if either operand is `double`, the other is converted into `double` and the end result will be `double`.
3. if either operand is `long`, the other is converted into `long`
4. if either operand is `unsigned` the other is converted into `unsigned`

- all floating point arithmetic is done in double precision.

- An unsigned operand is a variable or value that can only represent non-negative numbers (zero and positive integers). It uses all its bits to store the magnitude of the number, with no bit reserved for the sign.

- signed or unsigned is represented by Most significant bit (MSB)
