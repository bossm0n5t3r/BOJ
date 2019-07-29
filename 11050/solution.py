def sol():
    N, K = map(int, input().split())
    print(binomial_coefficient(N, K))


def binomial_coefficient(n, k):
    if k == 0:
        return 1
    if n == k:
        return 1
    if k == 1:
        return n
    if k == (n - 1):
        return n
    return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k)


if __name__ == "__main__":
    sol()
