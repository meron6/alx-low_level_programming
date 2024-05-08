#include <stdio.h>
#include <math.h> // For sqrt function

int jump_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    // Calculate the jump step (square root of the array size)
    size_t jump = (size_t)sqrt(size);
    size_t prev = 0;

    // Perform the jump search
    while (array[jump] <= value && jump < size)
    {
        printf("Value checked array[%lu] = [%d]\n", jump, array[jump]);
        prev = jump;
        jump += sqrt(size);
    }

    // Linear search within the block
    printf("Value found between indexes [%lu] and [%lu]\n", prev, jump);
    for (size_t i = prev; i < size; ++i)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return i;
    }

    return -1; // Value not found
}

int main(void)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
    printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
    printf("Found %d at index: %d\n", 999, jump_search(array, size, 999));

    return 0;
}
