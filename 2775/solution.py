def sol():
    apt = [ [_ for _ in range(15)] for _ in range(15) ]
    for i in range(15):
        apt[i][1] = 1
    for i in range(1, 15):
        for j in range(2, 15):
            apt[i][j] = apt[i-1][j] + apt[i][j-1]
    T = int(input())
    for _ in range(T):
        k = int(input())
        n = int(input())
        print(apt[k][n])


if __name__ == "__main__":
    sol()
