def findWords(words):
    """
    :type words: List[str]
    :rtype: List[str]
    """
    row = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]

    result = []
    for s in row:
        for word in words:
            if set(word.lower()).issubset(row):
                result.append(word)

    return result

Input = ["Hello", "Alaska", "Dad", "Peace"]

print findWords(Input)