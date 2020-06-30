"""
is subsequence

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
"""

from typing import *

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0: return True
        i = 0
        j = 0
        c = s[j]
        while i < len(t):
            if t[i] == c:
                j += 1
                if j >= len(s): return True
                c = s[j]
            i += 1
        return False
