# Makefile

Last update: **22 September, 2023**, *Shanghai*

**Brandon Lin**

This tutorial is for Linux or MacOS.

## Introduction

Makefiles are used to help decide *which parts of a large program need to be recompiled*. In the vast majority of cases, C or C++ files are compiled. Other languages typically have their own tools that serve a similar purpose as Make.

## Prerequistes

- Terminal
- "Make" installed

## Getting started

### Running the examples

- Create a file named "Makefile"
- In that directory run the command `make`

### Syntax of Makefile

A Makefile consists of a set of *rules*. A rule generally looks like this:

```makefile
targets: prerequisites
	command
	command
	command
```

- The *targets* are file names, separated by spaces. Typically, there is only one per rule.
- The *commands* are a series of steps typically used to make the target(s). These *need to start with a tab character*, not spaces.
- The *prerequisites* are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called *dependencies*

#### Example

```makefile
hello:
	echo "Hello, World"
	echo "This line will print if the file hello does not exist."
```

- We have one *target* called `hello`
- This target has two *commands*
- This target has no *prerequisites*

### Target

#### All target

Making multiple targets and you want all of them to run? Make an `all` target. Since this is the first rule listed, it will run by default if `make` is called without specifying a target.

```makefile
all: one two three

one:
	touch one
two:
	touch two
three:
	touch three

clean:
	rm -f one two three
```

#### Multiple targets

When there are multiple targets for a rule, the commands will be run for each target. 

- `$@` automatic variable that contains the target name

    ```makefile
    all: f1.o f2.o
    
    f1.o f2.o:
    	echo $@
    # Equivalent to:
    # f1.o:
    #	 echo f1.o
    # f2.o:
    #	 echo f2.o
    ```

### Make

#### Basic command

```shell
make
make hello
```

#### Essence of make

```c
// blah.c
int main() { return 0; }
```

```makefile
blah:
	cc blah.c -o blah
```

Try simply running `make`. 

- Since there's no target supplied as an argument to the `make` command, the first target is run. In this case, there's only one target (`blah`). The first time you run this, `blah` will be created. 
- The second time, you'll see `make: 'blah' is up to date`. That's because the `blah` file already exists. 

But there's a problem: if we modify `blah.c`and then run `make`, nothing gets recompiled.

```makefile
blah: blah.c
	cc blah.c -o blah
```

When we run `make` again, the following set of steps happens:

- The first target is selected, because the first target is the default target
- This has a prerequisite of `blah.c`
- Make decides if it should run the `blah` target. It will only run if `blah` doesn't exist, or `blah.c` is *newer than* `blah` - This is the **essence of Make**.

#### Example

```makefile
blah: blah.o
	cc blah.o -o blah # Runs third

blah.o: blah.c
	cc -c blah.c -o blah.o # Runs second

# Typically blah.c would already exist, but I want to limit any additional required files
blah.c:
	echo "int main() { return 0; }" > blah.c # Runs first
```

- Make selects the target `blah`, because the first target is the default target
- `blah` requires `blah.o`, so make searches for the `blah.o` target
- `blah.o` requires `blah.c`, so make searches for the `blah.c` target
- `blah.c` has no dependencies, so the `echo` command is run
- The `cc -c` command is then run, because all of the `blah.o` dependencies are finished
- The top `cc` command is run, because all the `blah` dependencies are finished
- That's it: `blah` is a compiled c program

### Make clean

`Clean` is often used as a target that removes the output of other targets, but it is not a special word in Make. You can run `make` and `make clean` on this to create and delete `some_file`.

```makefile
some_file: 
	touch some_file

clean:
	rm -f some_file
```

`clean` is doing two new things here:

- It's a target that is not first (the default), and not a prerequisite. That means it'll never run unless you explicitly call `make clean`
- It's not intended to be a filename. If you happen to have a file named `clean`, this target won't run, which is not what we want.

### Variables

Variables can only be strings. You'll typically want to use `:=`, but `=` also works. 

```makefile
files := file1 file2
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file

file1:
	touch file1
file2:
	touch file2

clean:
	rm -f file1 file2 some_file
```

- Single or double quotes have no meaning to Make. Don't ever use them, such as `files := 'one two'` instead use `files := one two`
- Single or double quotes are useful to shell/bash, such as `printf '${files}'`
- Reference variable using either `${}` or `$()`

## Automatic variables and Wildcards

### `*` Wildcard

`*` searches your filesystem for matching filenames. I suggest that you always wrap it in the `wildcard` function.

```makefile
# Print out file information about every .c file
print: $(wildcard *.c)
	ls -la  $?
```

Don't use directly `*.c`, always `$(wildcard *.c)`

### `%` Wildcard

- When used in "matching" mode, it matches one or more characters in a string. This match is called the stem.
- When used in "replacing" mode, it takes the stem that was matched and replaces that in a string.

## References

- [Learn Makefiles With the tastiest examples](https://makefiletutorial.com)
