
# Uses python3


def calc_fib(n):
    if n <= 1:
        return n

    old = 0
    new = 1

    for _ in range(n - 1):
        old, new = new, old + new

    return new


n = int(input())
print(calc_fib(n))


