"""
Sorting numbers
Using Bubble Sort

https://www.acmicpc.net/problem/2750
"""


def sol():
    data = []
    for _ in range(int(input())):
        data.append(int(input()))
    bubble(data)
    return data


def bubble(data):
    while True:
        flag = False
        for index in range(len(data) - 1):
            if data[index] > data[index + 1]:
                temp = data[index]
                data[index] = data[index + 1]
                data[index + 1] = temp
                flag = True
        if not flag:
            break
    return data


if __name__ == "__main__":
    for i in sol():
        print(i)
