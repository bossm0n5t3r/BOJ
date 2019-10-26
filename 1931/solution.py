import sys


def sol():
    input = sys.stdin.readline
    N = int(input())
    meetings = []
    for i in range(N):
        meetings.append(list(map(int, input().split(" "))))
    meetings = sorted(meetings, key=lambda x: (x[1], x[0]))
    count = 0
    last = 0
    for meeting in meetings:
        if last <= meeting[0]:
            last = meeting[1]
            count += 1
    print(count)


if __name__ == "__main__":
    sol()
