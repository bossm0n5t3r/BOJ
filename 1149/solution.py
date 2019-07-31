import sys
sys.setrecursionlimit(100000)


def sol(N, houses):
    save = {1 : []}
    paint(N, save, houses)
    return min(save[N])


'''
def sol(N, houses):
    R, G, B = 0, 0, 0
    for house in houses:
        R, G, B = min(G, B) + house[0], min(B, R) + house[1], min(R, G) + house[2]
    return min(R, G, B)
'''


def paint(n, save, houses):
    if n == 1:
        save[n].append(houses[n][0])
        save[n].append(houses[n][1])
        save[n].append(houses[n][2])
    if n not in save:
        save[n] = []
        save[n].append(houses[n][0] + min(paint(n - 1, save, houses)[1], paint(n - 1, save, houses)[2]))
        save[n].append(houses[n][1] + min(paint(n - 1, save, houses)[2], paint(n - 1, save, houses)[0]))
        save[n].append(houses[n][2] + min(paint(n - 1, save, houses)[0], paint(n - 1, save, houses)[1]))
    return save[n]


if __name__ == "__main__":
    input = sys.stdin.readline
    N = int(input())
    houses = [[0, 0, 0]]
    for i in range(N):
        houses.append(list(map(int, input().split())))
    print(sol(N, houses))
