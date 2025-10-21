class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            value = -int(str(x)[::-1][:-1])
        else:
            value = int(str(x)[::-1])
            
        return 0 if value < -2**31 or value > 2**31 -1 else value
        