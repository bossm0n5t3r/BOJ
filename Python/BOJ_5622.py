'''
BAKA

https://www.acmicpc.net/problem/5622
'''

dial = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]
time = 0
for i in input():
    for j in range(len(dial)):
        if i in dial[j]:
            time += (j + 3)
            break
print(time)
