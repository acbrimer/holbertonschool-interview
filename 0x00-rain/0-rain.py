#!/usr/bin/python3
""" 0-rain """


def rain(walls):
    """ Gets area of rain between n walls of varrying heights """
    if len([h for h in walls if h > 0]) == 0:
        return 0
    lastWall = max([i for i, x in enumerate(walls) if x > 0])
    firstWall = min([i for i, x in enumerate(walls) if x > 0])
    w = walls[:lastWall+1]
    maxH = max(walls)
    grid = [[True if w[x] > 0 and y < w[x]
             else False for x in range(len(w))] for y in range(maxH)]
    grid = list(grid)

    def hasL(y, x):
        if x <= firstWall:
            return False
        prevX = x - 1
        while prevX > 0:
            if grid[y][prevX]:
                return True
            prevX -= 1
        return grid[y][0]

    def hasR(y, x):
        nextX = x + 1
        while nextX < len(w):
            if grid[y][nextX]:
                return True
            nextX += 1
        return grid[y][lastWall]

    area = 0
    for y, r in enumerate(grid):
        for x, c in enumerate(r):
            if not c and hasL(y, x) and hasR(y, x):
                area += 1
    return area
