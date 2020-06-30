"""
minimum cost for tickets

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

    a 1-day pass is sold for costs[0] dollars;
    a 7-day pass is sold for costs[1] dollars;
    a 30-day pass is sold for costs[2] dollars.

The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.
"""

from typing import *

def M(i, h, memo, costs):
    if i > 365: return 0
    if i in memo: return memo[i]
    a = -1
    if i in h:
        a = min(M(i+1, h, memo, costs)+costs[0], M(i+7, h, memo, costs)+costs[1], M(i+30, h, memo, costs)+costs[2])
    else:
        a = M(i+1, h, memo, costs)
    memo[i] = a 
    return a

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        return M(1, set(days), {}, costs)
