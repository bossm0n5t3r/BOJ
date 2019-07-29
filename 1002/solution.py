def sol():
    T = int(input())
    for i in range(T):
        x1, y1, r1, x2, y2, r2 = map(int , input().split())
        dist = (x2 - x1) ** 2 + (y2 - y1) ** 2
        rdiff = (r1 - r2) ** 2
        radd = (r1 + r2) ** 2
        if dist == 0 and r1 == r2:
            print(-1)
        elif dist < rdiff or dist > radd:
            print(0)
        elif dist == rdiff or dist == radd:
            print(1)
        else:
            print(2)


if __name__ == "__main__":
    sol()
