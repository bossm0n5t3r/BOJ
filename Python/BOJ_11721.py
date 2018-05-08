'''
Print out each 10 alphabets

https://www.acmicpc.net/problem/11721
'''

string = input()
length = len(string)
while length > 9:
    print(string[:10])
    string = string[10:]
    length = len(string)
print(string)
