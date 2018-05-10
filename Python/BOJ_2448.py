'''
Printing stars - 11

https://www.acmicpc.net/problem/2448
'''

import sys

N = int(sys.stdin.readline())
space = []

def printStars(x, y, N):
    if N == 3:
        space[y][x+2] = "*"
        space[y+1][x+1] = "*"
        space[y+1][x+3] = "*"
        space[y+2][x] = "*"
        space[y+2][x+1] = "*"
        space[y+2][x+2] = "*"
        space[y+2][x+3] = "*"
        space[y+2][x+4] = "*"
        return;
    div = N // 2
    printStars(x + div, y, div)
    printStars(x, y + div, div)
    printStars(x + N, y + div, div)

for j in range(N):
    temp = []
    for i in range(2*N):
        temp.append(" ")
    space.append(temp)

printStars(0, 0, N)

for j in range(N):
    sys.stdout.write(''.join(space[j]))
    sys.stdout.write("\n")
