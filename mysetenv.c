#include <stdlib.h>
#include <string.h>

int my_setenv(const char *name, const char *value, int overwrite)
{
	size_t len_name;
	size_t len_value;
	char *new_var;
	int result;

	/*Check if name and value are not null pointers*/
	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	/*Check if name already exists in the environment and overwrite is not allowed*/
	if (getenv(name) != NULL && overwrite == 0)
	{
		return (0);
	}
	/*Allocate memory for the new environment variable*/
	len_name = strlen(name);
	len_value = strlen(value);
	new_var = malloc(len_name + len_value + 2);
	/*Copy name and value into the new environment variable*/
	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);
	/*Set the new environment variable*/
	result = putenv(new_var);
	/*Free the allocated memory*/
	free(new_var);
	return (result);
}

