/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_queue_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:13:04 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:13:31 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_queue	*queue_create(int n)
{
	t_queue	*new_queue;

	new_queue = (t_queue *)malloc(sizeof(t_queue));
	new_queue->data = (int *)malloc(sizeof(int) * n);
	new_queue->front = 0;
	new_queue->rear = 0;
	new_queue->n_values = 0;
	new_queue->max = n;
	return (new_queue);
}

int		queue_empty(t_queue *queue)
{
	return (queue->n_values == 0);
}

int		queue_full(t_queue *queue)
{
	return (queue->n_values == queue->max);
}

int		queue_enqueue(t_queue *queue, int id)
{
	if (queue_full(queue))
		return (0);
	queue->data[queue->rear++] = id;
	queue->rear %= queue->max;
	queue->n_values++;
	return (1);
}

int		queue_dequeue(t_queue *queue)
{
	int		id;

	if (queue_empty(queue))
		exit(0);
	id = queue->data[queue->front++];
	queue->front %= queue->max;
	queue->n_values--;
	return (id);
}
