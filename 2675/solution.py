def sol():
    for i in range(int(input())):
        R, S = input().split()
        print("".join([i * int(R) for i in S]))


if __name__ == "__main__":
    sol()
