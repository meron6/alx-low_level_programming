#!/usr/bin/python3
"""
5-island_perimeter
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in grid.

    Args:
        grid (list of list of int): Grid representing the island.

    Returns:
        int: Perimeter of the island.
    """
    perimeter = 0

    # Iterate through each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            # Check if current cell is part of the island
            if grid[i][j] == 1:
                # Check top side
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                # Check left side
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                # Check right side
                if j == len(grid[0]) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
                # Check bottom side
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1

    return perimeter


if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
