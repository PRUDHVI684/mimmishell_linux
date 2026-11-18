# Mini Shell Implementation in C (Linux)

## Project Overview

Mini Shell is a simple command-line shell developed using C programming on Linux. It provides an interactive environment to execute Linux commands and demonstrates fundamental Linux system programming concepts such as process creation, command execution, file descriptors, and I/O redirection.

## Features Implemented

- Interactive command-line interface.
- Command parsing using `strtok()`.
- Process creation using `fork()`.
- Execution of Linux commands using `execvp()`.
- Parent-child process synchronization using `waitpid()`.
- Built-in commands:
  - `cd` – Change the current working directory.
  - `pwd` – Display the current working directory.
  - `help` – Display available built-in commands.
  - `exit` – Terminate the shell.
- Input redirection (`<`) using `open()` and `dup2()`.

## Technologies Used

- Programming Language: C
- Operating System: Linux
- Compiler: GCC
- System Calls: `fork()`, `execvp()`, `waitpid()`, `chdir()`, `getcwd()`, `open()`, `dup2()`
- Header Files: `stdio.h`, `string.h`, `unistd.h`, `sys/wait.h`, `fcntl.h`

## Project Structure

```text
Mini-Shell/
│
├── mimishell_main.c
└── README.md
```

## Compilation

Compile the source code using GCC:

```bash
gcc shell_demo.c -o minishell
```

## Execution

Run the shell:

```bash
./minishell
```

## Usage Examples

### 1. Execute Linux Commands

```bash
minishell>> ls
minishell>> date
minishell>> ls -l
```

### 2. Built-in Commands

```bash
minishell>> pwd
minishell>> cd Documents
minishell>> help
minishell>> exit
```

### 3. Input Redirection

Create a sample file:

```bash
printf "Hello\nWorld\nLinux\n" > input.txt
```

Execute a command using input redirection:

```bash
minishell>> wc -l < input.txt
```

Expected output:

```text
3
```

## Concepts Learned

- Linux process management.
- Parent and child process execution.
- System calls and their usage.
- File descriptor management.
- Command-line argument parsing.
- Standard input and output handling.
- File I/O and input redirection.

## Future Enhancements

- Output redirection (`>`).
- Append redirection (`>>`).
- Pipe implementation (`|`).
- Multiple pipe handling.
- Background process execution (`&`).
- Signal handling using `SIGINT` and `SIGCHLD`.
- Improved command parsing and error handling.

## Project Status

**In Progress** – Core shell functionality and basic input redirection have been implemented and tested. Additional shell features are planned.
