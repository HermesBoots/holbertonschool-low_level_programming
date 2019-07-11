#!/usr/bin/python3
"""Module to find the perimeter of an island in an ocean"""

def get_neighbors(grid, square):
    """Get a list of cells neighboring another cell

    Args:
        grid (List[List[int]]): grid of ocean and land squares
        square (Tuple[int, int]): x, y coordinate pair

    Returns:
        Tuple[int]: list of neighbors, starting from the northern one and
        going clockwise, 0 means water, 1 means land, -1 is out of bounds

    """

    if square[1] == 0:
        north = -1
    else:
        north = grid[square[1] - 1][square[0]]
    if square[0] == len(grid[0]) - 1:
        east = -1
    else:
        east = grid[square[1]][square[0] + 1]
    if square[1] == len(grid) - 1:
        south = -1
    else:
        south = grid[square[1] + 1][square[0]]
    if square[0] == 0:
        west = 0
    else:
        west = grid[square[1]][square[0] - 1]
    return (north, east, south, west)

def island_perimeter(grid):
    """Return the perimeter of an island in an ocean grid

    Args:
        grid (List[List[int]]): grid where 0 is water and 1 is land

    """

    ret = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x] == 1:
                ret += 4 - get_neighbors(grid, (x, y)).count(1)
    return ret
