from Queue import Queue

class Vertex:
    def __init__(self, key):
        self.id = key
        self.neighbors = {}
        self.distance = 1
        self.color = 'white'
        self.Predes = 'None'

    def setdistance(self, distance):
        self.distance = distance

    def setPredes(self, pred):
        self.Predes = pred

    def getPredes(self):
        return self.Predes

    def getdistance(self):
        return self.distance

    def getColor(self):
        return self.color

    def setcolor(self, color):
        self.color = color

    def addNeighbor(self, nbr, weight=0):
        self.neighbors[nbr] = weight

    def __str__(self):
        return str(self.id) + "Connected to" + str([x.id for x in self.neighbors])

    def getId(self):
        return self.id

    def getWeight(self, key):
        return self.neighbors[key]

    def getNeighbors(self):
        return self.neighbors.keys()


class Graph:
    def __init__(self):
        self.vertexList = {}
        self.numVertices = 0

    def addVertex(self, key):
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.vertexList[key] = newVertex
        return newVertex

    def getVertex(self, n):
        if n in self.vertexList:
            return self.vertexList[n]
        else:
            None

    def __contains__(self, n):
        return n in self.vertexList

    def addEdge(self, t, f, cost=0):
        if t not in self.vertexList:
            self.addVertex(t)
        if f not in self.vertexList:
            self.addVertex(f)
        self.vertexList[f].addNeighbor(self.vertexList[t], cost)

    def getVertices(self):
        return self.vertexList.keys()

    def __iter__(self):
        return iter(self.vertexList.values())


def buildGraph(wordList):
    d = {}
    g = Graph()

    for word in wordList:
        for i in range(len(word)):
            bucket = word[:i] + '_' + word[i + 1:]
            if bucket in d:
                d[bucket].append(word)
            else:
                d[bucket] = [word]

    for v in d.keys():
        for word1 in d[v]:
            for word2 in d[v]:
                if word1 != word2:
                    g.addEdge(word1, word2)

    return g


def wordLadder(beginWord, endWord, wordList):
    g = buildGraph(wordList)
    start_vertex = g.getVertex(beginWord)
    vertQueue = Queue()
    vertQueue.put(start_vertex)
    while vertQueue.qsize() > 0:
        curr = vertQueue.get()
        for n in curr.getNeighbors():
            if n.getColor() == 'white':
                if n == g.getVertex(endWord):
                    return curr.getdistance() + 1
                n.setcolor('gray')
                n.setdistance(curr.getdistance() + 1)
                n.setPredes(curr)
                vertQueue.put(n)

        curr.setcolor('black')
    return 0

#wordList = ["hot", "hit", "dot", "dog", "lot", "log", "cog"]
wordList = ["hot", "dog"]

print "Length: ", wordLadder(wordList[0], wordList[-1], wordList)