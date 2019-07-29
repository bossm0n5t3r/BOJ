def sol():
    first = list(input())
    second = list(input())
    common = 0
    for i in first:
        if i in second:
            common += 1
            second.remove(i)
    print(len(first) + len(second) - common)


if __name__ == "__main__":
    sol()
