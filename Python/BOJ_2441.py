'''
Printing stars - 4

https://www.acmicpc.net/problem/2441
'''

N = int(input())
temp = ""
while N > 0:
    print(temp + "*" * N)
    temp += " "
    N -= 1
