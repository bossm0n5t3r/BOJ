def sol():
    save = list(range(1,10000))
    for i in range(1, 10000):
        temp = i
        for j in str(i):
            temp += int(j)
        if temp in save:
            save.remove(temp)
    for i in save:
        print(i)


if __name__ == "__main__":
    sol()
