from sys import stdin


def sol():
    N = int(input())
    members = [[] for _ in range(201)]
    for i in range(N):
        age, name = stdin.readline().rstrip().split()
        members[int(age)].append(age + " " + name)
    for member in members:
        for e in member:
            print(e)


if __name__ == "__main__":
    sol()
