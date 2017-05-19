def replaceSpaces(str, truelength):
    spaceCount = 0
    index =0
    i = 0
    for i in range(truelength):
        if str[i] == ' ':
            spaceCount += 1

    index = truelength + spaceCount*2

    for j in range(truelength-1, -1, -1):
        if str[j] == ' ':
            str[j - 1] = '0'
            str[j-2] = '2'
            str[j-3] = '%'

            index = index -3
        else:
            str[index - 1] = str[j]
            index -=1

    " ".join(str)

input = "Mr John Smith   "

print replaceSpaces(list(input), len(input.rstrip()))
