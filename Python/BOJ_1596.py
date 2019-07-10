'''
Yeongsik function

https://www.acmicpc.net/problem/1596
'''


def sol():
    a, b = map(int, input().split())
    


def F(n):
    '''
    input: string
    output: string
    '''
    length = len(n)
    result = ""
    for i in range(length - 1):
        number = abs(int(n[i + 1]) - int(n[i]))
        result += str(number)
    return str(int(result))


def all_lucky_numbers():
    '''
    output: True / False list
    '''
    result = [False] * 1000000001
    result[7] = True
    for i in range(1000000001):
        if result[F(i)]:
            result[i] = True
    return result


if __name__ == "__main__":
    sol()
