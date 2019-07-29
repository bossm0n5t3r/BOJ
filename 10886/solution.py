import sys


def sol():
    N = int(sys.stdin.readline().rstrip())
    cute = 0
    for i in range(N):
        cute += int(sys.stdin.readline().rstrip())
    print("Junhee is cute!" if 2 * cute > N else "Junhee is not cute!")


if __name__ == "__main__":
    sol()
