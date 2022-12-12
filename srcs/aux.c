#include "minishell.h"

bool is_metachar(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '|' || c == '&' || c == ';' || c == '(' || c == ')' || c == '<' || c == '>')
		return true;
	return false;
}

void *protected_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		program_errors("MALLOC", true, true);
	return ptr;
}

void dup2_util(int read_end, int write_end)
{
	if (dup2(read_end, STDIN_FILENO) == ERROR)
		program_errors("DUP2", true, true);
	if (dup2(write_end, STDOUT_FILENO) == ERROR)
		program_errors("DUP2", true, true);
}
