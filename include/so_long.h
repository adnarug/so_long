/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:10:56 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/26 12:30:44 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../lib/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "../Printf/ft_printf.h"
# define IMG_SIZE 64
# define IMAC_RES_Y 1344
# define IMAC_RES_X 2560

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int		x;
	int		y;
	t_bool	p_is_found;
}	t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
}	t_tiletype;

/* Struct for each tile */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	t_vector		size;
	t_bool			was_exit;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef enum e_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
}	t_enemyytpe;

/* Enemies animation  */
typedef struct s_enemy_imgs
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_low;
	void	*basic_mid;
}	t_enemy_img;

/* list of enemies */
typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

/* input keys */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

/* player  info*/
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	void			*wall_img;
	void			*collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_close_img;
	void			*red_panel;
	void			*white_panel;
}	t_game;

typedef struct s_map_data
{
	t_vector		size;
	t_vector		curs;
	t_bool			one_p;
	t_vector		player_position;
	t_bool			one_e;
	t_bool			at_least_one_c;
}				t_map_data;

void	game_init(t_game *game);
t_tile	**map_init(char **argv, t_game *game);
t_tile	**map_init(char **argv, t_game *game);
int		map_validity_check(char **map, int line_count);
void	check_border_integrity(t_map_data *map_data, char **map);
void	unique_tiles_check_after_flood(char **map, t_map_data *map_data);
void	remove_player(t_game *game);
void	kill_player(t_game *game);
int		end_program(t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);
void	error(char *message);
void	print_warning(char *message);
void	*null_error(char *message);
int		ft_chartable_linecount(char **table);
void	ft_free_chartable(char **table);
int		update(t_game *game);
t_bool	step_to(t_game *game, t_tile *tile);
int		input(int key, t_game *game);
t_enemy	*new_enemy(t_enemyytpe type, t_tile *tile);
t_enemy	*last_enemy(t_enemy *list);
void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile);
void	move_enemies(t_game *game);
t_bool	move_ver(t_enemy *enemy, t_game *game);
t_bool	move_hor(t_enemy *enemy, t_game *game);
void	enemy_animation(t_enemy_img *img);
void	kill_player(t_game *game);
void	valid_map(char **map);
int		map_validity_check(char **map, int line_count);
void	unique_tiles_check(char **map, t_map_data *map_data);

void	step_on_enemy(t_game *game);
void	step_on_exit(t_game *game);
void	step_through_exit(t_game *game, t_tile *tile);
void	step_on_collect(t_game *game, t_tile *tile);
void	step_on_empty(t_game *game, t_tile *tile);

void	check_file_extension(char *s);
int		ft_strlen_nl(const char *c);
void	check_valid_path(char **map, t_map_data *map_data);
void	unique_tiles_check_after_flood(char **map, t_map_data *map_data);
char	**map_dup(char **map, t_map_data map_data);
char	**alloc_columns(char *file, int *line_count);

#endif