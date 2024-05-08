#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array
 *
 * @array: array
 * @size: array size
 * @value: val to search
 *
 * Return: index of value, otherwise -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, index;

	low = 0;
	high = size - 1;

	if (!array)
		return (-1);

	while (low <= high)
	{
		if (low == high)
		{
			if (array[low] == value)
				return (low);
			return (-1);
		}

		index = low + (((double)(high - low) / (array[high] - array[low]))
		* (value - array[low]));
		if (value < array[low] || value > array[high])
		{
			printf("Value checked array[%lu] is out of range\n", index);
			return (-1);
		}


		printf("Value checked array[%lu] = [%i]\n", index, array[index]);
		if (array[index] == value)
			return (index);

		if (array[index] < value)
			low = index + 1;
		else
			high = index - 1;

	}
	return (-1);
}
