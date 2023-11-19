

## Environments
Implementation of ANSI C :
- Translation environment : Source code is converted in to executable machine instructions 
- Execution environment : Code actually runs.
### Translation

**Translation phase** consists of :
1. Each of the (potentially many) **source files** are individually converted to **object code** via the **compilation process**.
2. Various **object files** are tied together by the __linker__

**Compilation process** consists of :
1. **Preprocessors** : Textual manipulation, like `#define` and `#include`
2. **Parse** : Determine the meanings, send error and warning message. Object code is then generated. 

**Object code** is a preliminary form of the machine instructions that implement the statements of the programs called for by a command-line option.

#### Filename Conventions
- Source code : `.c`
- Header files (`#include`) : `.h` 
- Object file : `.o` or `.obj`

#### Compiling and Linking
- Compile and link : 
	```shell
	cc program.c
	cc main.c sort.c lookup.c
	```
- Compile one source file and link it with existing object files : 
	```shell
	cc main.o lookup.o sort.c
	```
- Compile and produce object files for each source file (for later linking):
	```shell
	cc -c program.c
	cc -c main.c sort.c lookup.c
	```
- Link object files : 
	```shell
	cc main.o sort.o lookup.o
	```

We can add `-o name` to store in a file called name rather than `a.out`

### Execution
Loaded into memory, execution using a runtime _stack_, termination.

## Lexical Rules

### Characters
### Comments
```c
/* ... */
```
- Wrong example : Only the first variable is initialized in the code below :
	```c
	x1 = 0; /***********************
	x2 = 0; ** Initialize the **
	x3 = 0; ** counter variables. **
	x4 = 0; ***********************/
	```

### Free form source code
- There are no rules governing where statements can be written; The only rule is that one or more white space characters (or a comment) must appear between tokens that would be interpreted as a single long token if they were adjacent.
- Every function must be completely contained in a single source file.
- A reasonable organization of a C program is for each source file to contain a group of related functions. This technique has the side benefit of making it possible to implement abstract data types.
### Identifiers
**Identifiers** are the names used for variables, functions, types, and so forth.