def log2(n):
    res = 0
    while n > 0:
        n = n // 2
        res += 1
    return res


def is_pow_2(n):
    num = 1
    while num < n:
        num *= 2
    if num == n:
        return True
    else:
        return False


n, k = [int(x) for x in input().split()]

if k == 1:
    print("1")
elif log2(n) > k:
    pow_2 = 2
    num = 0
    for i in range(k - 1):
        num += pow_2
        pow_2 *= 2
        if num > n:
            num = n - 1
            break

    print(num)
else:
    start = n
    pow_2 = 2
    num_child = 1
    while num_child - 1 < n - k:
        if start % 2 == 1:
            num_child += pow_2
        else:
            num_child += pow_2 // 2
        pow_2 *= 2
        start = start // 2

    if num_child - 1 == n - k:
        if is_pow_2(num_child + 1):
            l = 1
            start -= 1
            while l * 2 <= start:
                l *= 2
        else:
            start -= 1

    print(n - start)
