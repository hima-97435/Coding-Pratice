class Solution:
    # len(s)+#+s
    def encode(self, strs: List[str]) -> str:
        encoded_string=""
        for s in strs:
            encoded_string+=str(len(s))
            encoded_string+="#"
            encoded_string+=s
        print(encoded_string)
        return encoded_string

    def decode(self, s: str) -> List[str]:
        decoded=[]
        n=len(s)
        i=0
        while i<n:
            j=i
            while i<n and s[j].isdigit():
                j+=1
            # print(j)
            length =int(s[i:j])
            st = s[j+1: j+1+length]
            decoded.append(st)
            i=j+1+length
        return decoded