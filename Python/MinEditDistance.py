import numpy as np
def mineditdist(str1, str2):
    temp = np.zeros(shape=(len(str1)+1, len(str2)+1))
    for j in range(temp.shape[1]):
        i = 0
        if j != 0:
            temp[i][j] = temp[i][j - 1] + 1

    for i in range(temp.shape[0]):
        j = 0
        if i != 0:
            temp[i][j] = temp[i-1][j] + 1

    for i in np.arange(1, len(str1)+1):
        for j in np.arange(1, len(str2)+1):
            if str1[i-1] == str2[j-1]:
                temp[i][j] = temp[i-1][j-1]
            else:
                temp[i][j] = min(temp[i-1][j-1], temp[i][j-1], temp[i-1][j]) + 1

    print temp
    return temp

string1 = "azced"
string2 = "abcdef"

result = mineditdist(string1, string2)