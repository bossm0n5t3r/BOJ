'''
LJESNJAK

https://www.acmicpc.net/problem/2941
'''

croatia = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
s = input()
for i in croatia:
    s = s.replace(i, "0")
print(len(s))
