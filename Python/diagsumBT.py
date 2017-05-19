# -*- coding: utf-8 -*-
"""
Created on Tue Apr 11 09:14:29 2017

@author: ravi
"""
class Node:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

def diagsumBT(root, currentDiag, diagSumHash):
    if root == None:
        return None

    diagsumBT(root.left, currentDiag + 1, diagSumHash)
    
    prevSum = 0
    
    if(diagSumHash.get(currentDiag, 0) != 0):
        prevSum = diagSumHash.get(currentDiag, 0)
    
    diagSumHash[currentDiag] = prevSum + root.data
    
    diagsumBT(root.right, currentDiag, diagSumHash)
    
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.left.right.left = Node(8)
root.right.right = Node(6)
root.right.right.left = Node(7)

diagSum = {}

diagsumBT(root, 0, diagSum)

for key, data in diagSum.iteritems():
    print "Diagonal Sum on ", key, "Diag:", data