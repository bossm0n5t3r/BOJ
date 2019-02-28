"""
Fibonacci function

https://www.acmicpc.net/problem/1003
"""


def sol():
    T = int(input())
    for i in range(T):
        N = int(input())
        save = {-1: 1, 0: 0, 1: 1}
        fibonacci(N, save)
        print(str(save[N - 1]) + ' ' + str(save[N]))


def fibonacci(n, save):
    if n not in save:
        save[n] = fibonacci(n - 1, save) + fibonacci(n - 2, save)
    return save[n]


if __name__ == "__main__":
    sol()
