#!/usr/bin/python3

"""0-making_change"""


def makeChange(coins, total):
    """makeChange - returns the fewest number of coins needed to meet total"""
    count = 0
    if total <= 0:
        return count

    for coin in sorted(coins, reverse=True):
        while (total >= coin):
            if (total - coin < 0):
                break
            total -= coin
            count += 1
            if (total == 0):
                return count
            if (total < 0):
                return -1
    if total != 0:
        return -1
    return count
