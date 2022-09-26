#include "minishell.h"

t_minishell	*ms(void)
{
	static t_minishell	ms;

	return (&ms);
}
