"""
Verification number

https://www.acmicpc.net/problem/2475
"""


def sol():
    num = [int(i) ** 2 for i in input().split()]
    verify = sum(num) % 10
    print(verify)


if __name__ == "__main__":
    sol()
