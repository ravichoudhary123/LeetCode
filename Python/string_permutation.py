import operator

result = []


def stringPermutations(s):
    list_s = list(s)
    d = {}
    for c in list_s:
        d[c] = list_s.count(c)
    str_count = sorted(d.iteritems(), key=operator.itemgetter(0))
    temp_result = [None] * len(s)
    permuteUtil(str_count, temp_result, 0)
    return result


def permuteUtil(str_count, res, level):
    if (level == len(res)):
        result.append(''.join(res))
        return

    for x in range(len(str_count)):
        if str_count[x][1] != 0:
            res[level] = str_count[x][0]
            y = list(str_count[x])
            y[1] -= 1
            str_count[x] = tuple(y)
            permuteUtil(str_count, res, level + 1)
            y = list(str_count[x])
            y[1] += 1
            str_count[x] = tuple(y)

print stringPermutations("ABA")