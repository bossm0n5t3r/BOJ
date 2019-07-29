def sol():
    x, y, w, h = map(int, input().split())
    print(min(x, y, w - x, h - y))


if __name__ == "__main__":
    sol()
