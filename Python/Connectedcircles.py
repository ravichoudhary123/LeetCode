# -*- coding: utf-8 -*-
"""
Created on Mon May 15 10:38:54 2017

@author: ravi
"""

def countComponents(n, edges):
    """
    :type n: int
    :type edges: List[List[int]]
    :rtype: int
    """
    def dfs(node):
        for nei, adj in enumerate(cirmat[node]):
            if nei not in visited and adj == 1:
                visited.add(nei)
                dfs(nei)
                
                
    
    def createMat(cirmat, edges):
        for edge in edges:
            cirmat[edge[0]][edge[1]] = 1
    
    visited = set()
    count = 0
    cirmat = [[0]*n for i in xrange(n)]
    createMat(cirmat, edges)
    for i in xrange(n):
        if i not in visited:
            visited.add(i)
            dfs(i)
            count += 1

    return count
    

n = 5
edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

count = countComponents(n, edges)

print count 