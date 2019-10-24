def sol():
    N = int(input())
    save = {-1: 1, 0: 0, 1: 1}
    print(fibonacci(N, save))


def fibonacci(n, save):
    if n not in save:
        save[n] = fibonacci(n - 1, save) + fibonacci(n - 2, save)
    return save[n]


if __name__ == "__main__":
    sol()
