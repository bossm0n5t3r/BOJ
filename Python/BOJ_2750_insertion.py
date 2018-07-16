"""
Sorting numbers
Using Insertion Sort

https://www.acmicpc.net/problem/2750
"""


def sol():
    data = []
    for _ in range(int(input())):
        data.append(int(input()))
    insertion(data)
    return data


def insertion(data):
    index = 1
    while index < len(data):
        index_data = data[index]
        temp = index - 1
        while temp >= 0 and data[temp] > index_data:
            data[temp+1] = data[temp]
            temp -= 1
        data[temp + 1] = index_data
        index += 1
    return data


if __name__ == "__main__":
    for i in sol():
        print(i)
