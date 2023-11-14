

## Prerequisites
- [[Pointers]]
- [[Functions]]

## Declaration and Initialization
```c
int vector[5] = { 10, 20, 30, 40, 50 };
```

### Static Initialization
When initializing an array that is local to a function, think carefully whether it should be *reinitialized each time* the block is entered. If no, declare the array `static`.

### Incomplete Initialization
Only trailing initializers can be omitted.
```c
int vector[5] = { 1, 5 };
```

### Automatic Array Sizing
```c
int vector[] = { 1, 2, 3, 4, 5 };
```

The compiler makes the array *just big enough* to hold the initializers that were given.

## One-Dimensional Arrays

### Array Names
```c
int a;
int b[10];
```

- `b[4]`, the fifth specific value in the `b` array is a scalar. 

```ad-note
title: The value of the **array name** is a *pointer constant* that is the address of the first element of the array.
```

```ad-warning
title: arrays $\ne$ pointers
For example, an array has a certain number of elements, while a pointer is a scalar.
```

```c
int a[10], b[10];
int *c;
c = a; // equals to c = &a[0];
b = a; // Wrong. These are two pointers.
a = c; // Wrong. a is constant.
```

### Subscripts vs Pointers
中文：下标引用

```ad-important
title: Subscript $=$ Indirection 
```

```c
array[subscript] = *( array + ( subscript ) )
```

- Subscript checking is a difficult task in C. 

```ad-note
title: Subscripts are never more efficient than pointers, but pointers are somethimes more efficient than subscripts.
```

### Arrays and Pointers
```ad-note
title: Pointers and arrays are not equivalent.

- Declaring an array sets aside space in memory for the indicated number of elements, then creates the array name.
- Declaring a pointer variable reserves space for the pointer itself, but that is all. 
```

```c
int a[5];
int b;
/* *a make sense,
 * *b is not legal, as it is not initialized, now pointing to an indeterminate location */
```

### Array Names as Function Arguments

