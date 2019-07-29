def sol():
    while True:
        lengths = sorted(list(map(int, input().split())))
        if sum(lengths) == 0:
            exit()
        if lengths[0] ** 2 + lengths[1] ** 2 == lengths[2] ** 2:
            print("right")
        else:
            print("wrong")


if __name__ == "__main__":
    sol()
