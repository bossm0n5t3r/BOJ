'''
Bulky body

https://www.acmicpc.net/problem/7568
'''


def sol():
    N = int(input())
    people = []
    rank = [1] * N
    for i in range(N):
        people.append(list(map(int, input().split())))
    for i in range(N):
        for j in range(N):
            if i != j and people[i][0] < people[j][0] and people[i][1] < people[j][1]:
                rank[i] += 1
    print(" ".join(map(str, rank)))


if __name__ == "__main__":
    sol()
