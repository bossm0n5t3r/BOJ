'''
Find Alphabet

https://www.acmicpc.net/problem/10809
'''

S = input()
save = [-1] * 26
for i in range(len(S)):
    if save[ord(S[i]) - 97] == -1:
        save[ord(S[i]) - 97] = i
print(" ".join([str(i) for i in save]))
