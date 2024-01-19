num_sub = [2**x - 1 for x in range(67)]
for i in range(int(input())):
    X = int(input()) - 1
    output = []
    i = 65
    while i > 0:
        if X >= num_sub[i]:
            X -= num_sub[i]
            for j in range(i):
                output.append(j)
            break
        else:
            i -= 1
    while X > 0:
        if X >= num_sub[i] + 1:
            X -= num_sub[i] + 1
            output.append(i)
        else:
            i -= 1
    if len(output) > 200:
        print(-1)
        continue
    print(len(output))
    for num in output:
        print(num, end=" ")
    print()
