'''
Above average

https://www.acmicpc.net/problem/4344
'''

C = int(input())
for i in range(C):
    temp = list( map(int, input().split()) )
    average = sum(temp[1:])/temp[0]
    count = 0
    for j in temp[1:]:
        if j > average:
            count += 1
    print("%0.3f" % (count / temp[0] * 100) + "%")
