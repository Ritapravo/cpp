#generate parenthesis

def paren(n, li, n1=0, n2=0, tmp = ""):
    if(n1==n2 and n2 == n):
        li.append(tmp)
        return
    if(n1<n2 or n1>n or n2>n):
        return 
    paren(n, li, n1+1, n2, tmp+"(")
    paren(n, li, n1, n2+1, tmp+")")

class Solution:
    def generateParenthesis(self, n: int):
        li = []
        paren(n, li)
        return li
       
if __name__ == "__main__":
    sol = Solution()
    print(sol.generateParenthesis(3))

""" 
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 """