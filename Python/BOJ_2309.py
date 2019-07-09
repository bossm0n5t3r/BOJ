"""
Seven Dwarfs

https://www.acmicpc.net/problem/2309
"""


def sol():
    dwarfs = [int(input()) for i in range(9)]
    dwarfs.sort()
    all_dwarfs = sum(dwarfs)
    for i in range(8):
        check = False
        for j in range(i + 1, 9):
            if all_dwarfs - dwarfs[i] - dwarfs[j] == 100:
                for k in range(9):
                    if k not in [i, j]:
                        print(dwarfs[k])
                check = True
                break
        if check:
            break


if __name__ == "__main__":
    sol()
