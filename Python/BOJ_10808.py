"""
Alphabet Count

https://www.acmicpc.net/problem/10808
"""


def sol():
    S = input()
    for i in range(26):
        print(S.count(chr(i + 97)), end=' ')


if __name__ == "__main__":
    sol()

