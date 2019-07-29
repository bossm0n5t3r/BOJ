def sol():
    T = int(input())
    for i in range(T):
        a, b = map(int, input().split())
        print("Case #" + str(i + 1) + ": " + str(a + b))


if __name__ == "__main__":
    sol()
