#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - ...
 * @width: ...
 * @height: ...
 *
 * Return: ...
 */

int **alloc_grip(int width, int height)
{
	int i, j, l,;
	int **a;

	if (width <= 0 || height <= 0)
		return (NULL);

	a = malloc(sizeof(int *) * height);

	if (a == NULL)
	{
		free(a);
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		a[i] = malloc(sizeof(int) * width);

		if (a [i] == NULL)
		{
			free(a[j]);
			return (NULL);
		}
	}

	for (k = 0; k  < height; k++)
	{
		for (l = 0; l < width; l++)
		{
			a[k][l] = 0;
		}
	}

	return (a);
}
