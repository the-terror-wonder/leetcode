class Solution:
    def largestGoodInteger(self, num: str) -> str:
        for d in "9876543210": 
            triple = d * 3
            if triple in num:
                return triple
        return ""
