#include "minishell.h"

void read_file(char *filename)
{
	if (access(filename, F_OK) == ERROR)
	{
		file_error("NO FILE", filename, false);
		ms()->fd_input = NO_INPUT_FILE;
	}
	else if (access(filename, R_OK) == ERROR)
	{
		file_error("NO PERMISSION", filename, false);
		ms()->fd_input = NO_INPUT_FILE;
	}
	else
		ms()->fd_input = open(filename, O_RDONLY);
	if (ms()->fd_input == ERROR)
		program_errors("OPENING INPUT FILE", true, true);
}
