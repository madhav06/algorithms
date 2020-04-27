
# Uses python3
import sys


def merge(a, b, left, avg, right):
    inv_count = 0
    i, j, k = left, avg, left
    while i <= avg - 1 and j <= right:
        if a[i] <= a[j]:
            b[k] = a[i]
            i += 1
        else:
            b[k] = a[j]
            j += 1
            inv_count += avg - i
        k += 1
    while i <= avg - 1:
        b[k] = a[i]
        i += 1
        k += 1
    while j <= right:
        b[k] = a[j]
        j += 1
        k += 1
    for i in range(left, right + 1):
        a[i] = b[i]
    return inv_count


def merge_sort(a, b, left, right):
    inv_count = 0
    if right > left:
        avg = (left + right) // 2
        inv_count += merge_sort(a, b, left, avg)
        inv_count += merge_sort(a, b, avg + 1, right)

        inv_count += merge(a, b, left, avg + 1, right)

    return inv_count


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(merge_sort(a, b, 0, len(a) - 1))