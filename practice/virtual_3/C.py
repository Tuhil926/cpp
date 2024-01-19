x, b = input().split()
b = int(b)

num_commas = 0

if x == "0" and b == 0:
    print(0)
    exit(0)

last_possible = 0
pow_10 = 1
i = len(x) - 1
last_possible_char = i + 1
while i >= 0:
    if b == 0:
        print("NO WAY")
        exit(0)
    if x[i] == "0":
        if pow_10 * 10 + last_possible <= b:
            i -= 1
        else:
            # print(last_possible)
            num_commas += 1
            b = last_possible
            i = last_possible_char - 1
            last_possible = 0
            pow_10 = 1
            continue

    elif pow_10 * int(x[i]) + last_possible <= b:
        last_possible_char = i
        last_possible = pow_10 * int(x[i]) + last_possible
        i -= 1
    else:
        # print(last_possible)
        num_commas += 1
        b = last_possible
        i = last_possible_char - 1
        last_possible = 0
        pow_10 = 1
        continue
    pow_10 *= 10

print(num_commas)
