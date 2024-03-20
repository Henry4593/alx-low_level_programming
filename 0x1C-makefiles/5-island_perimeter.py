#!/usr/bin/python3
"""Defines a function computing the perimeter of the island landmass"""


def island_perimeter(grid):
    """Calculates the total length of the external boundary of the land area.

    The grid is a representation of a body of water, where 0 indicates water
    and 1 indicates land.

    Args:
        grid (list): A two-dimensional list of integers representing a landmass
                    within a body of water.

    Returns:
        int: The total length of the external boundary of the land area in the
            grid.
    """
    height, width = len(grid), len(grid[0])
    island_perimeter = 0

    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for row in range(height):
        for col in range(width):
            if grid[row][col] == 1:
                size += 1
                if (col > 0 and grid[row][col - 1] == 1):
                    edges += 1
                if (row > 0 and grid[row - 1][col] == 1):
                    edges += 1
    island_perimeter = size * 4 - edges * 2

    return island_perimeter
