"""
maximum subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
"""

from typing import *

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        b = 0
        curr = 0
        for x in nums:
            curr = max(0, curr+x) 
            b = max(b, curr)
        if b == 0:
            return max(nums)
        return b
