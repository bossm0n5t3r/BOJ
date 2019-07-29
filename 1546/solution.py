def sol():
    N = int(input())
    temp = list( map(int, input().split()) )
    maxValue = max(temp)
    length = len(temp)
    for i in range(length):
        temp[i] = temp[i] / maxValue * 100
    sum = 0
    for i in temp:
        sum += i
    print("%0.2f" % (sum / length))


if __name__ == "__main__":
    sol()
