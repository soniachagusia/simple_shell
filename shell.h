#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;
int main(int argc, char *argv[]);
void end_of_file(char *regy);
void _free(char **cmd_args);
void new_regy(char **regy);
char *get_path(char **cmd_args, char **dir);
void show_prompt(void);
void handle_path(char **cmd_args, char **argv, char *regy);
void read_error(ssize_t vw, char *regy);
char **str_parser(char *regy);
char *del_var(char *str);
int handle_exit(char **cmd_args, char *regy);
void execute(char *path_t, char *cmd_args[]);
char *strcat_x(char *src, char *dest);
#endif
