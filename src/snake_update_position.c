#include "../includes/snake.h"

t_snake			*snake_going_up(t_snake *snake)
{
	t_snake		*tmp;

	tmp = snake;
	snake = snake->next;
	free(tmp);
	snake->prev = NULL;
	while (snake->next)
		snake = snake->next;
	tmp = (t_snake*)malloc(sizeof(t_snake));
	tmp->x = snake->x;
	tmp->y = snake->y - 20;
	tmp->prev = snake;
	tmp->next = NULL;
	snake->next = tmp;
	return (snake);
}

t_snake			*snake_going_right(t_snake *snake)
{
	t_snake		*tmp;

	tmp = snake;
	snake = snake->next;
	free(tmp);
	snake->prev = NULL;
	while (snake->next)
		snake = snake->next;
	tmp = (t_snake*)malloc(sizeof(t_snake));
	tmp->x = snake->x + 20;
	tmp->y = snake->y;
	tmp->prev = snake;
	tmp->next = NULL;
	snake->next = tmp;
	return (snake);
}

t_snake			*snake_going_down(t_snake *snake)
{
	t_snake		*tmp;

	tmp = snake;
	snake = snake->next;
	free(tmp);
	snake->prev = NULL;
	while (snake->next)
		snake = snake->next;
	tmp = (t_snake*)malloc(sizeof(t_snake));
	tmp->x = snake->x;
	tmp->y = snake->y + 20;
	tmp->prev = snake;
	tmp->next = NULL;
	snake->next = tmp;
	return (snake);
}

t_snake			*snake_going_left(t_snake *snake)
{
	t_snake		*tmp;

	tmp = snake;
	snake = snake->next;
	free(tmp);
	snake->prev = NULL;
	while (snake->next)
		snake = snake->next;
	tmp = (t_snake*)malloc(sizeof(t_snake));
	tmp->x = snake->x - 20;
	tmp->y = snake->y;
	tmp->prev = snake;
	tmp->next = NULL;
	snake->next = tmp;
	return (snake);
}

t_snake			*snake_update_position(t_snake *snake, int direction)
{
	if (!snake || !snake->next)
		failure_exit_program("PLUS DE SNAKE", NULL);
	if (direction == 1)
		snake = snake_going_up(snake);
	else if (direction == 2)
		snake = snake_going_right(snake);
	else if (direction == 3)
		snake = snake_going_down(snake);
	else if (direction == 4)
		snake = snake_going_left(snake);
	while (snake->prev)
		snake = snake->prev;
	return (snake);
}
