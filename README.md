# C Programming and Computer Science Notes

## PL/I

* PL/I supports a variety of operations, including data processing, numerical computation, and scientific computing.
* Features include:

  * Structured programming
  * Recursion
  * Extensive data type support:

    * Fixed-point numbers
    * Floating-point numbers
    * Character strings
    * Bit strings

---

# Memory Management

## Dynamic Memory Allocation

### `malloc()` and `free()`

* `malloc()` allocates a specified number of bytes on the heap and returns a pointer to the allocated memory.
* `free()` releases previously allocated memory.
* Both are essential for dynamic memory management in C.

### Heap Memory

* Heap memory is used for dynamic allocation.
* Data whose size or lifetime is not known until runtime is typically stored on the heap.
* Unlike stack memory, heap memory is not automatically released when a function returns.
* The programmer is responsible for managing heap memory.

### Memory Leak

* A memory leak occurs when dynamically allocated memory is never released using `free()`.
* Over time, memory leaks can cause increased memory consumption and program instability.

### Garbage Collection

* Garbage collection is automatic memory management.
* A garbage collector reclaims memory that is no longer referenced by a program.

### Heap Fragmentation vs Garbage Collection

* **Heap Fragmentation:** Memory becomes split into small non-contiguous blocks due to repeated allocations and deallocations.
* **Garbage Collection:** Automatic reclamation of unused memory.

---

# Runtime Libraries

* A runtime library is a collection of pre-written routines used during program execution.
* Common services include:

  * Memory management
  * Input/output
  * Error handling
* Runtime libraries act as intermediaries between applications and the operating system.

---

# Type Systems

## Typeless Languages

* A typeless language does not associate values with fixed types in the traditional sense.
* The term is uncommon today.
* Modern languages are generally classified as:

  * Statically typed
  * Dynamically typed

---

# Pointers

## What is a Pointer?

* A pointer is a variable that stores the memory address of another variable.

```c
int x = 10;
int *p = &x;
```

* `&` obtains the address of a variable.
* `*` dereferences a pointer.

### Benefits

* Direct memory manipulation
* Efficient data handling
* Dynamic memory allocation

---

# Linting

* A linter is a tool that checks source code for:

  * Programming errors
  * Style issues
  * Potential bugs
* Linting improves code quality before deployment.

---

# Software Design Philosophy

* A common software design philosophy is to solve large problems using many small, reusable components.

---

# Topics in C Programming

1. Programs
2. Data types, operators, and expressions
3. Control flow (`if`, `else`, `while`, `for`)
4. Functions and program structure
5. External variables and scope rules
6. Pointers and address arithmetic
7. Structures and unions
8. Standard C I/O libraries
9. Interface between C and Unix

---

# Rosetta Stone

* The Rosetta Stone is an ancient Egyptian stone containing inscriptions in multiple scripts.
* Its decipherment enabled the understanding of Egyptian hieroglyphics.

---

# Operators

## Modulus Operator

* `%` returns the remainder after division.

```c
5 % 2  // Result: 1
```

* Works only with integer types in C.

## Logical Operators

| Operator | Meaning     |   |            |
| -------- | ----------- | - | ---------- |
| `&&`     | Logical AND |   |            |
| `        |             | ` | Logical OR |
| `!`      | Logical NOT |   |            |

### Short-Circuit Evaluation

* Expressions connected by `&&` or `||` are evaluated from left to right.

---

# Characters and Strings

## Single vs Double Quotes

```c
'A'    // Character constant
"A"    // String literal
```

* Character constants use single quotes.
* String literals use double quotes and are terminated by `'\0'`.

### Character Arrays vs Python Strings

* C strings are character arrays.
* They are much simpler and less feature-rich than Python strings.

### Escape Sequences

```c
'\n'   // Newline
'\f'   // Form feed
```

* `'\n'` is a single character despite consisting of two symbols.
* `'\f'` traditionally caused printers to start a new page.

---

# Running C on Debian

Install GCC:

```bash
sudo apt install build-essential
```

Compile:

```bash
gcc -o program source.c
```

Run:

```bash
./program
```

---

# Standard Streams

| Stream   | Purpose         |
| -------- | --------------- |
| `stdin`  | Standard input  |
| `stdout` | Standard output |
| `stderr` | Standard error  |

---

# Unicode and UTF

## Unicode

* A universal character set.
* Assigns code points to characters, symbols, and emoji.

## UTF (Unicode Transformation Format)

* Defines how Unicode code points are stored as bytes.
* Examples:

  * UTF-8
  * UTF-16
  * UTF-32

Unicode defines *what* a character is.

UTF defines *how* it is stored.

---

# Arrays

## Array Size

* Traditional array sizes cannot be changed after declaration.

### Number of Elements

```c
int n = sizeof(v) / sizeof(v[0]);
```

* Works only for actual arrays in the current scope.

---

# Segmentation Faults

* A segmentation fault occurs when a program accesses memory it is not allowed to access.
* Common causes:

  * Invalid pointers
  * Out-of-bounds access
  * Dereferencing NULL pointers

---

# Character Representation

## `char`

