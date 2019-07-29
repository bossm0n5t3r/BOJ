def sol():
    n = int(input())
    n = n - 1
    ans = [[1, 0], [0, 1]]
    fibonacci_matrix = [[1, 1], [1, 0]]
    while n > 0:
        if n % 2 == 1:
            ans = matrix_mul(ans, fibonacci_matrix)
        fibonacci_matrix = matrix_mul(fibonacci_matrix, fibonacci_matrix)
        n = n // 2
    print(ans[0][0])


def matrix_mul(mat1, mat2):
    result = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                result[i][j] = (result[i][j] + mat1[i][k] * mat2[k][j]) % 1000000
    return result


if __name__ == "__main__":
    sol()
