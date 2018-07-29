/*
** myirc.h for include in /home/parria_m/rendu/Tech2/PSU_2015_myirc/include
**
** Made by Maxime
** Login   <parria_m@epitech.net>
**
** Started on  Tue May 17 16:11:37 2016 Maxime
** Last update Jan Jun 5 14:23:27 2016
*/

#ifndef NCURSES_GENSHLIB_H_
# define NCURSES_GENSHLIB_H_

#define UP_ARROW	259
#define DOWN_ARROW	258
#define LEFT_ARROW	260
#define RIGHT_ARROW	261
#define ENTER		10
#define SPACE		32
#define BACKSPACE	263
#define PG_UP		339
#define PG_DOWN		338
#define TAB		9

typedef struct		s_entry
{
  int			input;
  int			cursor;
}			t_entry;

typedef struct		s_pos
{
  int			begin_x;
  int			begin_y;
  int			end_x;
  int			end_y;
}			t_pos;

/* Misc function */
/* If this == 0 return the actual char to display */
int	char_to_display(int this);

/* Draw function */
int	draw_line(t_pos pos);
int	draw_square(t_pos pos);

/* UserEntry function */
char	*get_entry(t_pos);
char	*get_entry_end(char *, int *);
int	is_arrow(int);
char	*get_entry_use(t_pos, char *, int, int *);
void	get_entry_display(t_pos, char *, int);
void	get_entry_move(int, int *);

/* Display function */
void	add_to_window(char *);
void	display_window(char *);

#endif	/* !NCURSES_GENSHLIB_H_ */
