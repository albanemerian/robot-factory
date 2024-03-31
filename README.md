# robot-factory
This project is the first part of the corewar project

# Corewar Tournament

The Corewar tournament is a game in which several programs called Champions will fight to stay the last one alive. Corewar is actually a computer simulation in which processors will share memory to run on.

The project is based on a virtual machine in which the champions will fight for memory by all possible means in order to win, the last champion being able to signal that he is alive wins the game. In other words, the last champion to execute the live instruction is declared the winner.

To start, search for "corewars" and "redcode" on the Internet.

## The Different Parts

The project is divided into two separate parts, with only one to develop:

### Champions (given, you don’t have to write any)

The champions are files written in an assembly language specific to our virtual machine. The file is filled with instructions that the champion must follow; it’s his line of conduct. It is in this file that the champion knows when he must attack, defend himself, or announce that he is still alive. Examples of champions are given in the attachments.

### The Assembler (to develop)

The purpose of this program, like a program that your computer would try to run, is to transcribe the champions (the .s files) into a language that the Corewar tournament program can understand. It will, therefore, be necessary to understand the assembly language in order to translate it byte by byte.

**op.c** and **op.h**

To get to the end of the Corewar and for each of you to develop champions with similar instructions and architecture, two files are made available to you: op.c and op.h. You will have to integrate them into your rendering directory. All values written in UPPERCASE in this subject are variables obtainable in op.c or op.h. The coding style will be checked on all the files that you deliver, including the currently non-compliant op.c and op.h.

## Champions
You can find champions exampe to test your code in the champions folder.<br>
Here’s what a champion (an .s file) might look like:

```assembly
              .name "Jon Snow"
              .comment "Winter is coming"
              sti r1, %:crow, %1
crow:         live %234
              ld %0, r3
              zjmp %:crow

```

| Category                         | Percentage | Tests | Crash |
|----------------------------------|------------|-------|-------|
| Algorithm app                    | 100%       | 5/5   | x     |
| Data structure                   | 80%        | 4/5   | x     |
| Parsing                          | 94.4%      | 17/18 | x     |
| Robustness                       | 97.1%      | 34/35 | x     |
| End score                        | 95.2%      | 60/63 | x     |
