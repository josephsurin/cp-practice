# sort the matrix diagonally
# given a m*n matrix of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted matrix

from typing import *

def get_diag(y, x, m, n):
    o = []
    while y < m and x < n:
        o.append((y, x))
        y += 1
        x += 1
    return o

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        # start from (0,0) and go all the way right to (0,n-1), sorting each of those diagonals
        # then do the same for the diagonals from (1,0) to (m-1,0)
        if len(mat) == 0: return []
        m = len(mat)
        n = len(mat[0])
        for x in range(n):
            d = get_diag(0, x, m, n)
            l = [mat[y][x] for y,x in d]
            l.sort()
            i = 0
            for y,x in d:
                mat[y][x] = l[i]
                i += 1
        for y in range(1, m):
            d = get_diag(y, 0, m, n)
            l = [mat[y][x] for y,x in d]
            l.sort()
            i = 0
            for y,x in d:
                mat[y][x] = l[i]
                i += 1
        return mat
