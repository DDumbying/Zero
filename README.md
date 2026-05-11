# Zero

A structured roadmap for learning low-level systems programming using the C language through interconnected projects.

This series exists to build a real mental model of how computers and operating systems work internally.

The goal is not to memorize syntax or complete isolated tutorials.
The goal is to understand:

* How programs execute
* How memory works
* How processes are created
* How terminals behave
* How binaries are structured
* How networking works internally
* How the kernel exposes abstractions
* How low-level software is designed

Each project in this series exists because the previous one introduces a limitation, question, or abstraction that leads naturally into the next topic.

By the end of the roadmap, the entire system should start feeling connected instead of fragmented.

# Project Structure

```txt
01-hex-viewer/
02-elf-parser/
03-mini-shell/
04-shell-pipes/
05-text-editor/
06-memory-allocator/
07-chat-server/
08-event-loop/
09-system-monitor/
10-debugger/
11-bytecode-vm/
12-init-system/
```

Each project should contain:

```txt
src/
include/
docs/
README.md
Makefile
```

# Roadmap

# 01 — Hex Viewer

## Problem

Programs usually hide the fact that files are just raw bytes.

This project exists to expose the binary nature of data and build awareness around memory representation.

## Concepts

* Binary data
* Buffers
* File descriptors
* Offsets
* ASCII
* Hexadecimal representation
* Pointer arithmetic

## Project

* [Hex Viewer](./01-hex-viewer)

# 02 — ELF Parser

## Problem

After seeing raw bytes, the next question becomes:

How are executable files actually structured?

This project exists to explore how programs are represented on disk before execution.

## Concepts

* ELF headers
* Sections
* Symbol tables
* Program headers
* Struct layout
* Executable loading

## Project

* [ELF Parser](./02-elf-parser)

# 03 — Mini Shell

## Problem

If executables are just files, how does the operating system run them?

This project exists to understand process creation and execution.

## Concepts

* Processes
* fork/exec model
* Process lifecycle
* Waiting for children
* Environment variables

## Project

* [Mini Shell](./03-mini-shell)

# 04 — Pipes & Redirection

## Problem

Processes alone are not enough.
Programs must communicate with each other.

This project exists to understand UNIX I/O abstractions.

## Concepts

* File descriptors
* Pipes
* Redirection
* stdin/stdout/stderr
* UNIX pipelines

## Project

* [Shell Pipes & Redirection](./04-shell-pipes)

# 05 — Text Editor

## Problem

Interactive terminal applications appear magical until you understand terminal behavior.

This project exists to expose how terminals actually work.

## Concepts

* Raw mode
* Escape sequences
* Cursor movement
* Screen rendering
* Input handling

## Project

* [Text Editor](./05-text-editor)

# 06 — Memory Allocator

## Problem

Applications constantly request and release memory, but where does that memory come from?

This project exists to understand heap management.

## Concepts

* Heap internals
* Free lists
* Fragmentation
* Alignment
* Virtual memory

## Project

* [Memory Allocator](./06-memory-allocator)

# 07 — TCP Chat Server

## Problem

Programs should not only communicate locally.
They should communicate across machines.

This project exists to understand low-level networking.

## Concepts

* TCP/IP
* Sockets
* Client/server architecture
* Blocking I/O
* Connections

## Project

* [TCP Chat Server](./07-chat-server)

# 08 — Event Loop

## Problem

Traditional blocking architectures do not scale efficiently.

This project exists to understand asynchronous and event-driven systems.

## Concepts

* Non-blocking I/O
* Event loops
* epoll
* Readiness notification
* Async architecture

## Project

* [Event Loop Server](./08-event-loop)

# 09 — System Monitor

## Problem

Operating systems expose runtime information internally.

This project exists to inspect and understand live system state.

## Concepts

* procfs
* Process inspection
* CPU statistics
* Memory statistics
* Kernel interfaces

## Project

* [System Monitor](./09-system-monitor)

# 10 — Debugger

## Problem

Programs are usually treated as black boxes during execution.

This project exists to understand runtime control and execution tracing.

## Concepts

* ptrace
* Registers
* Breakpoints
* Instruction stepping
* Process tracing

## Project

* [Debugger](./10-debugger)

# 11 — Bytecode Virtual Machine

## Problem

Real CPUs execute instructions.
Can software simulate that execution model?

This project exists to understand virtual execution systems.

## Concepts

* Bytecode
* Stack machines
* Interpreters
* Instruction dispatch
* Virtual execution

## Project

* [Bytecode VM](./11-bytecode-vm)

# 12 — Init System

## Problem

Systems need a process responsible for managing all other services.

This project exists to understand service supervision and system lifecycle management.

## Concepts

* Daemons
* Process supervision
* Signal handling
* Sessions
* System startup

## Project

* [Init System](./12-init-system)

# Final Goal

By the end of this series, the following ideas should feel connected instead of isolated:

* Memory
* Processes
* Binaries
* Execution
* File descriptors
* Networking
* Terminals
* Virtual memory
* Kernel interfaces
* Runtime systems

The purpose of this roadmap is to transform systems programming from a collection of APIs into a connected mental model of how computers actually operate.

After finishing this roadmap, you should be capable of:

* Reading UNIX source code
* Building low-level tools
* Understanding operating systems internals
* Building runtime systems
* Understanding performance bottlenecks
* Understanding memory behavior
* Building scalable networked applications
* Navigating kernel interfaces confidently
