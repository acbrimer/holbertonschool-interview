#!/usr/bin/python3
""" Module for 0-lockboxes """


def canUnlockAll(boxes) -> bool:
    """ canUnlockAll - checks if all boxes are unlocked """
    # keys = unique box values from current ix
    # starts at 0 + all vals in boxes[0] b/c first box is unlocked
    keys = list(set(boxes[0]) | {0})
    # if index of boxes in keys, box is unlocked
    for i in range(len(boxes)):
        if i not in keys:
            return False
        for b in boxes[i]:
            if b not in keys:
                keys.append(b)
    return True
