def sol():
    n = int(input())
    save = [0] * (n + 1)
    save[1] = 1
    if n > 1:
        save[2] = 2
    for i in range(3, n + 1):
        save[i] = (save[i - 1] + save[i - 2]) % 10007
    print(save[n])


if __name__ == "__main__":
    sol()
