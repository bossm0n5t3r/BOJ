def sol():
    dial = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]
    time = 0
    for i in input():
        for j in range(len(dial)):
            if i in dial[j]:
                time += (j + 3)
                break
    print(time)


if __name__ == "__main__":
    sol()
