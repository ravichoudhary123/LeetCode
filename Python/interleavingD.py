def isInterleaving(str1, str2, str3):
    result = [[False]*(len(str1)+1) for i in range(len(str2)+1)]
    for j in range(len(str1)+1):
        if j == 0:
            result[0][j] = True;
        else:
            if str1[j-1] == str3[j-1]:
                result[0][j] = result[0][j-1]
            else:
                result[0][j] = False
    for j in range(len(str1)+1):
        if j == 0:
            result[0][j] = True;
        else:
            if str2[j-1] == str3[j-1]:
                result[j][0] = result[j-1][0]
            else:
                result[j][0] = False

    for i in range(1, len(str1)+1):
        for j in range(1, len(str2)+1):
            if str3[i+j-1] == str1[j-1]:
                result[i][j] = result[i][j-1]
            elif str3[i+j-1] == str2[i-1]:
                result[i][j] = result[i-1][j]
            else:
                result[i][j] = False

    return result[len(str1)][len(str2)]

str1 = "aab"
str2 = "axy"
str3 = "aaxaby"

print "is str3 interleaving of str1 and str2: ", isInterleaving(str1,str2, str3)