/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:52:29 by aminko            #+#    #+#             */
/*   Updated: 2024/02/11 19:02:48 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "key_code.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 700
# define ROTSPEED  0.2
# define MOVESPEED 0.2
# define ON_KEYDOWN	2

# define RED 		0x00FF0000
# define BLUE		0x000000FF
# define WHITE		0xFFFFFFFF
# define BLACK		0x00000000
# define CYAN		0x80A6FF

typedef struct s_plane
{
	double	plane_x;
	double	plane_y;
}				t_plane;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			rot_speed;
	double			move_speed;
	double			old_dir_x;
	double			old_plane_x;
}				t_player;

typedef struct s_ch_map
{
	int		n;
	int		s;
	int		w;
	int		e;
	int		amount;
	int		space_l;
}				t_ch_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_check
{
	int		nt;
	int		st;
	int		wt;
	int		et;
	int		floor;
	int		ceiling;
	int		amount;
	int		fd;
	char	*line;
	char	*trimmed;
}				t_check;

typedef struct s_win
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bpp;
	int		l_len;
	int		end;
	int		x;
	int		y;
}				t_win;

typedef struct s_data
{
	char	*s_txt;
	char	*w_txt;
	char	*e_txt;
	char	*n_txt;
	int		ceiling[3];
	int		floor[3];
}					t_data;

typedef struct s_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			s_dist_x;
	double			s_dist_y;
	double			delt_dist_x;
	double			delt_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	unsigned int	color;
}				t_raycast;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}				t_map;

typedef struct s_all
{
	t_win		*win;
	t_data		*data;
	t_map		*m;
	t_ch_map	*checker;
	t_player	*player;
	t_plane		*plane;
	char		*line;
	int			i;
	int			temp;
	int			width;
	int			height;
	t_raycast	*rc;
	t_win		*n_tex;
	t_win		*s_tex;
	t_win		*w_tex;
	t_win		*e_tex;
}				t_all;

// check_data.c //

void			check_spaces(t_all *all, char **map, int i, int j);
void			check_line_spaces(t_all *all, char **map, int i);
void			check_map(t_all *all);

// check_txt.c //

void			check_file(char *str);
void			add_path(char **args, t_check *ch, t_data *data);
void			add_txt(t_data *data, t_check *ch);

// check_map.c //

void			check_player(t_all *all);
void			check_corners(t_all *all, int i, int j);
int				check_symbol(t_all *all, char **map, int i, int j);
int				check_is_zero(t_all *all, char **map, int i, int j);
void			check_one_player(t_all *all, char **map, int i, int j);

// check_color.c //

int				ft_atoi_color(const char *str);
char			*color_to_struct(char *str, t_color *col, int i);
void			check_color(char *str, t_color *col);
void			add_colors(char **args,
					t_check *ch, t_data *data);

// exec.c //

void			executing(t_all *all);
void			print_map(int x, t_all *all);
void			draw_fc(t_all *all, int x);

// free.c //

void			free_list(t_list *head);
void			free_memory(t_all *all);
void			free_tab(char **tab);
int				close_win(t_all *all);
void			check_malloc(char *data, char *message, int num);

// init_struct.c //

void			init_check(t_check	*ch);
void			init_player(t_all *all);
void			init_data(t_all *all);

// init_player.c //

void			player_to_struct(t_all *all, int i, int j, char direction);
void			get_dir(char direction, t_all *all);
void			dir_2(char direction, t_all *all);

// mlx_func.c //

void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
void			right_left(t_all *all,
					int key_code, double move_speed);
void			up_down(t_all *all,
					int key_code, double move_speed);
int				key_hook(int key_code, t_all *all);
void			rotate(t_all *all, double rot_speed);

// parse.c //

void			parse_data(char **av, t_all *all);
void			skip_empty_shit(t_check *ch);
void			parse_map(t_check *ch, t_all *all);
void			make_map_tab(t_all *all,
					t_list *lst, int height, int width);

// raycast.c //

void			raycast_start(t_all *all);
void			toujour_raycast_hein(t_all *all);
void			dda_algo(t_all *all);
void			blabla(t_all *all);

// utils.c //

void			error_exit(char *str, int num);
void			print_tab(t_map *m);
char			*ft_spaces_str(int width, int len);
int				create_rgb(int r, int g, int b);

// textures.c //

void			draw_walls(t_all *all, int x);
void			draw_texture(t_all *all, t_win *tex, int x, int shade);
int				add_shade(double distance, int color);
unsigned int	get_tex_color_pixel(t_win *img, int x, int y);
void			my_img_to_xpm(t_win *win, char *path, t_win *data);

#endif
