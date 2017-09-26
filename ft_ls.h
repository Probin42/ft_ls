/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 16:15:33 by rweiss            #+#    #+#             */
/*   Updated: 2017/06/05 12:06:58 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include "./libft/libft.h"
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define CYAN		"\033[36m"
# define BROWN		"\033[33m"
# define NONE		"\033[39m"
# define GREEN		"\033[32m"
# define MAGENTA	"\033[35m"

typedef struct		s_lst
{
	char			*content;
	size_t			content_len;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_item
{
	char			*name;
	char			*path;
	char			*lnpath;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	dev_t			st_rdev;
	struct s_item	*next;
}					t_item;

typedef struct		s_flag
{
	int				a;
	int				l;
	int				r;
	int				t;
	int				upper_r;
	int				u;
	int				f;
	int				g;
}					t_flag;

typedef struct		s_len
{
	int				total;
	int				maj;
	int				min;
	int				len;
	int				groupspace;
	int				linkspace;
	int				userspace;
}					t_len;

void				ft_illegal_option(char flag);
void				ft_basic_error(char *name, char *error, int ex);
void				ft_lstpushback(t_lst **lst, void const *content,
		size_t content_len);
int					ft_strchr2(t_flag flag, char *str);
int					found_dash(char *str);
void				ft_get_arg(t_flag *flag, char *str);
void				ft_get_params(int nombre, char **params, t_flag *flag,
		t_lst **path);
t_item				*ft_new_item(char *name, char *path, t_flag flag);
int					ft_get_item(t_item **files, struct dirent *file,
		char *path, t_flag flag);
void				ft_get_item_file(t_item **files, char *name,
		char *path, t_flag flag);
void				ft_recursion(t_flag flag, t_item *file);
t_lst				*ft_lsttnew(void const *content, size_t content_len);
void				ft_earth_prog(t_flag flag, t_lst *path, int mdir);
void				ft_displayfile(t_flag flag, t_item *files, int fileordir);
void				ft_ls_dir2(t_flag flag, t_item *list, int multidir,
		char *tmp);
void				ft_ls_dir(t_flag flag, t_lst *path, int multidir);
t_item				*ft_sort_item(t_item *list, t_flag flag);
void				ft_copy_item(t_item **src, t_item *cpy);
void				ft_sort(t_item **list, int (*cmp)(t_item *item1,
			t_item *item2));
void				ft_reverse(t_item **list);
int					ft_cmp_alpha(t_item *item1, t_item *item2);
int					ft_cmp_time(t_item *item1, t_item *item2);
void				ft_get_color(mode_t mode);
void				ft_basic_ls(t_flag flag, t_item *files);
void				ft_notbasic_ls_file(t_flag flag, t_item *cur, t_len len);
void				ft_notbasic_ls(t_flag flag, t_item *files,
		int fileordirectory);
void				ft_print_rights(t_item *item);
void				ft_print_int(int link, int spacemax);
void				ft_print_str(char *str, int spacemaxx);
void				ft_print_majmin(t_item *file, t_len len);
void				ft_date(time_t date);
t_len				ft_get_size(t_flag flag, t_item *files);
void				ft_get_size_handling(t_len *len, t_item *cur);
void				ft_get_size_swiftly(t_len *len, t_item *cur);
void				ft_get_stat(t_flag flag, t_lst *file);
char				ft_print_special_right_grp(t_item *item);
char				ft_print_special_right_usr(t_item *item);
char				ft_print_special_right_t(t_item *item);
void				ft_lnk(t_item *cur, t_flag flag, char *buf);
void				free_files(t_item **files);
#endif
