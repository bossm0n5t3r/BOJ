def sol():
    N, B = map(int, input().split())
    print(base_B(N, B))


def base_B(N, B):
    result = ""
    while N:
        remain = N % B
        if 10 <= remain <= 35:
            result = chr(remain - 10 + 65) + result
        else:
            result = str(remain) + result
        N //= B
    return result


if __name__ == "__main__":
    sol()
