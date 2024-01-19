#include "main.h"
/**
 * _stelen - program return the length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longa = 0; 

	while (*s != '\0')
	{
		longa++;
		s++;
	}
	return (longa);
}
