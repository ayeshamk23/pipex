# 🔗 pipex

> A Unix pipe emulator using `fork`, `execve`, and `pipe`.

## 📌 Description

**pipex** is a 42 School project that recreates shell-like piping between commands. It simulates the behavior of:

```bash
< file1 cmd1 | cmd2 > file2
```

The program replicates this using system-level calls like `fork`, `execve`, `pipe`, and file I/O redirection. It helps build a deep understanding of Unix internals, process management, and inter-process communication.

## ⚙️ Features

- Executes two commands connected via a pipe
- Supports input/output file redirection
- Uses only low-level system calls (no `popen` or `system()`)
- Handles error reporting and command path resolution

## 🚀 Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

### 💡 Example

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

Which behaves like:

```bash
< input.txt grep hello | wc -l > output.txt
```

## 🔧 Requirements

- Only allowed to use:  
  `open`, `close`, `read`, `write`, `malloc`, `free`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`, `perror`, `strerror`
- No `system()` or `popen()` calls

## 📘 Concepts Learned

- 🧵 **Inter-Process Communication (IPC)** using pipes
- 🧬 **Process management**: creating child processes with `fork()`
- 🚪 **File descriptor redirection** using `dup2()`
- 🧠 **Command execution** with `execve()` and path resolution
- 🗂️ **File I/O operations** (`open`, `read`, `write`, `close`)
- 🔄 **Error handling** and custom message reporting
- 📂 **Environment parsing** and working with `PATH`
- ♻️ **Memory management** and resource cleanup
- ⚙️ **Debugging complex flows** involving multiple processes

