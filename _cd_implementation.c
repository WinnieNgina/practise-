else if (strcmp(tokens[0], "cd") == 0) /* cd built-in command */
{
    char *path;
    if (tokens[1] == NULL)
    {
        path = getenv("HOME"); /* if no argument is given, use HOME directory */
    }
    else if (strcmp(tokens[1], "-") == 0)
    {
        path = getenv("OLDPWD"); /* if argument is "-", use OLDPWD directory */
        if (path == NULL)
        {
            write(STDERR_FILENO, "cd: OLDPWD not set\n", strlen("cd: OLDPWD not set\n"));
            return;
        }
    }
    else
    {
        path = tokens[1]; /* use the given path */
    }
    
    char *cwd = getcwd(NULL, 0);
    if (cwd == NULL)
    {
        write(STDERR_FILENO, "cd: getcwd failed\n", strlen("cd: getcwd failed\n"));
        return;
    }
    if (chdir(path) != 0) /* change directory */
    {
        write(STDERR_FILENO, "cd: unable to change directory\n", strlen("cd: unable to change directory\n"));
        free(cwd);
        return;
    }
    if (setenv("OLDPWD", cwd, 1) != 0) /* set OLDPWD environment variable */
    {
        write(STDERR_FILENO, "cd: failed to set OLDPWD environment variable\n", strlen("cd: failed to set OLDPWD environment variable\n"));
        free(cwd);
        return;
    }
    if (setenv("PWD", getcwd(NULL, 0), 1) != 0) /* set PWD environment variable */
    {
        write(STDERR_FILENO, "cd: failed to set PWD environment variable\n", strlen("cd: failed to set PWD environment variable\n"));
        free(cwd);
        return;
    }
    free(cwd);
}

