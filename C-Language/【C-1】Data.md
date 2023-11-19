## Basic Data Types

There are only four basic data types in C – **integers**, **floating-point values**, **pointers**, and **aggregate types** such as arrays and structures.

### Integers
- The integer family contains **characters, short integers, integers, and long integers**. All have both **signed** and **unsigned** versions.
- Long integers are as least as large as integers, which themselves are at least as large as short integers.
#### Signed and Unsigned Binary Numbers
Three representation schemes for signed integers called :
- Sign-Magnitude representation
- **1’s Complement representation**
- **2’s Complement representation**
![](assets/截屏2023-09-25%2008.26.07.png)

- Sign-Magnitude representation : 用最高位表示符号位，其他位存放该数的二进制的绝对值 
	- Examples : `-2 -> [1]010`, `4 -> [0]100`
	- Problems :
		- `0 = [1]000 = [0]000` two representations
		- `1+2=3 -> [0]001 + [0]010 = [0]011` correct, however `1+(-1)=0 -> [0]001 + [1]001 = [1]010 (-2)` incorrect （相反数相加不为0）

- 1’s Complement representation : 为了解决相反数相加不为 0 问题，各位取反
	- Examples : `2 -> 0010` so `-2 -> 1101`
	- Problems :
		- `0 = 0000 = 1111` two representations
		- `1+(-1)=0 -> 0001 + 1110 = 1111` correct, however `-1+(-3)=-4 -> 1110+1100 = 11010 = (-00101) (-5)` incorrect（负数相加不正确）

- 2's Complement representation : *正数的补码等于它的原码；负数的补码等于反码+1*
	- `(-1)+2=1 -> 1111+0010=10001` （保留后4位，得到 `1`）
#### `char`
Although the intention behind char variables is for them to hold characters, characters are actually tiny integer values.
#### Integer literals
- The term **literal** is an abbreviation for literal constant—an entity that specifies its own value, and whose value cannot be changed (variables declared to be `const`)
	- It can be given in octal starting with `0` : `0173`
	- It can be given in hexadecimal by starting with `0x` : `0xFFFF`
- **character literals** always have type `int`; you cannot use the unsigned or long suffixes on them, such as `'M'`
#### Enumerated Type
An enumerated type is one whose values are symbolic constants rather than literal. These are declared in this fashion:
```c
enum Jar_Type { CUP, PINT, QUART,
			   HALF_GALLON, GALLON };

enum Jar_Type milk_jug, gas_can, medecine_bottle;
```

### Float
#### Floating point literals
- Floating point literals are always written in decimal and must contain either a decimal point, an exponent, or both.
	- Example : `6.023e23`, `25.`
- Floating point literals are `double` values unless they are followed by a suffix: `L` or `l` specify long double, and `F` or `f` specify float.

### Pointers
- Each **memory location** is identified and referenced with an **address**, just as the houses on a street can be located by their address. 
- **Pointer** is just another name for an address
- At **pointer variable** is a variable whose *value is the address of some other memory location*.

#### Pointer Constants

#### String literals

## References
1. [二进制的原码、反码、补码](https://zhuanlan.zhihu.com/p/99082236)