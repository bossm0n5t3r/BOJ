def sol():
    abcd = sorted(list(map(int, input().split())))
    print(abcd[0] * abcd[-2])


if __name__ == "__main__":
    sol()
