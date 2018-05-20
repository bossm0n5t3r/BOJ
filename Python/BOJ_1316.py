'''
Group word Checker

https://www.acmicpc.net/problem/1316
'''

count = 0
for i in range(int(input())):
    word = input()
    if list(word) == sorted(word, key = word.find):
        count += 1
print(count)
