def matrixElementsSum(matrix):
    sum = 0
    ghost_room = {}
    for j in range(len(matrix)):
        for i in range(len(matrix[0])):
            if i not in ghost_room.keys():
                if matrix[j][i] != 0:
                    sum += matrix[j][i]
                else:
                    if matrix[j][i] == 0:
                        if i not in ghost_room.keys():
                            ghost_room[i] = 'Yes'


    return sum

matrix =  [[0,1,1,2],
           [0,5,0,0],
           [2,0,3,3]]

print matrixElementsSum(matrix)