def sol():
    data = []
    for _ in range(int(input())):
        data.append(int(input()))
    quick(data, 0, len(data) - 1)
    return data


def quick(data, start, end):
    left = start
    right = end
    pivot = data[(left + right)//2]
    while left <= right:
        while data[left] < pivot:
            left += 1
        while data[right] > pivot:
            right -= 1
        if left <= right:
            temp = data[left]
            data[left] = data[right]
            data[right] = temp
            left += 1
            right -= 1
    if start < right:
        quick(data, start, right)
    if end > left:
        quick(data, left, end)


if __name__ == '__main__':
    for i in sol():
        print(i)
