'''
NOTE

https://www.acmicpc.net/problem/2920
'''

temp = list( map( int, input().split() ) )

diff = []

for i in range(len(temp) - 1):
    diff.append(temp[i+1] - temp[i])

if len(set(diff)) != 1:
    print("mixed")
elif diff[0] == 1:
    print("ascending")
else:
    print("descending")
