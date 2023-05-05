void handle_variables(char *input, char *output)
{
	int i = 0, j = 0;
	char pid[10];
	sprintf(pid, "%d", getpid());
	while (input[i] != '\0')
	{
		if (input[i] == '$')
		{
			i++;
			if (input[i] == '$')
			{
				strcat(output, pid);
				j += strlen(pid);
			}
			else if (input[i] == '?')
			{
				char status[10];
				sprintf(status, "%d", WEXITSTATUS(status));
				strcat(output, status);
				j += strlen(status);
			}
			else if (isdigit(input[i])) {
                int num = input[i] - '0';
                if (num < argc-1) {
                    strcat(output, argv[num]);
                    j += strlen(argv[num]);
                }
            }
            else {
                char var[10];
                int k = 0;
                while (input[i] != '\0' && !isspace(input[i])) {
                    var[k++] = input[i++];
                }
                var[k] = '\0';
                char *val = getenv(var);
                if (val != NULL) {
                    strcat(output, val);
                    j += strlen(val);
                }
            }
        }
        else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
}

