def sol():
    A, B = map(int, input().split())
    if A > B:
        print(">")
    elif A < B:
        print("<")
    else:
        print("==")


if __name__ == "__main__":
    sol()
