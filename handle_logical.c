void execute_logical_operators(char **tokens, int status)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		if (strcmp(tokens[i], "&&") == 0)
		{
			tokens[i] = NULL;
			execute(tokens);
			status = status && WIFEXITED(status) && (WEXITSTATUS(status) == 0);
			if (status == 0)
			{
				return;
			}
			tokens += i + 1;
			i = 0;
			continue;
		}
		else if (strcmp(tokens[i], "||") == 0)
		{
			tokens[i] = NULL;
			execute(tokens);
			status = status && WIFEXITED(status) && (WEXITSTATUS(status) == 0);
			if (status == 1)
			{
				return;
			}
			tokens += i + 1;
			i = 0;
			continue;
		}
		i++;
	}
}

