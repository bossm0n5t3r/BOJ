'''
Honeycomb

https://www.acmicpc.net/problem/2292
'''

N = int(input())
ub = pt = 1
while ub < N:
    ub += pt * 6
    pt += 1
print(pt)
