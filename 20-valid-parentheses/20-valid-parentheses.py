class Solution:
    def isValid(self, st: str) -> bool:
        res = []
        for s in st:
            if s in ['(','{','[']:
                res.append(s)
            elif len(res)==0:
                return False
            elif s==')' and res[-1]=='(':
                res.pop()
            elif s=='}' and res[-1]=='{':
                res.pop()
            elif s==']' and res[-1]=='[':
                res.pop()
            else:
                return False
        if len(res)==0:
            return True
        return False
        