def sol():
    N = int(input())
    temp = ""
    while N > 0:
        print(temp + "*" * N)
        temp += " "
        N -= 1


if __name__ == "__main__":
    sol()
