'''
Break-even point

https://www.acmicpc.net/problem/1712
'''


def sol():
    A, B, C = map(int, input().split())
    if C <= B:
        print(-1)
        exit()
    margin = C - B
    print( (A // margin) + 1 )


if __name__ == "__main__":
    sol()
