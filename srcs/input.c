#include "minishell.h"

int read_file(char *filename)
{
	int fd_input;

	if (access(filename, F_OK) == ERROR)
	{
		file_error("NO FILE", filename, false);
		fd_input = NO_INPUT_FILE;
	}
	else if (access(filename, R_OK) == ERROR)
	{
		file_error("NO PERMISSION", filename, false);
		fd_input = NO_INPUT_FILE;
	}
	else
		fd_input = open(filename, O_RDONLY);
	if (fd_input == ERROR)
		program_errors("OPENING INPUT FILE", true, true);
	return fd_input;
}
