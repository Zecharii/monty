# Monty

`monty` is an interpreter of Monty ByteCodes files, which is a scripting language just like Python. The project is done by me (Zechariah Gaiya) alone as part of the **ALX Software Engineering program**.

## The Monty language
This is a language that is intended to be equally suitable for both scripting and conventional programming. It contains specific instructions to manipulate data information (stacks or queues), where each instruction (*called opcode*) is sended per line. The files containing Monty byte codes usually have the `.m` extension.

## Technologies
* The interpreter was written in C language
* All C files are compiled using `gcc 4.8.4`
* All C files are written according to the C89 standard
* All files are written and compiled on Ubuntu 20.04 LTS

## Usage
All files will be compiled on Ubuntu 20.04 LTS using `gcc`:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
The **synopsis** of the interpreter is the following:

```bash
$ ./monty [filename]
```
To run the interpreter:

```bash
$ ./monty file.m
```

## Features
### Opcodes
`monty` executes the following opcodes:

| Opcode | Description |
| -------- | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `queue` | Sets the format of the data to a queue (FIFO) |
| `stack` | Sets the format of the data to a stack (LIFO) |
| `nop` | Doesn't do anything |
| `add` | Adds the top two elements of the stack |
| `sub` | Subtracts the top element of the stack from the second top element of the stack |
| `mul` | Multiplies the second top element of the stack with the top element of the stack |
| `div` | Divides the second top element of the stack by the top element of the stack |
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| `pchar` | Prints the char at the top of the stack |
| `pstr` | Prints the string starting at the top of the stack |
| `rotl` | Rotates the stack to the top |
| `rotr` | Rotates the stack to the bottom |

### Comments
Comments are indicated with `#` and are not executed by the interpreter.

### Return value
When there is no errors, `monty` returns `0`. Otherwise, it returns `1`

## Author
* Zechariah Gaiya: [Twitter](https://twitter.com/GA_Zechariah) - [GitHub](https://github.com/Zecharii)
