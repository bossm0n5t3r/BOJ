def sol():
    x = int(input())
    count = 1
    while count < x:
        x -= count
        count += 1
    if count % 2 == 1:
        print('%d/%d' % (count - x + 1, x))
    else:
        print('%d/%d' % (x, count - x + 1))


if __name__ == "__main__":
    sol()
