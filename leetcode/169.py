"""
majority element

find the element that appears more than n//2 times in an array of size n
"""
from typing import *
from collections import Counter

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = Counter(nums)
        for c in d:
            if d[c] > len(nums)//2:
                return c
