'''
Average integer value

https://www.acmicpc.net/problem/10039
'''

sum = 0

for i in range(5):
    temp = int(input())
    if temp < 40:
        sum += 40
    else:
        sum += temp

print(sum // 5)
