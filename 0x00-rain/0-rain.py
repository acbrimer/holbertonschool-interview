#!/usr/bin/python3
""" 0-rain """


def getArea(startIx, walls):
    """ Computes the area from start ix and the next wall if exists """
    endIx = startIx + 1
    while walls[endIx] == 0:
        # end of walls
        if endIx == len(walls) - 1:
            return -1
        endIx += 1
    # return next height and width
    width = endIx - startIx - 1
    return min([walls[endIx], walls[startIx]]) * width


def rain(walls):
    """ Gets area of rain between n walls of varrying heights """
    area = 0
    for ix, h in enumerate(walls):
        # get the next wall if current position is a wall
        if h != 0 and ix < len(walls) - 1:
            a = getArea(ix, walls)
            # if getArea returns -1, no more walls
            if a == -1:
                return area
            area += a
    return area
