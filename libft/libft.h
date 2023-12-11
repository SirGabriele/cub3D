/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:16:54 by kbrousse          #+#    #+#             */
/*   Updated: 2023/01/13 15:46:09 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

typedef struct s_listgnl
{
	int					fd;
	char				*buf;
	char				*line;
	int					tdl;
	int					i;
	int					hmb_read;
	int					nb_of_read;
	struct s_listgnl	*next;
}	t_listgnl;

// CHAR
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);

char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strcapitalize(char *str);

//STR
size_t				ft_strlen(const char *str);
size_t				ft_strlen_no_newline(const char *str);
int					ft_substrlen(const char *str, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, \
						size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strjoin_free_first(char *s1, char const *s2);
char				*ft_strnjoin_free_first(char *s1, char const *s2, size_t n);
char				*ft_strjoin_free_second(char const *s1, char *s2);
char				*ft_strnjoin_free_second(char const *s1, char *s2, \
						size_t n);
char				*ft_strjoin_free_both(char *s1, char *s2);
char				*ft_strnjoin_free_both(char *s1, char *s2, size_t n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				**ft_split_char(char const *s, char c);
char				**ft_split_set(char const *str, char *set);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, int n);
char				**ft_strdup_double(const char **src);
int					ft_extension(const char *filename, const char *extension);
int					is_an_int(char *arr);
int					is_char_in_set(const char c, const char *set);

//MEMORY
void				*ft_memset(void *ptr, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				free_double_arr(char **arr);

//OUTPUT
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(int fd, char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nb);

//ATOI_ITOA
int					ft_atoi(const char *nbr);
long int			ft_atol(const char *nbr);
long long int		ft_atoll(const char *nbr);
double				ft_atod(const char *nbr);
char				*ft_itoa(int n);

//LL
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
						void (*del)(void *));

//FT_PRINTF_FD
int					ft_printf_fd(int fd, const char *fmt, ...);
void				ft_specifier_requested_fd(const char **fmt, int *i, \
						va_list param, int fd);
void				ft_putcharprintf_fd(unsigned const char c, int *i, int fd);
void				ft_putstrprintf_fd(char *str, int *i, int fd);

//FT_PRINTF
int					ft_printf(const char *format, ...);
void				ft_specifier_requested(const char **fmt, int *i, \
						va_list param);
void				ft_putcharprintf(unsigned const char c, int *i);
void				ft_putstrprintf(char *str, int *i);

//FT_PRINTF_ERROR
int					ft_printf_error(const char *format, ...);
void				ft_specifier_asked_error(const char **fmt, int *i, \
						va_list param);
void				ft_putcharprintf_error(unsigned const char c, int *i);
void				ft_putstrprintf_error(char *str, int *i);

//GNL

char				*get_next_line(int fd);
void				ft_read_file_and_fill_buf(t_listgnl *temp);
void				ft_fill_line(t_listgnl *temp);
char				*ft_increase_string_size(t_listgnl *temp);
void				ft_erase_linkgnl(t_listgnl **first_elem, t_listgnl *temp);
t_listgnl			*ft_lstnewgnl(int entry_fd);
t_listgnl			*ft_go_to_linkgnl(t_listgnl **first_elem, int fd);
void				ft_lst_addbackgnl(t_listgnl **first_elem, t_listgnl *new);
int					check_string(char *str);
void				*ft_callocgnl(int size);

#endif
