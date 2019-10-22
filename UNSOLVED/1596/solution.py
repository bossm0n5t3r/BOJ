def sol():
    A, B = map(int, input().split(" "))
    basis = [7, 18, 29, 70, 81, 92]
    count = 0
    for i in range(A, B):
        ys = ys_func(basis, i)
        if ys in basis:
            basis.append(i)
            count += 1
    print(count)


def ys_func(basis, n):
    tmp = str(n)
    if len(tmp) == 1 or len(tmp) == 2:
        return n
    result = ""
    for i in range(len(tmp) - 1):
        result += str(abs(int(tmp[i]) - int(tmp[i + 1])))
    if int(result) not in basis and len(result) > 2:
        return ys_func(basis, int(result))
    return int(result)


if __name__ == "__main__":
    sol()
