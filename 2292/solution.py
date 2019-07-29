def sol():
    N = int(input())
    ub = pt = 1
    while ub < N:
        ub += pt * 6
        pt += 1
    print(pt)


if __name__ == "__main__":
    sol()
