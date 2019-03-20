"""
Presentation of a Set

https://www.acmicpc.net/problem/1717
"""


import sys


def sol():
    n, m = map(int, sys.stdin.readline().rstrip().split())
    parents = [i for i in range(n + 1)]
    for i in range(m):
        check, a, b = map(int, sys.stdin.readline().rstrip().split())
        if check == 0:
            union(a, b, parents)
        else:
            if find(a, parents) == find(b, parents):
                sys.stdout.write("YES\n")
            else:
                sys.stdout.write("NO\n")
        

def find(x, parents):
    if parents[x] == x:
        return x
    else:
        parents[x] = find(parents[x], parents)
        return parents[x]


def union(x, y, parents):
    if find(x, parents) != find(y, parents):
        parents[find(x, parents)] = y


if __name__ == "__main__":
    sol()
