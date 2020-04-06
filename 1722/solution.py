def sol():
    N = int(input())
    input_arr = list(map(int, input().split()))
    arr = [i for i in range(1, N + 1)]
    divide_arr = [1]
    for i in range(1, N):
        divide_arr.insert(0, i * divide_arr[0])
    idx = 0
    if input_arr[0] == 1:
        answer = []
        k = input_arr[1] - 1
        while k > 0:
            answer.append(arr[k // divide_arr[idx]])
            arr.pop(k // divide_arr[idx])
            k %= divide_arr[idx]
            idx += 1
        answer += arr
        print(" ".join(map(str, answer)))
    elif input_arr[0] == 2:
        answer = 1
        tmp_arr = input_arr[1:]
        for i in tmp_arr[:-1]:
            answer += arr.index(i) * divide_arr[idx]
            arr.pop(arr.index(i))
            idx += 1
        print(answer)


if __name__ == "__main__":
    sol()
