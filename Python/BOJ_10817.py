'''
The second largest number

https://www.acmicpc.net/problem/10817
'''

temp = list( map(int, input().split()) )
temp.sort()
print(temp[1])
