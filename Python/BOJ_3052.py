'''
Remainder

https://www.acmicpc.net/problem/3052
'''


def sol():
    print(len(set( [int(input()) % 42 for i in range(10)] )))


if __name__ == "__main__":
    sol()
