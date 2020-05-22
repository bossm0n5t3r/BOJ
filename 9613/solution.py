def sol():
    t = int(input())
    while t > 0:
        t -= 1
        nums = list(map(int, input().split()))[1:]
        result = 0
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                result += gcd(nums[i], nums[j])
        print(result)


def gcd(x, y):
    while y:
        x, y = y, x % y
    return x


if __name__ == "__main__":
    sol()
