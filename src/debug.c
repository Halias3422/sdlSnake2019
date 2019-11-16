#include "../includes/snake.h"

void		print_snake_list(t_snake *snake)
{
	while (snake)
	{
		printf("snake->x = %d snake->y = %d\n", snake->x, snake->y);
		if (snake->next == NULL)
			printf("DEJA NULL!!\n");
		snake = snake->next;
	}
}
