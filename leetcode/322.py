"""
coin change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
"""

from typing import *

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        M = [float('inf') for _ in range(amount+1)]
        M[0] = 0
        for i in range(amount+1):
            for c in coins:
                if c <= i:
                    M[i] = min(M[i], M[i - c] + 1) 
        return M[amount] if M[amount] != float('inf') else -1
