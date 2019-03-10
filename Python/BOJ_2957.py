"""
Binary Search Tree

https://www.acmicpc.net/problem/2957
"""


import sys


def sol():
    N = int(sys.stdin.readline().rstrip())
    MAX_N = 300000
    left = [0] * (MAX_N + 2)
    right = [0] * (MAX_N + 2)
    lev = [0] * (MAX_N + 2)
    data = [0] * (MAX_N + 1)
    C = 0
    result = []
    for i in range(1, N + 1):
        data[i] = int(sys.stdin.readline().rstrip())
        left[i] = i - 1
        right[i] = i + 1
    for i in range(N, -1, -1):
        right[left[data[i]]] = right[data[i]]
        left[right[data[i]]] = left[data[i]]
    lev[0] = lev[N + 1] = -1
    for i in range(1, N + 1):
        lev[data[i]] = max(lev[left[data[i]]], lev[right[data[i]]]) + 1
        C += lev[data[i]]
        result.append(str(C))
    print('\n'.join(result))


if __name__ == "__main__":
    sol()
