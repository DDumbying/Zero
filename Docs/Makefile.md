## What is Makefile?

A **Makefile** is *a configuration file used by the make build automation tool to manage and streamline the process of compiling or executing tasks in a project*.

so it's a Automation tool to automate builds..

Let's assume that we have a program that calculate the distance between two values..

in normal situation you will find that you have in your file a (hash "#") include to the `math.h` lib.

then when you decide to comple your program using gcc or clang or whatever

```c
clang file.c -o file
```

this ^ could cause an error message like undefined reference to `pow` or `sqrt` or whatever you use in your program.

so you need to specify another tags like `-l m`, so it will be like that

```c
clang gile.c -o file -l m
```

and this will compile correctly..

**So why is this happening?**

this actually happened because the math header doesn't have the code that makes the funtion work actually.. so the compiler knows that this specific Funtion exists but doesn't actually have the code itself, so you need to link it with math lib to have the actuall code.

So also before diving into how to use the Makefiles, let's take a step to know how even the compiler handles the `.c` files?

let's go back to our file.c that calculate the distance between two values..

this file.c file will be compiled by *clang* for example..

so the first thing **Before** the file goes to our compiler, we have the **Preprocessor** this thing handle two main things:

- handling the *#include*, and *defines*
- strips our comments

these are two main things, but there is more than that you could figure it out yourself.

Then our compiler comes to the land.

The **Compiler** actually job is to translate `C` to *assembly*, then our file goes from `.c` file to `.S` file.

Then this `.S` file handled by the *assembler*. And the job of assembler is to translate assembly to something called *object* file with the extention `.o.

Then the **Linker** takes the hand and it's actually *brings together object files to produce **executable**.

in each one of these steps, you could acatully specify a specific step to stop in.

for example if you want your compiler to stop after Preprocessing you could specify the the `-E` flag.

and for the compiler you specify `-S`, and for assembler you specify the `-C`.

So why even need to know that we could specify a specific step?

this actually depend on your situation..like imagine you have a huge project, this project has like 1 million lines of code, which is not correct to have all these lines in one file and when you change something in this file you need then to recompile the whole file again, and this actually take a huge amount of time.

so in the normal situation this whole project would be splitted into separate files, each file has it's own lines of code that represent a kind of functionality, so you just compile the files one time (we will talk about this in details) and when you want to change something in a specific file you could do that normally then you comple this file and link it with other useing flags..

> or not,my english isn't that good and i don't have  the ability to draw the process the way i see it, so F yourself.

Let's continue (to the things that i could JUST write)

So we already talk about the steps to make an executable file and talk about that you could specify a specifc step and stop in it..

so we will assume that we have a a `file.c` and `sfile.c` these two file depend on each other, so we will compile each one by the option `-C` to make them stops at the object file step, so it's not really an executable file yet.. after that we will take these two files and compile them together by :

```
clang file.o sfile.o -o outfile
```

These `.o` extentions comes from the prev step that we compile these file with, using the `-C` option, like this :

```
clang -C file.c // this outs the file.o

clang -C sfile.c // this outs sfile.o
```

so we need to automate this process..

here the **Makefile** comes.

## Makefiles (really)

The structure of Makefile is like this :

```
# _*_ MakeFile _*_ // this is a comment

target: dependencies
    action
```
This is the structure of the Makefile command..

let's now make it with our example

```
file: file.o sfile.o
    clang file.o sfile.o - o file -l m // if there is a math lib linking

file.o: file.c
    clang -c file.c

sfile.o: sfile.c
    clang -c sfile.c
```

ok so the make files actually isn't just a tool to automate, it's also a smart files that really ease everything that depends on the compiling process.. so it searches on each file, each line each change and based on that it makes the right dissesion.

btw this file based on this [Youtube video](https://www.youtube.com/watch?v=GExnnTaBELk).

