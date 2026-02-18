class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []
        digitsMapped = {
            "2" : "abc",
            "3" : "def",
            "4" : "ghi",
            "5" : "jkl",
            "6" : "mno",
            "7" : "pqrs",
            "8" : "tuv",
            "9" : "wxyz"
        }

        def backtracking(idx, currStr):
            if len(currStr) == len(digits):
                ans.append(currStr)
                return
            for c in digitsMapped[digits[idx]]:
                backtracking(idx + 1, currStr + c)
        
        if digits:
            backtracking(0, "")
        
        return ans