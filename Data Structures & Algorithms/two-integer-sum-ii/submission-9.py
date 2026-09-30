class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        mp = { }
        for i in range(len(numbers)):
            tg = target-numbers[i]
            if tg in mp:
                return [mp[tg],i+1]
            mp[numbers[i]]=i+1
        return [-1,-1]