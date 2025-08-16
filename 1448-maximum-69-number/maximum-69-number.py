class Solution:
    def maximum69Number (self, num: int) -> int:
        temp = num
        add=0
        curr=0
        while temp > 0 :
            if temp%10 == 6 :
                add= 3 * int(math.pow(10,curr))
            curr+=1
            temp//=10
            # print(add)

        return num + int(add)

        