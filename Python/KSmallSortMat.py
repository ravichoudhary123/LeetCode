# -*- coding: utf-8 -*-
import heapq
matrix = [[ 1,  5,  9], [8, 11, 13], [10, 13, 15]]
k = 5

h = [(row[0], row, 1) for row in matrix]
heapq.heapify(h)
for _ in xrange(k - 1):
    v, r, i = h[0]
    if i < len(r):
        heapq.heapreplace(h, (r[i], r, i + 1))
    else:
        heapq.heappop(h)

print h[0][0]