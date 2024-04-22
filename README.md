# Simple shell
<img src="https://s3.eu-west-3.amazonaws.com/hbtn.intranet.project.files/holbertonschool-low_level_programming/235/shell.jpeg" alt="the gates of shell" width="200"/>
^“The Gates of Shell”, by Spencer Cheng, featuring Julien Barbier

In this project we are expected to make a simple shell.

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
### Function Main:
Here's the flowchart of our function main and of the shell:
<img src="https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/29fd0653-d85b-4557-bc1e-f5f5ee45206b" alt="main function flowchart" width="200"/>
#### This function serves as the entry point of the program.
- It runs an infinity loop that repeatedly displays the prompt ("shellula$") using the function **display_prompt**, reads a command line using **read_line**, executes the command using **execute_command** and frees the memory allocated for the command line.
This loop continues indefinitely until the user explicity exits the shell by entering the command exit.

### Function display_prompt:
Here's the flowchart of the function display_prompt:
![display prompt flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/275d6710-617f-4793-ac68-ba59c6aa1282)
#### This function displays the shell prompt to the user.
- Prints the prompt "shellula$" to the standard output and ensures (with fflush) that the prompt is immediately displayed by flushing the output buffer.

### Function read_line:
Here's the flowchart of the function read_line:
![Read line flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/7174cdfc-ef00-4ae2-a896-d9556ee6789a)
#### This function reads the input of the user.
- Reads the input line from standard input. Checks if the line of the input is read successfully (if not succesfull, it handles the error), checks if "exit" is entered (if so, it frees the memory used and exits the program), if the line is read successfully and "exit" was not entered, the function returns the input line for further use.

### Function execute_command:
Here's the flowchart of the function execute_command:
![execute command flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/76143ef7-8762-4113-ae21-20e92b980a2c)
#### This function executes a command entered by the user.
- Uses recursion with functions **analize_arguments** to parse the command string into arguments and **search** to execute the command by searching for its path and executing it. Lastly it frees the memory allocated for the arguments array, to use it every time that the user inputs a command.

### Function analize_arguments:
Here's the flowchart of the function analize_arguments:
![analize arguments flowchart](https://github.com/alisonalvezz/holbertonschool-simple_shell/assets/159053351/88935676-049a-41b2-a830-3678bd5cab48)
#### This function tokenizes the command string.
- It begins initializing necessary variables, including 'i' for interation and a pointer 'token' for tokenization.
- It allocates memory using malloc, if the memory allocation fails it prints an error message.
- Uses strtok to tokenize the input command 'cmd' using spaces, tabs and newline characters as delimiters. The first call to strtok tokenizes the command and initializes the token variable with the first token (argv[0]).
- It enters a loop that continues as long as token isn't null. Inside the loop it checks if 'i' is less than argv_size -1 (to ensure that there is space in the argv array to store another token), and if theres space, it assigns the current token to argv[i] and increments i. Then, it tokenizes the input again to get the next token.
- After the loop, it sets argv[i] to null, to ensure that argv array is properly terminated.
  #### It returns the argv array containing the parsed arguments.

### Function search:
Here's the flowchart of the function search:
