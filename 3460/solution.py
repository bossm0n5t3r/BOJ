def sol():
    T = int(input())
    while T:
        T -= 1
        n = int(input())
        index = 0
        while n:
            if n % 2 == 1:
                print(str(index), end=" ")
            n //= 2
            index += 1


if __name__ == "__main__":
    sol()
