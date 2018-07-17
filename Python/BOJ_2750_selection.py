"""
Sorting numbers
Using Selection Sort

https://www.acmicpc.net/problem/2750
"""


def sol():
    data = []
    for _ in range(int(input())):
        data.append(int(input()))
    selection(data)
    return data


def selection(data):
    for index in range(len(data)):
        index_min = index
        for compare_index in range(index, len(data)):
            if data[index_min] > data[compare_index]:
                index_min = compare_index
        if index_min != index:
            temp = data[index]
            data[index] = data[index_min]
            data[index_min] = temp


if __name__ == "__main__":
    for i in sol():
        print(i)
