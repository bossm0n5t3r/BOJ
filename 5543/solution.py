def sol():
    hamburger = [int(input()) for i in range(3)]
    beverage = [int(input()) for i in range(2)]
    print(min(hamburger) + min(beverage) - 50)


if __name__ == "__main__":
    sol()
