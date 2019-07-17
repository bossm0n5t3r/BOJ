'''
CETVRTA

https://www.acmicpc.net/problem/3009
'''


def sol():
    x = []
    y = []
    for i in range(3):
        tmp_x, tmp_y = map(int, input().split())
        if tmp_x in x:
            x.remove(tmp_x)
        else:
            x.append(tmp_x)
        if tmp_y in y:
            y.remove(tmp_y)
        else:
            y.append(tmp_y)
    print(x[0], y[0])


if __name__ == "__main__":
    sol()
