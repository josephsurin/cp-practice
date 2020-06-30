"""
climbing stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
"""

from typing import *

class Solution:
    def climbStairs(self, n: int) -> int:
        F = [0, 1, 2]
        if n < 3:
            return F[n]
        for i in range(3, n):
            F.append(F[i-1] + F[i-2])
        return F[n-1] + F[n-2]
