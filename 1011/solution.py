import math


def sol():
    T = int(input())
    for i in range(T):
        x, y = map(int, input().split())
        dist = y - x
        check = int(math.sqrt(dist))
        if dist - pow(check, 2) > check:
            print(2 * check + 1)
        elif dist - pow(check, 2) > 0:
            print(2 * check)
        else:
            print(2 * check - 1)


if __name__ == "__main__":
    sol()
