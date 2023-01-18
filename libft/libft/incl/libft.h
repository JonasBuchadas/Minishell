/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:38:37 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/16 22:05:29 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct d_list
{
	void			*content;
	struct d_list	*next;
	struct d_list	*prev;
}					t_dlist;

# define BUFFER_SIZE 1

// MANDATORY PROTOTYPES
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
// LINKED LIST PROTOTYPES
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// CIRCULAR DOUBLE LINKED LISTS PROTOTYPES
t_dlist	*ft_cdlstnew(void *content);
void	ft_cdlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_cdlstadd_front(t_dlist **lst, t_dlist *new);
int		ft_cdlstsize(t_dlist *lst);
t_dlist	*ft_cdlstlast(t_dlist *lst);
void	ft_cdlstdelone(t_dlist *lst, void (*del)(void *));
void	ft_cdlstclear(t_dlist **lst, void (*del)(void *));
void	ft_cdlstiter(t_dlist *lst, void (*f)(void *));
// ADDITIONAL PROTOTYPES
char	*get_next_line(int fd);
void	ft_sort_int_tab(int *tab, int size);
int		ft_min_int(int n, ...);
int		ft_max_int(int n, ...);
bool	ft_strequal(char *s1, char *s2);
void	ft_strarray_clear(char ***str_array);
void	ft_strdel(char **str);
void	ft_memdel(void **mem);
#endif
