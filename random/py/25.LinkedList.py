

class node():
    def __init__(self,value):
        self.val = value
        self.next = None

s = node(0)
t = node(1)
s.next = t

t = s 
while(t):
    print(t.val)
    t = t.next 

#python "F:\cpp\random\py\25.LinkedList.py"