class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp={}
        for s in strs:
            k=s
            k=''.join(sorted(s))
            if k not in mp:
                mp[k]=[]
            mp[k].append(s)
        ans=[]
        for t in mp:
            ans.append(mp[t])
        return ans