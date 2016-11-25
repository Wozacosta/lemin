/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:01:10 by srabah-m          #+#    #+#             */
/*   Updated: 2014/03/23 21:41:16 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define INFINITY		1000000000
# define NB_NODES_MAX	1000000

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct	s_queue
{
	int		front;
	int		rear;
	int		n_values;
	int		max;
	int		*data;
}				t_queue;

typedef struct		s_adj_node
{
	int					id;
	int					displayed;
	struct s_adj_node	*next;
}					t_adj_node;

typedef t_adj_node* t_adj_list;

typedef struct	s_graph
{
	int				nb_vertices;
	t_adj_list		*adj_list_array;
}				t_graph;

typedef struct	s_node
{
	char		*name;
	int			dist;
	int			visited;
	int			ant;
	int			coord[2];
	t_adj_list	bfs_next;
}				t_node;

size_t		ft_strlen(const char *str);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_putendl(char *str);

int			ft_isdigit(char c);
int			ft_atoi(const char *str);

void		ft_putstr_fd(int fd, const char *str);
int			ft_error(const char *str);
void		ft_fatal(const char *str);

char		*ft_itoa(int n);
char		*ft_strcpy(char *s1, const char *s2);

t_queue		*queue_create(int n);
int			queue_empty(t_queue *queue);
int			queue_full(t_queue *queue);
int			queue_enqueue(t_queue *queue, int id);
int			queue_dequeue(t_queue *queue);
void		queue_destroy(t_queue *queue);
void		bfs(void);
void		move_bfs(int i);
void		de_visit(void);
void		move(void);
void		display_move(int ant_nb, char *head, int i);
void		move_ant(int id, int i, t_adj_list next);
int			parse_anthill_bis(int j);

void		add_next(int tail, int head);
void		display_coord_node(int id);
void		set_as_displayed(char *from, char *to);
void		display_anthill(t_graph *graph);
int			parse_anthill_room(char *str);
int			parse_anthill(char *str);
void		get_anthill(void);
int			get_end_name(void);
int			add_link(char *str);
int			add_link_both(char *a, char *b);
int			find_node(char *name);
int			parse_cmd(char *str);
t_graph		*create_graph(int n);
t_adj_node	*create_adj_node(int id);
void		add_next(int tail, int head);
void		add_edge_directed(t_graph *graph, int a, int b);
void		add_edge(t_graph *graph, int a, int b);
char		*ft_strndup(const char *s1, int n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strchr(const char *s, int c);
void		get_nb_ants(void);
int			parse_anthill_coord(char *str, int id);
int			get_start_name(void);

extern int		g_nb_ants;
extern int		g_nb_nodes;
extern int		g_start_set;
extern int		g_end_set;
extern t_node	g_nodes[NB_NODES_MAX];
extern t_graph	*g_graph;
extern int		g_nb_start;
extern int		g_nb_end;
extern t_queue	*g_queue;

#endif /* !LEMIN_H */
