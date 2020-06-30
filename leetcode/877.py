"""
stone game

Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
"""

from typing import *

class Solution:
    memo = {}
    piles = None

    def stoneGame(self, piles: List[int]) -> bool:
        self.piles = piles
        return self.K(0, len(piles) - 1) > 0
    
    def K(self, i, j):
        memo = self.memo
        piles = self.piles
        K = self.K

        if i > j: return 0
        if (i, j) in memo: return memo[(i, j)]
        a = 0
        if (j - i - len(piles)) & 1:
            a = max(K(i+1, j) + piles[i], K(i, j-1) + piles[j])
        else:
            a = min(K(i+1, j) - piles[i], K(i, j-1) - piles[j])
        memo[(i, j)] = a
        return a
