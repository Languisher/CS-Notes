

## Empty Statement
## Expression Statement

Turn an **expression** in to a statement : put a semicolon `;` at the end of it.
```c
x = y + 3;
ch = getchar();
```

**Effect** and **side effect** : `printf( "Hello world!\n" ); a++;` The statement "has no effect" only in the sense that the value of the expression is ignored ; However it (1)prints out informations or (2)add the value of `a`. Such work is called **side effect**.

## Statement Blocks
```
{
	declarations
	statements
}
```

## If Statement
```c
if ( expression )
	statement
else
	statement
```

## While Statement
```c
while ( expression )
	statement
```

### Break, Continue
- The `break` statement may be used in a `while` loop to terminate the loop prematurely. The next statement to be executed is the one that would have been performed *had the loop terminated normally*.
- The `continue` statement may be used in a `while` loop to *terminate the current iteration* of the loop prematurely. After a `continue`, the expression is evaluated again.

