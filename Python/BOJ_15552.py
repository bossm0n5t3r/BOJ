'''
Fast A + B

https://www.acmicpc.net/problem/15552
'''

import sys

T = int(sys.stdin.readline())
for i in range(T):
    a, b = map(int, sys.stdin.readline().split())
    print(a+b)
