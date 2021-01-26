#ifndef CUB3D_H
# define CUB3D_H
 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mlx.h"

#define ESC							53 
#define W							13
#define A							0
#define S							1
#define D							2
#define LEFT						123
#define RIGHT						124






//
#define NoEventMask					0L
#define KeyPressMask				(1L<<0)
#define KeyReleaseMask				(1L<<1)
#define ButtonPressMask				(1L<<2)
#define ButtonReleaseMask			(1L<<3)
#define EnterWindowMask				(1L<<4)
#define LeaveWindowMask				(1L<<5)
#define PointerMotionMask			(1L<<6)
#define PointerMotionHintMask		(1L<<7)
#define Button1MotionMask			(1L<<8)
#define Button2MotionMask			(1L<<9)
#define Button3MotionMask			(1L<<10)
#define Button4MotionMask			(1L<<11)
#define Button5MotionMask			(1L<<12)
#define ButtonMotionMask			(1L<<13)
#define KeymapStateMask				(1L<<14)
#define ExposureMask				(1L<<15)
#define VisibilityChangeMask		(1L<<16)
#define StructureNotifyMask			(1L<<17)
#define ResizeRedirectMask			(1L<<18)
#define SubstructureNotifyMask		(1L<<19)
#define SubstructureRedirectMask	(1L<<20)
#define FocusChangeMask				(1L<<21)
#define PropertyChangeMask			(1L<<22)
#define ColormapChangeMask			(1L<<23)
#define OwnerGrabButtonMask			(1L<<24)

/* Event names.  Used in "type" field in XEvent structures.  Not to be
confused with event masks above.  They start from 2 because 0 and 1
are reserved in the protocol for errors and replies. */

#define KeyPress			2
#define KeyRelease			3
#define ButtonPress			4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify			7
#define LeaveNotify			8
#define FocusIn				9
#define FocusOut			10
#define KeymapNotify		11
#define Expose				12
#define GraphicsExpose		13
#define NoExpose			14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify			18
#define MapNotify			19
#define MapRequest			20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define GenericEvent		35
#define LASTEvent			36    /* must be bigger than any event # */


/* Key masks. Used as modifiers to GrabButton and GrabKey, results of QueryPointer,
   state in various key-, mouse-, and button-related events. */

#define ShiftMask       (1<<0)
#define LockMask        (1<<1)
#define ControlMask     (1<<2)
#define Mod1Mask        (1<<3)
#define Mod2Mask        (1<<4)
#define Mod3Mask        (1<<5)
#define Mod4Mask        (1<<6)
#define Mod5Mask        (1<<7)

/* modifier names.  Used to build a SetModifierMapping request or
   to read a GetModifierMapping request.  These correspond to the
   masks defined above. */
#define ShiftMapIndex       0
#define LockMapIndex        1
#define ControlMapIndex     2
#define Mod1MapIndex        3
#define Mod2MapIndex        4
#define Mod3MapIndex        5
#define Mod4MapIndex        6
#define Mod5MapIndex        7

int g_error;
typedef struct	s_list
{
	char *line;
	struct s_list *next;

}				t_list;

typedef struct s_parser 
{
	char *n_tex;
	char *s_tex;
	char *w_tex;
	char *e_tex;
	char *color_floor;
	char *color_ceil;
	char *sprite_tex;
	char *size_screan;
}				t_parser;

typedef struct	s_cub
{
    double			*dist;
    void			*mlx;
    void			*mlx_win;
	void			*mlx_tex;
	int				width;
	int				height;
	void			*image;
	char			**map;
	char			*data;
	int				size_line;
	int				sprite_num;
	int				bpp;
	double			*sprite_dir;
	int				*sprite_x;
	int				*sprite_y;
	double			hit;
	double			hit_sprite;
	double			dist_wall;
	double			*dist_sprite;
	double			cos;
	double			sin;
	double			x;
	double			y;
	double			direction;
	double			fov;
	int				what_texture;
	int				r_floor;
	int				g_floor;
	int				b_floor;
	int				r_ceil;
	int				g_ceil;
	int				b_ceil;
	int				size_line_tspr;
	int				size_line_tn;
	int				size_line_ts;
	int				size_line_te;
	int				size_line_tw;
	int				width_texture_sprite;
	int				height_texture_sprite;
	int				height_texture;
	int				width_texture;
	int				height_texture_s;
	int				width_texture_s;
	int				height_texture_e;
	int				width_texture_e;
	int				height_texture_w;
	int				width_texture_w;
	void			*texture_sprite;
	void			*texture_north;
	void			*texture_south;
	void			*texture_west;
	void			*texture_east;
	char			*texture_add_sprite;
	char			*texture_add_south;
	char			*texture_add_north;
	char			*texture_add_west;
	char			*texture_add_east;
	t_parser		*par;
	t_list			*lst;
}				t_cub;


void		drow_wall(t_cub *cub, int i);
char*		give_color(t_cub *cub, double kall, double hit);
double		map_wall(double x, double y, t_cub *cub);
void		my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub);
void		drow_sprite(t_cub *cub, int k, int i);
size_t		ft_strlen(const char *str);
double		valid_pi(double dir);
int			where_im(int key, t_cub *cub);
int			search_wall(t_cub *cub);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *str);
char		*find_new_line(char *buff);
int			get_next_line(int fd, char **line);
void		ft_lstadd_back(t_list **lst, t_list *lst_new);
int			ft_lstsize(t_list *lst);
char 		*texture_add_north;
void		what_in_line(char *line, t_cub *cub);
t_list		*ft_lstnew(char *content);
t_list		*ft_lstlast(t_list *lst);
void		all_set(t_cub *cub);
void		all_free(t_cub *cub);
void		valid_map(t_cub *cub);
int			ft_atoi_cub(const char *str, int *i);
int			skip_spaces(const char *line, int i);
void		parser(t_cub *cub);
void		set_all(t_cub *cub);
void 		where_sprite(t_cub *cub, int i);
void		d(t_cub *cub, int i, int size, int point_sprite);



#endif
