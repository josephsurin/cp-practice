"""
longest palindromic substring

given a string s, find the longest palindromic substring in s
"""

from typing import *

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 0: return ''
        dp = [[0 for _ in range(n)] for _ in range(n)]
        ans = ''
        best = 0
        for j in range(0, n):
            for i in range(0, j+1):
                same = s[i] == s[j]
                if j - i <= 2:
                    dp[i][j] = same
                else:
                    dp[i][j] = same and dp[i+1][j-1]

                if dp[i][j] and j - i + 1 > best:
                    best = j - i + 1
                    ans = s[i:j+1]
        return ans
