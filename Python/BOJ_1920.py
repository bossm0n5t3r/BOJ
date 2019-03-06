"""
Find Number

https://www.acmicpc.net/problem/1920
"""


import sys


def sol():
    N = int(sys.stdin.readline().rstrip())
    check = set(sys.stdin.readline().rstrip().split())
    M = int(sys.stdin.readline().rstrip())
    for e in sys.stdin.readline().rstrip().split():
        if e in check:
            print(1)
        else:
            print(0)


if __name__ == "__main__":
    sol()
