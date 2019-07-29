def sol():
    A, B, V = map(int, input().split())
    print( ((V - A - 1) // (A - B)) + 2 )


if __name__ == "__main__":
    sol()
