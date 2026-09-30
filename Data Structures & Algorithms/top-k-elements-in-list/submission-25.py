import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        for n  in nums:
            if n not in mp:
                mp[n]=0
            mp[n]+=1
        
        heap = []
        for num,freq in mp.items():
            # print(key)
            # print(v)
            heapq.heappush(heap,(freq,num))
            if len(heap)>k:
                heapq.heappop(heap)
        ans=[]
        for freq,num in heap:
            ans.append(num)
        return ans