* A `char` is typically 1 byte (8 bits).
* Often stores values from 0–255 (unsigned) or -128–127 (signed).

### Character Promotion

* `char` and `short` are automatically promoted to `int` in arithmetic expressions.

### Unicode Limitation

* A single-byte `char` cannot represent most Unicode characters, such as emoji.

Python example:

```python
print(ord("A"))     # 65
print(ord("😀"))    # 128512
```

---

# Numeric Types

## Floating Point

* `float` is typically 32 bits.
* Provides about 7 significant decimal digits.

### Basic Types

```c
int
float
char
short
long
double
```

* `double` typically provides twice the precision of `float`.

### Printing

```c
printf("%f", value);
printf("%.0f", value);
```

* `%f` works for both `float` and `double` in `printf()`.
* `%.0f` suppresses decimal places.

---

# Type Conversion Rules

For arithmetic operations:

1. `char` and `short` become `int`.
2. `float` becomes `double`.
3. If either operand is `double`, the result is `double`.
4. Else if either operand is `long`, the other becomes `long`.
5. Else if either operand is `unsigned`, the other becomes `unsigned`.

Most floating-point arithmetic is performed in double precision.

---

# Loops

## `for` Loop Structure

```c
for (expr1; expr2; expr3)
```

* `expr1`: Initialization
* `expr2`: Condition
* `expr3`: Update

### Omitted Expressions

* Omit `expr1`: no initialization.
* Omit `expr2`: treated as always true.
* Omit `expr3`: no update step.

## `while`

* Preferred when initialization and updates occur elsewhere.

## `do-while`

```c
do {
    ...
} while(condition);
```

* Executes the body at least once.

---

# Functions

## General Form

```c
return_type name(parameters)
{
    declarations;
    statements;
}
```

### Scope

* Local variables are visible only within their function.
* Different functions may use variables with the same name.

### Passing Arguments

#### Call by Value

* C passes arguments by value.
* A copy of the value is provided to the function.

#### Arrays

* Arrays decay into pointers when passed to functions.
* This allows modification of the original array contents.

### Returning Values

```c
return value;
```

* Returns control and optionally a value to the caller.

### Forward Declarations

```c
int add(int, int);
```

* Tell the compiler that a function exists before its definition appears.

---

# Storage Classes

## `extern`

* Declares a global variable or function defined elsewhere.

```c
extern int count;
```

### Declaration vs Definition

**Declaration**

```c
extern int count;
```

* Describes a variable.
* Does not allocate storage.

**Definition**

```c
int count;
```

* Allocates storage.

## `static`

* External and static variables are initialized to zero by default.

## `register`

* Suggests that a variable be stored in a CPU register for faster access.
* Modern compilers usually ignore this hint.
* You cannot apply `&` to a register variable.

---

# Recursion

* Recursion occurs when a function calls itself.
* Useful for:

  * Trees
  * Recursive data structures
  * Divide-and-conquer algorithms

---

# Stack and Stack Frames

## Stack

* Uses a Last-In, First-Out (LIFO) structure.

## Stack Frame

A stack frame contains:

1. Local variables
2. Function parameters
3. Return address
4. Previous frame pointer

* A new stack frame is created for every function call.
* Destroyed when the function returns.
* In simple terms, a stack frame is the current execution context of a function.

### Stack Overflow

* Excessive recursion can exhaust stack space.
* This results in a stack overflow.

---

# Preprocessor

* The C preprocessor performs source-to-source transformations before compilation.
* Examples:

  * `#include`
  * `#define`
  * Conditional compilation

---

# Unary Operators

Unary operators work on a single operand.

```c
++count
!flag
~bits
sizeof(int)
&variable
*pointer
```

---

# Operator Precedence

* Arithmetic operators have higher precedence than relational operators.
* Relational operators have higher precedence than assignment.

Example:

```c
if ((c = getchar()) != EOF)
```

Parentheses prevent unintended behavior.

---

# Compound Assignment

Examples:

```c
+=
-=
*=
/=
%=
&=
|=
^=
<<=
>>=
```

These combine an operation with assignment.

---

# `break` and `goto`

## `break`

Can exit:

* `switch`
* `for`
* `while`
* `do-while`

## `goto`

* Occasionally useful for escaping deeply nested structures.
* Generally discouraged in modern code.

---

# Endianness

Endianness describes byte ordering in memory.

### Big Endian

* Most significant byte stored first.

### Little Endian

* Least significant byte stored first.

---

# Signed and Unsigned

## Unsigned Types

* Store only non-negative values.
* Use all bits for magnitude.

## Signed Types

* Store both positive and negative values.
* Modern systems typically use two's complement representation.

---

# Miscellaneous

## Conciseness

* Writing or speaking using as few words as necessary.

## Semicolons

### Terminator Languages

* C
* Java
* PHP
* JavaScript

### Python

* Semicolons are optional separators, not statement terminators.

## Obfuscated Code

* Code intentionally written to be difficult to understand.
* Often used in competitions such as the International Obfuscated C Code Contest (IOCCC).

## Programs and Functions

* A program consists of functions working together.
* Functions communicate through:

  * Arguments
  * Return values
