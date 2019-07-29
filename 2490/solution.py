def sol():
    N = 3
    mal = ['E', 'A', 'B', 'C', 'D']
    while N:
        N -= 1
        yut = list(map(int, input().split()))
        num_of_zero = yut.count(0)
        print(mal[num_of_zero])


if __name__ == "__main__":
    sol()
