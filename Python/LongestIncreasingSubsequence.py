def lis(arr):
    temp = [1] * len(arr)
    i = 1
    j = 0
    while i < len(arr):
        if arr[j] < arr[i]:
            temp[i] = max(temp[i], temp[j] + 1)
            j += 1
        elif j == i:
            i += 1
            j = 0
        else:
            j += 1

    return max(temp)

arr = [3, 4, -1, 0, 6, 2, 3]
length_long = lis(arr)
print length_long