'''
Studying words

https://www.acmicpc.net/problem/1157
'''

word = input().upper()
count = [0] * 26
for i in range(26):
    count[i] = word.count(chr(i + 65))
print(count.count(max(count)) > 1 and "?" or chr(count.index(max(count)) + 65))
