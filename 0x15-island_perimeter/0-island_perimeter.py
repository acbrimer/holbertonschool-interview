

def island_perimeter(grid):

    def getPerimAtCoord(y, x):
        p = 4
        # Check left is island
        if x - 1 >= 0 and grid[y][x - 1] == 1:
            p -= 1
        # Checks right is island
        if x + 1 < len(grid[y]) and grid[y][x + 1] == 1:
            p -= 1
        # Check check bottom is island
        if y - 1 >= 0 and grid[y - 1][x] == 1:
            p -= 1
        # Check top is island
        if y + 1 < len(grid) and grid[y + 1][x] == 1:
            p -= 1
        return p

    perimeter = 0
    # Loop over coords in grid to get 
    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if grid[y][x] == 0:
                continue
            perimeter += getPerimAtCoord(y, x)

    return perimeter
