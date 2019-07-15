'''
Maximum

https://www.acmicpc.net/problem/2562
'''


def sol():
    tmp = [int(input()) for i in range(9)]
    print(max(tmp))
    print(tmp.index(max(tmp)) + 1)


if __name__ == "__main__":
    sol()
