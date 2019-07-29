def sol():
    croatia = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
    s = input()
    for i in croatia:
        s = s.replace(i, "0")
    print(len(s))


if __name__ == "__main__":
    sol()
