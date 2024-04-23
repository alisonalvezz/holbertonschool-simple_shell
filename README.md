# Simple shell: Shellula 🦠
<img src="https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/235/shell.jpeg" alt="the gates of shell" width="500"/>
^“The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier

### In this project we are expected to make a simple shell.

## What is a "Shell"?
A shell is a **command line** interpreter that allows users to interact with the operating system by typing commands. When a user enters a command, the shell interprets it, searches through the PATH variable to find the corresponding executable file in the system's directories, and executes the command by creating a new process.

## Why making a shell?
- **Task Automation:** A shell allows users to automate common tasks through scripts or command files. This can save time and reduce errors by executing a sequence of commands instead of performing each task manually.
- **Learning and Education:** Creating a shell is an excellent exercise for learning about operating systems, low-level programming, process handling, file handling, and other fundamental concepts.
- **Customization and Extensibility:** When creating a shell, you have full control over its functionality and appearance (like us with the name of the shell). You can customize it according to your needs and add new features or extensions to enhance its functionality.
- **Integration with Existing Systems:** A shell can be integrated with other existing systems or tools, making it easier to automate tasks and facilitate interoperability between different system components.

## Learning objectives:
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## About our shell:

#### Our shell looks like this in interactive mode:
```
$ ./hsh
(shellula$) /bin/ls
hsh main.c shell.c
(shellula$) ls
hsh main.c shell.c
($) exit
$
```

### Function [Main](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/la_shellula.c):
- Here's the flowchart of our function `main` and of the shell:
![Main Function Flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/29fd0653-d85b-4557-bc1e-f5f5ee45206b)
#### This function serves as the entry point of the program.
- It runs an infinite loop that repeatedly displays the prompt ("shellula$") using the function **display_prompt**, reads a command line using **read_line**, executes the command using **execute_command**, and frees the memory allocated for the command line.
- This loop continues indefinitely until the user explicitly exits the shell by entering the command "exit".

### Function [display_prompt](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/display_prompt.c):
- Here's the flowchart of the function `display_prompt`:
![Display Prompt Flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/275d6710-617f-4793-ac68-ba59c6aa1282)
#### This function displays the shell prompt to the user.
- Prints the prompt "shellula$" to the standard output and ensures (with `fflush`) that the prompt is immediately displayed by flushing the output buffer.

### Function [read_line](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/read_line.c):
- Here's the flowchart of the function `read_line`:
![Read Line Flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/7174cdfc-ef00-4ae2-a896-d9556ee6789a)
#### This function reads the input of the user.
- Reads the input line from standard input. Checks if the line of the input is read successfully (if not successful, it handles the error), checks if "exit" is entered (if so, it frees the memory used and exits the program). If the line is read successfully and "exit" was not entered, the function returns the input line for further use.

### Function [execute_command](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/execute_command.c):
- Here's the flowchart of the function `execute_command`:
- ![Execute command flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/ecb9bf98-7fd2-40b3-bc71-30ae8ba8cbd0)
#### This function executes a command entered by the user.
- Uses recursion with functions `analize_arguments` to parse the command string into arguments and `search` to execute the command by searching for its path and executing it. Lastly, it frees the memory allocated for the arguments array, to use it every time that the user inputs a command.

### Function [analize_arguments](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/analize_arguments.c):
- Here's the flowchart of the function `analize_arguments`:
![Analize Arguments Flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/88935676-049a-41b2-a830-3678bd5cab48)
#### This function tokenizes the command string.
- It begins initializing necessary variables, including 'i' for iteration and a pointer 'token' for tokenization.
- It allocates memory using malloc. If the memory allocation fails, it prints an error message.
- Uses `strtok` to tokenize the input command 'cmd' using spaces, tabs, and newline characters as delimiters. The first call to `strtok` tokenizes the command and initializes the token variable with the first token (argv[0]).
- It enters a loop that continues as long as token isn't null. Inside the loop, it checks if 'i' is less than `argv_size - 1` (to ensure that there is space in the `argv` array to store another token). If there's space, it assigns the current token to `argv[i]` and increments 'i'. Then, it tokenizes the input again to get the next token.
- After the loop, it sets `argv[i]` to null, to ensure that the `argv` array is properly terminated.
  #### It returns the `argv` array containing the parsed arguments.

### Function [search](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/search.c):
- Here's the flowchart of the function `search`:
![Search Flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/8cdcfc4c-77e5-4af5-902e-e09356090334)
#### This function searches the path of the command.
- It begins initializing necessary variables and checking if there are arguments to search for.
- If the arguments contain an absolute path, it calls `pid_function`. If the argument doesn't contain an absolute path, it starts searching through the directories specified in the PATH environment variable.
- It constructs the full path (for example /bin/cmd or /usr/bin/cmd) and checks if it's executable in each directory, if the command is found and executable it calls `pid function` and returns from the function. If the command is not found in any directory specified in the PATH varibable, it prints an error message.

### Funcion [mitosis](https://github.com/alisonalvezz/holbertonschool-simple_shell/blob/main/pid.c):
- Here's the flowchart of the function `mitosis`:
![Pid function flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/5ee36e8d-1439-452a-9a7d-bb969307939b)
#### This function is designed to execute a command passed as an argument (`cmd`) along with its arguments (`argv[]`) in a child process.
- The function starts by calling fork() system call to create a new child process.
- If fork fails, it prints an error message and exits the program, if it succeeds, it continues to execute code in both the parent and the child processes.
- In the child process, it uses `execve` to execute the specified command with any required arguments. If `execve` fails, it prints an error message and exits the child process.
- In the parent process, it waits for the child process to finish execution using `waitpid`. If `waitpid` fails, it prints an error message and exits the program.
- Once the child process completes its execution, both the parent and child processes exit. If the child process encounters an error during execution, it exits with a failure status.

## Compilation
This shell should be compilated with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
