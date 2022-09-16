#ifndef SO_LONG_H
# define SO_LONG_H

# include "./lib/mlx.h"
# include <stdlib.h>
# include <stdio.h>//to be deleted
# include <fcntl.h>
# include <string.h>//to be deleted
# include <unistd.h>
# include "./Printf/ft_printf.h"
# define IMG_SIZE 64

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;


typedef struct s_vector
{
	int x;
	int y;
}	t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_tiletype;

/* Struct for each tile */
typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

// ---------- IMAGES

/* All posible wall images */
typedef struct s_wall_img
{
	void	*block;
}	t_wall_img;

/* Collectables animation info */
typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

/* Info for the particle-like effect */
typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

/* An image that covers the whole window */
typedef struct s_panel
{
	void		*pointer;
	char		*pixels;
	t_vector	size;
	int			bpp;
	int			line_size;
	int			endian;
}	t_panel;

/* Color */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

// ---------- ENEMIES

typedef enum e_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
}	t_enemyytpe;

/* Enemies animation info */
typedef struct s_enemy_imgs
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_up;
	void	*basic_low;
	void	*basic_mid;
}	t_enemy_img;

/* Struct to make a list of enemies */
typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

// ---------- GAME

/* All valid input keys */
enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

/* Info about the player */
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
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

typedef struct s_map_data_checker
{
	t_vector		size;
	t_vector		curs;
	t_bool			one_P;
	t_bool			one_E;
	t_bool			at_least_one_C;
}	t_map_data_checker;

void	game_init(t_game *game);
int		end_program(t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);
int		error(char *message);
void	print_warning(char *message);
void	*null_error(char *message);
int		ft_chartable_linecount(char **table);
void	ft_free_chartable(char **table);
t_color	new_color(int r, int g, int b, int a);
void	color_panel(t_panel *panel, t_color color);
void	*new_panel(t_game *game, t_color color);
void	render(t_game game);
int		update(t_game *game);
t_bool  move_to(t_game *game, t_tile *tile);
int	input(int key, t_game *game);
t_enemy	*new_enemy(t_enemyytpe type, t_tile *tile);
t_enemy	*last_enemy(t_enemy *list);
void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile);
void	move_enemies(t_game *game);
t_bool	move_ver(t_enemy *enemy, t_game *game);
t_bool	move_hor(t_enemy *enemy, t_game *game);
void	enemy_animation(t_enemy_img *img);
void	kill_player(t_game *game, t_vector pos);
void	valid_map(char **map);

#endif