"""
min cost climbing stairs

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1
"""
from typing import *

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        if n == 1:
            return 0
        if n <= 3:
            return min(cost[0], cost[1])
        K = [0 for _ in range(n+1)]
        for i in range(2, n+1):
            K[i] = min(K[i-1] + cost[i-1], K[i-2] + cost[i-2])
        return K[n]
