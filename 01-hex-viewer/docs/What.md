This is the first project from a punch of projects made by me for me, to understand the deep topics of the Low Level Programming, and document it for others (idk, i hope this will go well)

btw the first project here is a **Hex Viewer**, and this is where you go deep down to understand that there is another layer of abstracting things.. and one of these things are the file content. So..

## What is the Hex Viewer

A hex viewer is **A software too used to display the raw contents of a computer file or data in [hexadecimal format](./docs/hexadecimal.md)**.

So u hope you already know what is even the hexadecimal format.. and if you don't know i decide to read the link that i embeded already to the word *hexadecimal*, and then come back to continue the reading session.

So we already know that it's actually a peice of software.. so it could be just show the raw of data or even makes you could edit these data.. and in both this is the idea of the project that we will do.

BUT our one will just view the data.. nothing else (till now).

The purpose of this project is to understand these things:

- File descriptors
- buffers
- read()
- raw bytes
- memory representation

So we will now start to define each one of these mentioned terms.

## File Descriptor (FD)

A File Descriptor (FD) is a small integer used by a process to reference an opened resource managed by the operating system kernel.

The resource can be:

* a file
* a terminal
* a pipe
* a socket
* a device
* or any stream-based I/O object

A file descriptor does not contain the resource itself.
Instead, it acts as an identifier/index inside the process's file descriptor table, which is maintained by the kernel.

When a process performs operations such as:

* read()
* write()
* close()

the file descriptor tells the kernel which opened resource the operation should target.

Example:

```c
int fd = open("notes.txt", O_RDONLY);
```

If `open()` succeeds, the kernel may return:

```c
fd = 3;
```

This means:

```txt
FD 3 -> notes.txt
```

inside the process's file descriptor table.

Then:

```c
read(3, buffer, 16);
```

means:

```txt
"Read 16 bytes from the resource associated with file descriptor 3."
```

In UNIX-like systems, file descriptors are a core abstraction because almost all I/O is represented uniformly as streams of bytes accessed through file descriptors.

so what about mentioned BUFFER?

## Buffer

A buffer is a region of memory used to temporarily store data while it is being transferred between different parts of a system.

In systems programming, buffers are commonly used during input/output operations such as:

* reading from files
* writing to files
* network communication
* terminal input/output

A buffer exists because data usually moves between:

* kernel space
* process memory
* hardware devices
* storage devices

and these transfers need a temporary memory area to hold the data.

Example:

```c
unsigned char buffer[16];
```

This creates a memory region capable of storing 16 bytes.

When calling:

```c
read(fd, buffer, 16);
```

the process requests:

```txt
"Read up to 16 bytes from the resource associated with fd
and copy them into this memory region."
```

After the call succeeds, the buffer contains raw bytes copied by the kernel.

Example:

```txt
buffer:
48 65 6c 6c 6f 0a
```

which represents:

```txt
Hello\n
```

in ASCII encoding.

Buffers are important because they:

* reduce direct hardware interaction
* allow chunk-based data processing
* improve I/O efficiency
* provide temporary storage during data transfer

In low-level systems programming, a buffer is usually just raw memory.
It has no meaning until the programmer interprets the bytes stored inside it.




