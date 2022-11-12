#include "minishell.h"

bool is_metachar(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '|' || c == '&' || c == ';' || c == '(' || c == ')' || c == '<' || c == '>')
		return true;
	return false;
}
