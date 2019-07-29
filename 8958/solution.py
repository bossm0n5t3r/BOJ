def sol():
    N = int(input())
    for i in range(N):
        sum = 0
        for i in map(len, input().split("X")):
            sum += i * (i+1) // 2
        print(sum)


if __name__ == "__main__":
    sol()
