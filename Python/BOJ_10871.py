'''
Less than X

https://www.acmicpc.net/problem/10871
'''

N, X = map(int, input().split())
A = list( map(int, input().split()) )
temp = ""
for i in A:
    if i < X:
        temp += str(i) + " "
print(temp[:-1])
