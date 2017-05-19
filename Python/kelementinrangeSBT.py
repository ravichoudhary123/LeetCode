# -*- coding: utf-8 -*-
"""
Created on Mon Apr 10 23:29:14 2017

@author: ravi
"""

class Node:
    def __init__(self, count, data, left = None, right = None, parent = None):
        self.data = data
        self.count = count
        self.left = left
        self.right = right
        self.parent = parent
        
    def setCount(self, count):
        self.count = count
        
    def getCount(self):
        return self.count
    
    def getData(self):
        return self.data
    
    def hasleftChild(self):
        return self.left
    
    def hasrightChild(self):
        return self.right
    
    def isleft(self):
        return self.parent and self.parent.left == self
    
    def isright(self):
        return self.parent and self.parent.right == self
    
    def hasanychildre(self):
        return self.left or self.right
    
    def isLeaf(self):
        return not (self.left or self.right)
    
    def hasbothchildren(self):
        return self.left and self.right
    
    
    
class BSTree:
    def __init__(self):
        self.root = None
        self.size = 0
    
    def length(self):
        return self.size
    
    def __len__(self):
        return self.size
    
    def __iter__(self):
        return self.root.__iter__()
    
    def put(self, count, data):
        if self.root:
            self._put(self, count, data, self.root)
        else:
            self.root = Node(count, data)

        self.size += 1
        
        return self.root
    
    def _put(self, count, data, currentNode):
        if data < currentNode.data:
            if currentNode.hasleftChild():
                self._put(self, count, data, currentNode.left)
            else:
                currentNode.left = Node(count, data, parent = currentNode)
        else:
            if currentNode.hasrightChild():
                self._put(self, count, data, currentNode.right)
            else:
                currentNode.right = Node(count, data, parent=currentNode)
    
    def __setitem__(self, k, v):
        self._put(k,v)
        
    