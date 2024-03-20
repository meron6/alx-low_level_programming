#!/usr/bin/python3
"""
This module contains a function to calculate the perimeter of an island.
"""

def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in grid.

    Args:
        grid (list of list of int): Represents the island where 1 represents land
                                     and 0 represents water.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0

    # Iterate over each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:  # If cell is land
                # Check its neighbors and increment perimeter for each water cell
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == len(grid[0]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter

# Test the function
if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))

