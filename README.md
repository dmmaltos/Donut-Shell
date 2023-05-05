# DonutShell 

A simple linux shell, completely written in C.

Created by Dylan Maltos.

## Project Goals
* Implemented a unique shell startup sequence that immediately occurs when program is run.
* Takes UNIX external commands such as ls, emacs, cd, etc.
* Takes internal commands:
  - exit: Terminates DonutShell.
  - print: Prints the current PID to console.
  - help: Prints the DonutShell help desk, provides available commands.
* By using the ampersand character (&) to seperate commands in user input, results incommands will execute concurrently.
* Truncates a given user input line back down to 100 characters, if input is longer than 100 characters.
* Supports multiple argumments for commands.
* If an invalid character is found in an argument or command, shell prints an error message, then proceeds to ignore the rest of the given user input line.
  - Valid Characters: `A-Z`, `a-z`, `0-9`, `-`, `.`, `/`, and `_`.

## Build Instructions
How to correctly build and run DonutShell:
<pre>
gcc -o DonutShell DonutShell.c -lm

./DonutShell
</pre>
