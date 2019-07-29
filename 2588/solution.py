def sol():
    a = input()
    b = input()
    for i in range(3):
        print( int(a) * int(b[2 - i]) )
    print(int(a) * int(b))


if __name__ == "__main__":
    sol()
