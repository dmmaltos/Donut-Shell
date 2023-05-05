# DonutShell 

A simple linux shell, completely written in C.

Created by Dylan Maltos.

## Goals & Objectives

* Implement a unique shell startup sequence that immediately occurs when program is run.
* Handles UNIX external commands such as ls, emacs, cd, etc.
* Handles internal commands:
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

## Structure

* Startup sequence:

  - A loading screen stating that DonutShell is initializing.
  - A spinning donut.
  - A screen welcoming the user to DonutShell.
  - Finally, prompting the user for a line of input.
  
* Main loop:

  - Reads given user input lines and checks for:
  
    - Multiple commands seperated by the ampersand character (&).
    - If the input line is over 100 characters.
    - Command arguments.
    - Invalid characters in commands or arguments.
  
  - Executes given user input line:
    - Commands seperated by ampersand chracter (&) execute concurrently.
    - Truncates user input line down to 100 caracters, if over 100 chracters.
    - Executes command arguments properly (ex. 'cd Folder/' will bring you to directory 'Folder/').
    - Invalid characters in given commands or arguments, result in a errorm message, the rest of user input line is ignored.
   
  - Repeats:
    - Until 'CTRL-C' signal or internal command 'exit' is given.
