def longestPalindrome(s):
    """
    :type s: str
    :rtype: str
    """
    longestPalind = 0
    length = len(s)
    T = [[False] * length for i in range(length)]

    # First initialize diagnal element
    for i in range(length):
        T[i][i] = True
        longestPalind = 1
        longpal = s[i]

    k = 0
    # Initialize table for
    for i in range(1, length):
        if s[k] == s[i]:
            T[k][i] = True
            longestPalind = 2
            longpal = s[k:i + 1]
        k += 1

    for count in range(2, length):
        for i in range(length - count):
            if s[i] == s[count+i] and T[i + 1][count + i - 1]:
                T[i][count+i] = True
                longpal = s[i:count +i+ 1]
                longestPalind = count + i + 1

    return longpal

input1 = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"

print longestPalindrome(input1)
