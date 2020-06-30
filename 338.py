"""
counting bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
"""
from typing import *

class Solution:
    def countBits(self, num: int) -> List[int]:
        if num == 0: return [0]
        B = [0, 1]
        if num == 1: return B
        for i in range(2, num+1):
            B.append(B[i>>1] + (i&1))
        return B
