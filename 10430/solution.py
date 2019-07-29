def sol():
    a, b, c = map(int, input().split())
    print( (a+b)%c )
    print( ( (a%c) + (b%c) )%c )
    print( (a*b)%c )
    print( ( (a%c) * (b%c) )%c )


if __name__ == "__main__":
    sol()
