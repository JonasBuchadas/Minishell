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
