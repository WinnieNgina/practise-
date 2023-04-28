#include "shell.h"

void handle_separator(char **tokens)
{
	int i = 0, j = 0;
	char *builtins[6] = {"exit", "env", "cd", "unsetenv", "setenv", NULL};
	int k;
	char *commands[MAX_NUM_TOKENS]; /* array of commands */
	int num_commands = 0; /* number of commands */

	/* split input into separate commands using semicolon separator */
	while (tokens[i] != NULL)
	{
		if (strcmp(tokens[i], ";") == 0) /* found separator */
		{
			commands[num_commands] = NULL; /* end current command */
			num_commands++; /* move to next command */
			j = 0;
		}
		else
		{
			commands[num_commands * MAX_NUM_TOKENS + j] = tokens[i]; /* populate command with tokens */
			j++;
		}
		i++;
	}
	commands[num_commands] = NULL; /* end last command */
	num_commands++; /* increment number of commands */
	/* execute each command sequentially */
	for (i = 0; i < num_commands; i++)
	{
		if (commands[i] != NULL)
		{
			for (k = 0; builtins[k]; k++)
			{
				if (my_strcmp(tokens[0], builtins[i]) == 0)
				{
					execute_builtins(tokens, environ);
					return (NULL);
				}
			}
		}
	}
}
