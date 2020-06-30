"""
best time to buy and sell stock

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
"""

from typing import *

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0: return 0
        min_price = prices[0]
        best = 0
        for i in range(len(prices)):
            min_price = min(min_price, prices[i])
            best = max(best, prices[i] - min_price)
        return best
