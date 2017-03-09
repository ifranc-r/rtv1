/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:48:11 by ifranc-r          #+#    #+#             */
/*   Updated: 2017/03/09 16:59:32 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <math.h>
# define BUFF_SIZE 1024

typedef struct		s_color
{
	double			a;
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(int const fd, char **line);
int					ft_power(int nbr, int power);
unsigned int		ft_abs(int n);
int					ft_strrealloc(char **str, char *addtostr);
char				*ft_freestrjoin(char *s1, char *s2, int s);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void	*b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strdup(const char *s1);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);

int					ft_toupper(int c);
int					ft_tolower(int c);

char				*ft_itoa(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_ditoa(double n, int c);
int					ft_exp(int n, int p);

t_vect				multi_vect(t_vect a, t_vect b);
t_vect				add_vect(t_vect a, t_vect b);
t_vect				minus_vect(t_vect a, t_vect b);
t_vect				multi_vect(t_vect a, t_vect b);
t_vect				devide_vect_double(t_vect a, double b);
t_vect				multi_vect_double(t_vect a, double b);
t_vect				normalize_vect(t_vect a);
t_vect				add_vect_double(t_vect a, double b);
t_vect				negative_vect(t_vect a);
double				magintude(t_vect a);
double				dot(t_vect a, t_vect b);
double				minus_double(t_vect a, t_vect b);
double				triangle_area(t_vect p1, t_vect p2, t_vect p3);
t_vect				cross_prod(t_vect a, t_vect b);
double				neg_dot(t_vect a, t_vect b);
double				solvequadratic(double a, double b, double c, int i);
double				lengh(t_vect a);
t_vect				devide_vect(t_vect a, t_vect b);

t_color				multi_color_double(t_color color, double b);
t_color				add_color(t_color a, t_color b);
void				color_condition(t_color *color);
t_color				init_color(double r, double g, double b, double a);
t_color				multi_color(t_color color, t_color b);
t_color				minus_color(t_color a, t_color b);
t_color				devide_color_double(t_color color, double b);
#endif
