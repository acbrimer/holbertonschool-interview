#!/usr/bin/python3
""" Module for 0-lockboxes """


def canUnlockAll(boxes) -> bool:
    """ canUnlockAll - checks if all boxes are unlocked """
    # keys = unique box values from current ix
    # starts at 0 b/c first box is unlocked
    keys = [0]
    unlocked = [0]

    willUnlock = True
    while willUnlock:
        willUnlock = False
        for ix, box in enumerate(boxes):
            if ix in keys:
                if ix not in unlocked:
                    unlocked.append(ix)
                for bk in box:
                    if bk not in keys:
                        keys.append(bk)
                        # reset willUnlock
                        willUnlock = True
    # if num unlocked = num boxes, all have been unlocked
    return len(unlocked) == len(boxes)
