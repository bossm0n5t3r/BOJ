def sol():
    N = int(input())
    cnt_of_2 = 0
    cnt_of_5 = 0
    while N > 0:
        copy_of_N = N
        while copy_of_N % 2 == 0:
            cnt_of_2 += 1
            copy_of_N //= 2
        while copy_of_N % 5 == 0:
            cnt_of_5 += 1
            copy_of_N //= 5
        N -= 1
    print(min(cnt_of_2, cnt_of_5))


if __name__ == "__main__":
    sol()
