# -*- coding: utf-8 -*-

def countSubstringWithEqualEnds(string):
    s_len = len(list(string))
    result = 0    
    count = [0]*26
    for c in range(s_len):
        count[ord(string[c]) - ord('a')] += 1
    
    for i in range(26):
        result +=(count[i]*(count[i]+1)/2)
        
    return result

string = raw_input()

print countSubstringWithEqualEnds(string)