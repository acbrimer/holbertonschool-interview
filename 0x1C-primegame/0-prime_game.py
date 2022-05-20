#!/usr/bin/python3
"""
0-prime_game
"""

def isPrime(n):
    """
    isPrime - checks if a number is prime
    return: True for prime, else Flase
    """
    if n==2 or n==3: return True
    if n%2==0 or n<2: return False
    for i in range(3, int(n**0.5)+1, 2):   # only odd numbers
        if n%i==0:
            return False
    return True

def getPrimes(n):
    """
    getPrimes - gets a list of primes to n
    return: list of pirmes
    """
    return [i for i in range(2, n) if isPrime(i)]


def isWinner(x, nums):
    """
    isWinner - checks if Maria or Ben is the winner of the prime game
    return: "Ben" or "Maria"
    """
    scores = [0, 0]

    # handle null x/nums, x==0, empty nums
    if not (x or nums) or x == 0 or len(nums) == 0:
        return None
    

    for n in range(x):
        primes = getPrimes(n)
        if (len(primes) % 2 == 0):
            scores[1] += 1
        else:
            scores[0] += 1
    
    if scores[0] == scores[1]:
        return None

    return "Maria" if scores[0] > scores[1] else "Ben"

