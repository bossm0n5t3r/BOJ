def sol():
    N, X = map(int, input().split())
    A = list(map(int, input().split()))
    temp = ""
    for i in A:
        if i < X:
            temp += str(i) + " "
    print(temp[:-1])


if __name__ == "__main__":
    sol()
