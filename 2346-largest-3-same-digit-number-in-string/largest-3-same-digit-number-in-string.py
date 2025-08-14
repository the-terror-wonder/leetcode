class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num)
        if num.find("999") != -1:
            return "999"
        elif num.find("888") != -1:
            return "888"
        elif num.find("777") != -1:
            return "777"
        elif num.find("666") != -1:
            return "666"
        elif num.find("555") != -1:
            return "555"
        elif num.find("444") != -1:
            return "444"
        elif num.find("333") != -1:
            return "333"
        elif num.find("222") != -1:
            return "222"
        elif num.find("111") != -1:
            return "111"
        elif num.find("000") != -1:
            return "000"
        return ""
