def sol():
    count = 0
    for i in range(int(input())):
        word = input()
        if list(word) == sorted(word, key = word.find):
                count += 1
    print(count)


if __name__ == "__main__":
    sol()
