'''
Number of each numeric

https://www.acmicpc.net/problem/2577
'''

A = int(input())
B = int(input())
C = int(input())

tempint = A * B * C

templist = [int(i) for i in str(tempint)]

countlist = []

for i in range(10):
    count = 0
    for j in templist:
        if j == i:
            count += 1
    countlist.append(count)

for i in countlist:
    print(i)
