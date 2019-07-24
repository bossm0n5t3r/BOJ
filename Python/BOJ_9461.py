'''
Padovan Sequence

https://www.acmicpc.net/problem/9461
'''


import sys


def sol():
    input = sys.stdin.readline
    print = sys.stdout.write
    T = int(input())
    save = {1 : 1, 2 : 1, 3 : 1, 4 : 2, 5 : 2}
    padovan(save, 100)
    for i in range(T):
        print(str(save[int(input())]) + "\n")


def padovan(save, n):
    if n not in save:
        save[n] = padovan(save, n - 1) + padovan(save, n - 5)
    return save[n]


if __name__ == "__main__":
    sol()
