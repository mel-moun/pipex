# pipex 🚀

## Overview 📝

`pipex` is a C project that implements a simple shell-like program to handle processes and pipes. The goal of this project is to learn how to manage processes, file descriptors, and pipes in C. It simulates a basic version of the command-line pipeline using multiple processes and redirections, similar to how commands are chained using `|` in a shell.

This project is part of the 42 coding school curriculum, helping students develop a strong understanding of system programming and process management.

## Features 🌟

- Implements piping between commands, allowing data to flow from one command to another.
- Supports file redirection (input/output redirection).
- Executes multiple commands using `fork()`, `execve()`, and pipes.
- Handles the standard input/output redirection with files.
- Basic error handling and process management.
