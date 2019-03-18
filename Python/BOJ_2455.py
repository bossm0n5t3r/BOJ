"""
An intelligent train

https://www.acmicpc.net/problem/2455
"""


def sol():
    train = 0
    MAX = 0
    station = 1
    while station <= 4:
        get_off, get_on = map(int, input().split())
        train = train - get_off + get_on
        if MAX < train:
            MAX = train
        station += 1
    print(MAX)


if __name__ == "__main__":
    sol()
