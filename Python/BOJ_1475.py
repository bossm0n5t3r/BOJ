'''
Room No.

https://www.acmicpc.net/problem/1475
'''

save = [0 for _ in range(9)]
for i in input().replace("9", "6"):
    save[int(i)] += 1
save[6] = (save[6] + 1) // 2
print(max(save))
