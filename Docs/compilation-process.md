Here we will take a deepdive into the Compilation Process step by step.

let's before diving into the steps ask our self some quesions and answer them one by one..

we all know that The compiler job is to transalte the source code into machine code, so how this even work? this is the question, BUT..

## What is source code?

Source code is *the fundamental set of instructions and statements written by programmers using human-readable programmers using programming languages (like, C, python, java, etc..).

this is google definition of what is the source code.. btw you as a programmer should know what the hell is source code, so don't make me tell you what the hell is source code mean!

so if you have file that named file.c or file.py or whatever and contain some lines like

```
#include <something.h>

int main(void) {

    //comment
    statement

    if(condition) {
        //block of code
    }

}
```

this is the source code.

but YOUR computer doesn't understand what the hell these are, he understand more complex shity things like `01010101010000101010111100` and more from the zeroes and ones, and these zeroes and ones called A **Machine Language**,
but the humman wouldn't able to write something like this! it's so F complecated! how the hell could i write a whole program just by keep typing zeroes and ones!

imagine that if you want to write something simple like "Hello World!\n" how it could looks in zeroes and ones?

```
1011100000000100000000000000000000000000101110110000000100000000000000000000000010111001101000001000010000000100000010001011101000001101000000000000000000000000110011011000000001001000011001010110110001101100011011110010000001010111011011110111001001101100011001000010000100001010
```
Bruh! WTH? so how the hell could i even know if it's hello world? google it!

you have zeroes and ones and you have enternet take this line and google it and you will see.

btw enough.

you now see how computer understand things.. so now the mession of the compiler comes, BUT! what even is the compiler?

## The Compiler

**THE COMPILER MESSION IS TO TRANSALTE THE HUMAN READABLE CODE TO MACHINE CODE** That's it.

so it takes this good and understandable lines written upove and transalte it to the computer into it's own language.. like google transalte or any other language translator.. if your mother lang is Arabic and you need to tell someone that doesn't speek arabic, then you write what you need in Arabic in translator and he immediately translate it to you into his language.


i think every thing is clear now. about the problem?

Now How this compiler works? this is why this post exist to spread all things around the compilation process.

## The Compilation Process

Our sweet compiler have **Four** stages to compile the file into machine language..

```
Preprocessor -> Compiler -> Assembler -> Linker
```

### Preprocessor

So let's take our awsome file into it's sompiling journey and see how this process looks..

first step as we already mention is the *Preprocessor* step, we could expalin this phase as the phase that we clean our code file in..

because here in this stage there is **Three** main tasks will be done :

- Remove the comments

in our file prev file that we names as file.we ("we" is an abbreviation for our imaginary "WhatEver" file format)

```
#include <something.h>

int main(void) {

    //comment <- this phase removes this line
..
```

- Replace the macro

A macro (short for "macro instruction") in programming is *a rule or pattern that automatically maps a specific maps or a specific inputs seqenece to a replacement output sequence, typically used to automate repetitive tasks and rdeuce code duplication.

```
#include <stdio.h>

// 1. Object-like macro (Constants)
#define PI 3.14159

// 2. Function-like macro (Code substitution)
#define AREA_OF_CIRCLE(radius) (PI * (radius) * (radius))

int main() {
    double r = 5.0;

    // Here where the preprocessor replaces AREA_OF_CIRCLE(r) with (3.14159 * (r) * (r))
    double area = AREA_OF_CIRCLE(r);

    printf("Radius: %.1f\n", r);
    printf("Area: %.5f\n", area);

    return 0;
}
```
> this code is in C not our imaginary lang (stupid!)

- Expand the header files

Acually expand the header file is somehow longer than it should be because it takes three steps to finish it's mession, so how it even works?

1. **The code**: You write `#include <stdio.h>` at the top of your `C` file.
2. **The search**: The preprocessor lloks for a file named `stdio.h` in your system directories.
3. **The expantion**: It deletes the `#include <stdio.h` line and dumps thousands of lines of code from that file directly into your file.

**SMALL** visual example..

let's assume that you have a header file named `math_helper.h`:
```
// math_helpers.h
int add(int a, int b);
int subtract(int a, int b);
```

And your main source code file looks like this:
```
// main.c
#include "math_helpers.h"

int main() {
    return add(5, 3);
}
```

The **expanded** version of `main.c` sent to the compiler becomes:
```
// main.c (After Preprocessor Expansion)
int add(int a, int b);
int subtract(int a, int b);

int main() {
    return add(5, 3);
}
```

### Some Facts about Expantion

- **Massive Files Sizes**: Standard headers contain thousands of lines. Expanding `<stdio.h>` or `<iostream>` can turn a 10-line file into a 20,000-line file instantly.
- **Hidden from view**: This expanded file is **Temporary**. It exists in memory during compilation, so you do not see it in your text editor.

Btw you can view this expanded file yourself. in GCC or Clang by running `gcc -E file.c` to stop after the expantion phase and ourput the raw text.

Also something needs to be mentioned, that in this phase a `.i` file comes as output to go to compiler.

Also i suggest to you to read more about **[Include Guards]()**.

And this is all about the **Preprocessing** phase.



### The Compiler


