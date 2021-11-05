#!/usr/bin/python3
""" Module for 0-lockboxes """


def canUnlockAll(boxes) -> bool:
    """ canUnlockAll - checks if all boxes are unlocked """
    ix = 0
    keys = list(set(boxes[0]) | {0})
    check = True
    while check:
        check = False
        res = []
        for k in keys[ix:]:
            res += boxes[k]
        for k in res:
            if k not in keys:
                keys.append(k)
                ix += 1
                check = True
    return len(keys) == len(boxes)
