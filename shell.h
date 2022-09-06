#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define READ_BUF 1000
#define DELIM " \a\t\r\n"

/* command type */
#define INTERNAL_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

/* declaring global environ variable */
extern char **environ;

typedef struct internal_func
{
	char *cmd_name;
	void (*func)(char **command);
} map_func;


int _strlen(char *var);
int print (char *var, int fd);
void ctrl_C(int signum);
char *_getline(void);
char *_realloc(char *ptr, int new_size);
int is_delimeter(const char *delimeters, char c);
char **tokenize(char *str, const char *delim);
void execute(char **commands, int cmd_type);
void shell_execute(char **command, int cmd_type);
int check_command(char *command);
int _strcmp(char *str1, char *str2);
void (*get_func(char *command))(char **);
char *_getenv(char *path);
void env(char **command __attribute__((unused)));
void quit(char **command);
void ch_dir(char **command);


#endif