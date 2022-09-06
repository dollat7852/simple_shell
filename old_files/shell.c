#include "shell.h"

char **environ;

int main(int argc __attribute__((unused)), char ** argv)
{
FILE stream;
char *buffer = NULL;
char **tokens, *token;
char delim[] = "\n ";
size_t n = 0;
int position = 0;
ssize_t num;
int i;
pid_t pid;
sigal (SIGINT, cntr_C);
{

}
printf("$");
num = getline(&buffer, &n, stdin);
// tokenization
 tokens = malloc(num * sizeof(char *));

 token = strtok(buffer, delim); //space used as delimiter

 while (token)
 {
    tokens[position++] = token;  
    token = strtok(NULL, delim); /* code */
 }
 tokens[position] = NULL;

 while(tokens[i])
    printf("%s\n", tokens[i++]);

pid = fork(); // create a fork function
if (pid == 0)
{
    if (execve(environ, tokens[0], tokens) == -1)
    {
    perror("failed");
    exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        perror("failed with pid");
        
}
//printf(">>%s\n", buffer);
printf("%lu", num);
return (0);
}