"""
search in rotated sorted array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, orthwise return false.
""" 
from typing import *

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if len(nums) > 0 and nums[-1] == target:
            return True
        for i in range(len(nums)-1):
            if nums[i] == target:
                return True
            if nums[i+1] < nums[i]:
                nums = nums[i+1:] + nums[:i+1]
                break
        lo = 0 
        hi = len(nums)
        while lo < hi:
            m = (lo+hi)//2
            if nums[m] == target:
                return True
            elif nums[m] > target:
                hi = m
            else:
                lo = m + 1
        return False
