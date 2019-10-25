def sol():
    L, P = map(int, input().split(" "))
    people = L * P
    data = list(map(int, input().split(" ")))
    for candidates in data:
        print(str(candidates - people), end=" ")


if __name__ == "__main__":
    sol()
