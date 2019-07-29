def sol():
    N = int(input())
    factorial = 1
    for i in range(1, N + 1):
        factorial *= i
    print(factorial)


if __name__ == "__main__":
    sol()
