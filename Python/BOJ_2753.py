'''
Leap year

https://www.acmicpc.net/problem/2753
'''


def sol():
    year = int(input())
    print(int( year % 400 == 0 or ( year % 4 == 0 and year % 100 != 0 )))


if __name__ == "__main__":
    sol()
