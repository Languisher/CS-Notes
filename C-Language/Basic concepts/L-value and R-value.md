Update：2023 年 11 月 19 日 上海交通大学

⚠️重要：始终理解一个变量由**地址**和**值**同时组成，且唯一对应；作为左值我们关心其地址，作为右值我们关心其值，赋值我们关心*新值向目标地址的值的传递过程*。
## Definition

```ad-note
title: Definition of L-value and R-value
An **L-value** is something that can appear on the left side of an equal sign, and an **R-value** is something that can appear on the right side of an equal sign. 
```

```ad-important
title: Difference between L-value and R-value
Major difference between the two:
1. An **L-value** identifies a *specific location*,
	- where a result can be stored
	- that we can refer to later in the location

2. An **R-value** designates a *value*.
```

### Examples
```c
b + 25 = a; // Wrong, we can't predict where the result will be.

int a[30];
a[ b + 10 ] = 0; // True, we do know where *(a + b + 10) would be !

int a, *pi;
pi = &a; // True, the expression specifies the location to be modified.
*pi = 20;
```

The value in the pointer `pi` is the *address of a specific location in memory,* and the `*` operator directs the machine to that location. 
- When used as an **L-value**, this expression specifies the *location* to be modified.
- When used as an **R-value**, it gets the *value* currently stored at that location.

## The process of `=`

So what does `exp1 = exp2` means ?
```ad-important
title: `exp1 = exp2`
Here, we take the **address of `exp1`(L-value)** and the **value of `exp2`(R-value)**.
We pass the **value** `exp2` into the *value* where **position** `exp1` possess.
```

### Example
`*pi = 20` 当 `*pi` 作为左值时，这个表达式指定了需要修改的位置（同理作为右值时，他就提取存储于当前位置的值），然后将 20 这个值传入这个需要修改的位置（即，改变了这个位置所对应的值）。
