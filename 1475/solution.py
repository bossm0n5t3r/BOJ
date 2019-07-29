def sol():
    save = [0 for _ in range(9)]
    for i in input().replace("9", "6"):
        save[int(i)] += 1
    save[6] = (save[6] + 1) // 2
    print(max(save))


if __name__ == "__main__":
    sol()
