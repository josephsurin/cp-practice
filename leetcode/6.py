# zigzag conversion
# return the zigzag of a given string eg s=PAYPALISHIRING with n=3 rows
# P   A   H   N
# A P L S I I G
# Y   I   R
# return PAHNAPLSIIGYIR

from typing import *

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if len(s) == 0 or numRows == 1: return s
        l = 2 * (numRows - 1)
        o = ''
        for i in range(numRows):
            for j in range(0, len(s) - i, l):
                o += s[j+i]
                if 0 < i < numRows - 1 and j + l - i < len(s):
                    o += s[j + l - i]
        return o
