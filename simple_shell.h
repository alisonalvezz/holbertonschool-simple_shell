#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char **environ;
void display_prompt(void);
void execute_command(char *cmd);
char *read_line();
void search(char *argv[]);
void mitosis(char *cmd, char *argv[]);
int main(void);
char **analize_arguments(char *cmd);
char *_getenv(const char *name);
int exit_command(const char *cmd);
#endif
