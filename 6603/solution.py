def sol():
    while True:
        input_data = list(map(int, input().split(" ")))
        k = input_data[0]
        arr = input_data[1:]
        if k == 0:
            break
        visited = [False] * k
        combination(arr, visited, 0, k, 6)
        print()


def combination(arr, visited, start, end, r):
    if r == 0:
        for i in range(end):
            if visited[i]:
                print(arr[i], end=" ")
        print()
    for i in range(start, end):
        visited[i] = True
        combination(arr, visited, i + 1, end, r - 1)
        visited[i] = False


if __name__ == "__main__":
    sol()
