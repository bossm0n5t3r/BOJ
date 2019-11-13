def sol():
    N, B = map(int, input().split(" "))
    matrix = []
    for i in range(N):
        matrix.append(list(map(int, input().split(" "))))
    result = identity_matrix(N)
    while B > 0:
        if B % 2 == 0:
            matrix = matrix_mul(matrix, matrix)
            B //= 2
        else:
            result = matrix_mul(result, matrix)
            B -= 1
    for i in range(N):
        print(" ".join(map(str, result[i])))


def matrix_mul(matrix1, matrix2):
    N = len(matrix1)
    result = [[0 for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
            result[i][j] %= 1000
    return result


def identity_matrix(N):
    result = [[0 for j in range(N)] for i in range(N)]
    for i in range(N):
        result[i][i] = 1
    return result


if __name__ == "__main__":
    sol()
