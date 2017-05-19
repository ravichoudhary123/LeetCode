# -*- coding: utf-8 -*-

M = [[1,1,0],[1,1,0],[0,0,1]]
N = len(M)
visited = set()

def dfs(node):
    for nei, adj in enumerate(M[node]):
        if adj and nei not in visited:
            visited.add(nei)
            dfs(nei)
    
count = 0

for i in range(N):
    if i not in visited:
        dfs(i)
        count += 1

print count 