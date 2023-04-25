void execute(char **tokens)
{
	pid_t pid;
	char *path = command_checker(tokens);
	int i = 0;
	int status = 0;

	if (path == NULL)
	{
		return;
	}
	while (tokens[i] != NULL)
	{
		if (strcmp(tokens[i], "&&") == 0)
		{
			tokens[i] = NULL;
			execute(tokens); /* execute first command */
			status = status && WIFEXITED(status) && (WEXITSTATUS(status) == 0);
			if (status == 0)
			{
				return; /* if first command fails, return without executing second command */
			}
			tokens += i + 1;
			i = 0;
			continue;
		}
		else if (strcmp(tokens[i], "||") == 0)
		{
			tokens[i] = NULL;
			execute(tokens); /* execute first command */
			status = status && WIFEXITED(status) && (WEXITSTATUS(status) == 0);
			if (status == 1)
			{
				return; /* if first command succeeds, return without executing second command */
			}
			tokens += i + 1;
			i = 0;
			continue;
		}
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		execve(path, tokens, environ);
		perror("execve failure");
		exit(1);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork failed");
		exit(1);
	}
}

