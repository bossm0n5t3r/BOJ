def sol():
    N = int(input())
    string = input()
    count = 0
    while N > 0:
        count += int(string[N - 1])
        N -= 1
    print(count)


if __name__ == "__main__":
    sol()
