# DonutShell 

A simple linux shell, completely written in C.

Created by Dylan Maltos.

## Goals & Objectives

* Implement a unique shell start-up sequence that immediately occurs when program is run.
* Properly handle UNIX external commands such as: `ls`, `emacs`, `cd`, etc.
* Properly handle internal commands such as:
  - exit: Terminate DonutShell.
  - print: Print the current PID to console.
  - help: Print the a help page to console, listing available commands for the shell.
* Support using the ampersand character (&) to seperate commands in user input, results in the given commands executing concurrently.
* Truncate a given user input line back down to 100 characters, if the input line is longer than 100 characters.
* Support arguments for commands.
* If an invalid character is found in an argument or command, print an error message, then ignore the rest of the user input line.
  - Valid characters: `A-Z`, `a-z`, `0-9`, `-`, `.`, `/`, and `_`.

## Build Instructions

How to correctly build and run DonutShell:

<pre>
gcc -o DonutShell DonutShell.c -lm

./DonutShell
</pre>

## Shell Structure

* Start-up sequence:

  - A loading screen stating that DonutShell is initializing.
  - A spinning donut.
  - A screen welcomes the user to DonutShell.
  - Finally, prompts the user for a line of input.
  
* Main loop:

  - Reads a given user input line and checks for:
  
    - Multiple commands seperated by the ampersand character (&).
    - If the input line is over 100 characters.
    - Command arguments.
    - Invalid characters in commands or arguments.
  
  - Executes the given user input line:
    - Commands seperated by ampersand chracter (&) execute concurrently.
    - Truncates user input line down to 100 caracters, if over 100 chracters.
    - Executes command arguments properly (ex. `cd Folder/` will bring you to directory `Folder/`).
    - Invalid characters in given commands or arguments, result in a errorm message, the rest of user input line is ignored.
   
  - Repeats:
    - Until `CTRL-C` signal or internal command `exit` is given.
