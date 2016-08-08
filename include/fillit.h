/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 02:30:47 by jerollin          #+#    #+#             */
/*   Updated: 2016/04/13 02:30:50 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_tetra
{
	char			**pos;
	struct s_tetra	*next;
}					t_tetra;

typedef struct		s_off
{
	int				x;
	int				y;
}					t_off;

int					ft_check_error_second(char **str, int erret);
int					ft_check_error(t_tetra **list, char **str);
int					ft_check_hor_len_high(char **str);
int					ft_check_vert_len_right(char **str);
int					ft_check_hor_length_down(char **str);
int					ft_check_vert_len_left(char **str);
int					ft_is_stick(char **str);
int					ft_is_square(char **str);
int					ft_is_l(char **str);
int					ft_is_t(char **str);
int					ft_is_sharp(char **str);
int					ft_is_l_second(char **str, t_off pos);
void				ft_putab(char **str);
char				**ft_resize1(char **str);
char				**ft_resize2(char **str);
char				**ft_resize3(char **str);
char				**ft_resize4(char **str);
int					ft_tablen(char **str);
t_off				ft_find_first_sharp(char **str);
int					ft_count_sharp(char **str);
int					ft_file_parser(int fd, t_tetra **list);
t_tetra				*ft_tetra_create(char **pos);
void				ft_tetra_add(t_tetra **list, char **element);
int					ft_tetra_len(t_tetra **tetra_list);
void				ft_tetra_print(t_tetra **list);
void				ft_putstrtab(char **str);
int					ft_approx_root(int nb);
char				**ft_init_mat(int size);
char				**ft_matcopy(char **src);
int					ft_is_piece_fits(char **mat, char **tetra, t_off *offset);
void				ft_insert_piece(char **mat, char **tetra, t_off *offset);
void				ft_tetra_del(t_tetra **alst);
int					ft_mat_del(char **mat);
t_off				*ft_init_offset(void);
int					ft_get_offset(char **mat, char **tetra, t_off *offset);
char				**ft_resolve_fillit(char **mat, t_tetra *tetra);

#endif
