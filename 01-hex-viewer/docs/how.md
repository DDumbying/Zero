in this file we should explain how even the hex viewer understand the file..

and this will be spread here.

## How Hex Viewer understand the file?

he doesn't actually **understand** the file, he really just show the **bytes** as it is, So instead of seing "Hello" you will see something like

```
48 65 6c 6f
```

**So why is this matter?**

This actually because most of the programs hide the real representation, while the Hex Viewer reveals the raw truth of the data.

So the most important question here is.. **How to know the meaning of these specific bytes?**

anyway this actually depend on the file format specification... So **what is even the File Format?**

**File Format** is a *set of rules that define how bytes should be interpreted*.

For example, let's assume that we have a **PNG**  file, any png file start with :

```
89 50 4E 47
```

and this is not coincidence, people who designs PNG said that any PNG file should start with these signatures.

then:

- a specific bytes means width
- another bytes means height
- another means compression

and so on

so the **Format** is *Template/layout/specification* for the bytes.

**BUT** is the `.png` extension is the important thing?

the answer is **NO**, and this is a hugge point.

the extension is just a convention, not the truth. The truth exists insdie the bytes itself.. because of that there is :

- magic numbers
- signatures
- headers

for example, if your file is actually a `.png` and you did `mv image.png hello.txt`, this actually didn't change anything the file is still a PNG file, bacause the files itself doesn't changed.

**So how the system knows this type of file?**

we said it before.. usually via :

- magic numbers
- signatures
- headers

Now let's ask the deepest qustion.

## How WE understand any format?

this happenes through the specification, almost every real format has:

- documentaion
- binary layout
- structure definition

**Imaginary Example**

```
Byte 0-3   -> magic number
Byte 4-7   -> width
Byte 8-11  -> height
Byte 12-.. -> image data
```

this should be *memory/file layout*, so reading "format" means *Linking specific offsets to specific meanings*.

## How to learn different templates?

Not by memorizing them, but by understanding how are binary layout designed.

Almost every format has (as we say before but with more details):

- header
- metadata
- playload/data
- offsets
- sizes
- encoding rules

So if we give a real examples here.

Any **[ELF](./docs/elf.md)** file has :

- Header
- Program Headers
- Sections
- Symbols
- Machine Code

Any **PNG** file has:

- Signature
- Chunks
- metadata
- compressed image data

Any **WAV** file has:

- RIFF header
- Audio format info
- Raw audio samples

Thats it.







