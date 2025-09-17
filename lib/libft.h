/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:11:53 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/16 21:13:03 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include "sprintf/ft_sprintf.h"

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

typedef struct s_dbl_list
{
	void				*content;
	int					*index;
	struct s_dbl_list	*prev;
	struct s_dbl_list	*next;
}	t_dbl_list;

size_t		ft_strlen(char const *s);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
int			ft_atoi(const char *nptr);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strchr_nbr(char const *s, int c);
int			ft_strnrchr_nbr(char const *s, int c, int end);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_join_args(int length, ...);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strnstr(char const *big, char const *little, size_t len);
char		*ft_strchr(char const *s, int c);
char		*ft_strrchr(char const *s, int c);
char		*ft_strdup(char const *s);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
long		ft_atol(const char *nptr);
size_t		ft_strcspn(const char *s, const char *reject);
void		free_split(char ***split);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstswap(t_list **lst);

t_dbl_list	*ft_dbl_lstnew(void *content);
void		ft_dbl_lstadd_front(t_dbl_list **lst, t_dbl_list *new);
int			ft_dbl_lstsize(t_dbl_list *lst);
t_dbl_list	*ft_dbl_lstlast(t_dbl_list *lst);
void		ft_dbl_lstadd_back(t_dbl_list **lst, t_dbl_list *new);
void		ft_dbl_lstdelone(t_dbl_list *lst, void (*del)(void*));
void		ft_dbl_lstiter(t_dbl_list *lst, void (*f)(void *));
t_dbl_list	*ft_dbl_lstmap(t_dbl_list *lst, void *(*f)(void *),
				void (*del)(void *));
void		ft_dbl_lstclear(t_dbl_list **lst, void (*del)(void*));
void		ft_dbl_lstswap(t_dbl_list **lst);

#endif
