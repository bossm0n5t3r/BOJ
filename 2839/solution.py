def sol():
    n = int(input())
    # 2000 is a upperbound of answer
    # 5001 is a maximum of input
    save = [2000] * (5001)
    save[3], save[5] = 1, 1
    for i in range(6, n + 1):
        save[i] = min(save[i - 3], save[i - 5]) + 1
    print(save[n] < 2000 and save[n] or -1)


if __name__ == "__main__":
    sol()
