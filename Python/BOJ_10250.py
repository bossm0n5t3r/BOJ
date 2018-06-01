'''
ACM Hotel

https://www.acmicpc.net/problem/10250
'''

T = int(input())
for _ in range(T):
    H, W, N = map(int, input().split())
    print(100 * ((N-1)%H + 1) + (N-1)//H + 1)
