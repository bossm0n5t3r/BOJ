'''
Sorting Coordinates 2

https://www.acmicpc.net/problem/11651
'''


import sys


def sol():
    input = sys.stdin.readline
    print = sys.stdout.write
    N = int(input())
    coordinates = []
    for i in range(N):
        coordinates.append(list(map(int, input().split())))
    for coordinate in sorted(coordinates, key=lambda x: (x[1], x[0])):
        print("%d %d\n" % (coordinate[0], coordinate[1]))


if __name__ == "__main__":
    sol()
