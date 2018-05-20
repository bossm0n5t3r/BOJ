'''
Repeating Characters

https://www.acmicpc.net/problem/2675
'''

for i in range(int(input())):
    R, S = input().split()
    print("".join([i*int(R) for i in S]))
