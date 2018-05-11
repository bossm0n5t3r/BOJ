'''
Score

https://www.acmicpc.net/problem/8958
'''

N = int(input())

for i in range(N):
    sum = 0
    for i in map(len, input().split("X")):
        sum += i * (i+1) // 2
    print(sum)
