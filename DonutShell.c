//////////////////////////////////////////////////////
//                  Dylan Maltos                    //
//             CS321 Operating Systems              //
//                 April 4th, 2023                  //
// A simple linux-based shell project, DonutShell. //
//////////////////////////////////////////////////////


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <wait.h>
#define MAX_CMD_LENGTH 100 // Max length for a user command is 100.
#define MAX_INPUT_LENGTH 100 // Max length for a command line inpuit is 100.
#define clear() printf("\033[H\033[J") // Clears the shell through escape sequences.

// Controls the shell's boot initialization.
void init_shell() 
{
    // Prints please wait initializing screen.
    printf("\n\n\n\n#####################""##################");
    printf("\n\n\n\tINITALIZING DONUTSHELL");
    printf("\n\n\t\t\b\b\b\bPLEASE WAIT...");
    printf("\n\n\n#####################""##################");
    printf("\n");
    sleep(5);
    clear();

    // Prints spinning donut after please wait initializing screen.
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for(int counter = 1; counter <= 300; counter++) 
    {
        memset(b,32,1760);
        memset(z,0,7040);
        for(j=0; j < 6.28; j += 0.07) 
        {
            for(i=0; i < 6.28; i += 0.02) 
            {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) 
                {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
    }
    clear();

    // Prints the welcome prompt after spinnping donut screen.
    printf("\n\n\n\n#####################""##################");
    printf("\n\n\n\tWelcome to DonutShell");
    printf("\n\n\t\b\b\b\bA linux shell by Dylan Maltos");
    printf("\n\n\n####################""###################");
    char *username = getenv("USERNAME");
    printf("\n\n\nLogged in as: %s", username);
    printf("\n");
    sleep(5);
    clear();
    return;
}

// Executes when user inputs help command.
void cmdHelp()
{
    printf("\n#######################################################################");
    printf("\n\t\t---WELCOME TO THE DONUTSHELL HELPDESK---");
    printf("\n#######################################################################");
    printf("\nSupported Commands:\n");
    printf("\n\t- help: Directs you here, the DonutShell HelpDesk.");
    printf("\n\t\t Usage: help\n");
    printf("\n\t- exit: Terminates DonutShell.");
    printf("\n\t\t Usage: exit\n");
    printf("\n\t- print: Prints the current PID.");
    printf("\n\t\t Usage: print\n");
    printf("\n\t- cd: Lets you enter a directory/path.");
    printf("\n\t\t Usage: cd <path>\n");
    printf("\n\t- ls: Lists all files in a directory.");
    printf("\n\t\t Usage: ls; ls <directory>\n");
    printf("\n\t- emacs: Access to a powerful text editor for programming.");
    printf("\n\t\t Usage: emacs <filename>\n");
    printf("\nDonutShell is compatible with all other general external UNIX commands.\n");
    printf("#######################################################################\n\n");
  
    return;
}

// Handles internal commands: exit, help, and print for the shell.
void cmdHandler(char **commands)
{
    char *args[1];
    if (strcmp(args[1], "help") == 0) 
    {
        cmdHelp();  // Calls cmdHelp() function which prints out the DonutShell help page.
    } 
}

// The main function for DonutShell.
int main()
{
    char inputString[MAX_CMD_LENGTH + 1];
    char *commands[MAX_CMD_LENGTH];
    int Running = 1;
    int numCMD = 0;
    clear();
    init_shell(); // DonutShell starts its start up process.

    while (Running == 1) 
    {
        printf("~DonutShell$ > ");
        fgets(inputString, MAX_INPUT_LENGTH + 1, stdin);

        numCMD++;

        if (strlen(inputString) >= 100)
        {
            inputString[100] = '\0';
            printf("ERROR: Input long, truncating to 100 characters.\n");
        }

        inputString[strcspn(inputString, "\n")] = 0;

        if (strcmp(inputString, "help") == 0)   // Code here will execute if user input is "exit".
        {
            cmdHelp();
        }

        if (strcmp(inputString, "exit") == 0)   // Code here will execute if user input is "exit".
        {
            printf("Exiting DonutShell...\n");  // Prints a statement announcing that DonutShell is ending.
            sleep(1);   // Waits before printing goodbye message.
            printf("Adios!\n");   // Prints a goodbye message "Adios!" to the DonutShell user.
            exit(0);    // Terminates DonutShell.            
        }

        if (strcmp(inputString, "print") == 0)
        {
            printf("Printing PID for the current process...\n"); 
            sleep(1);
            printf("PID: %d\n", getpid());  // Prints out current processes' PID.
        }
    
        if (strcmp(inputString, "print") == 0)
        {
            printf("Printing PID for the current process...\n"); 
            sleep(1);
            printf("PID: %d\n", getpid());  // Prints out current processes' PID.
        }

        char* token = strtok(inputString, "&"); // Parses user input into individual commands.
        while (token != NULL) 
        {
            commands[numCMD++] = token;
            token = strtok(NULL, "&");
        }

        for (int i = 0; i < numCMD; i++) // Executes commands
        {
            pid_t pid = fork();

            if (pid == 0) // child process
            { 
                system(commands[i]);
                exit(0);
            } 
            else if (pid > 0) // parent process
            {
                // do nothing
            }
            else
            {
                perror("fork"); // Forking error
            }
        }

        for (int i = 0; i < numCMD; i++)
        {
            wait(NULL);
        }
        memset(commands, 0, sizeof(commands));
        numCMD = 0;
    }

    return 0;
}