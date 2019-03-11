"""
AUTORI

https://www.acmicpc.net/problem/2902
"""


def sol():
    txt = input().split('-')
    result = ''
    for e in txt:
        result += e[0]
    print(result)


if __name__ == "__main__":
    sol()
