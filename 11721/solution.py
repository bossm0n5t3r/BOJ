def sol():
    string = input()
    length = len(string)
    while length > 9:
        print(string[:10])
        string = string[10:]
        length = len(string)
    print(string)


if __name__ == "__main__":
    sol()
