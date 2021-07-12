
class Recipe:
    def __init__(self, a, b, c, d, e):
        self.recipeId = a
        self.recipeName = b
        self.majorIngredients = c 
        self.recipeType = d 
        self.approxCalories = e 
    

class MyKitchen:
    def __init__(self, rlist, klist):
        self.rlist = rlist
        self.klist = klist 

    def getAvailableRecipeCount(self, rcp, rlist, klist):
        li = []
        xlist = [i.lower() for i in klist]
        c = 0
        for elem in rlist:
            if(elem.recipeType == rcp):
                ind = 0
                for i in elem.majorIngredients:
                    if i.lower() not in xlist:
                        ind = 1
                        break
                if(ind==0):
                    c += 1
        return c


    def getTwoRecipeWithLeastCalories(self, rlist, klist):
        z = rlist[:]
        z.sort(key=lambda x: x.approxCalories)
        return z[:2]






if __name__=="__main__":
    n = int(input())
    rlist = []
    for i in range(n):
        a = int(input()) #recipeId
        b = input() #recipeName
        d = input() #recipeType
        c = [] #list of string
        for i in range(3):
            c.append(input())
        e = float(input()) #calories
        temp = Recipe(a,b,c,d,e)
        rlist.append(temp)

    m = int(input())
    klist = []
    for i in range(m):
        klist.append(input())
    
    rcp = input() #string used in getAvailableRecipeCount 
    ob = MyKitchen(rlist, klist)



    ans1 = ob.getAvailableRecipeCount(rcp, rlist, klist)
    ans2 = ob.getTwoRecipeWithLeastCalories(rlist, klist)
    
    if(ans1==0):
        print("Major ingredients for given recipe type not found")
    else:
        print(ans1)
    for i in ans2:
        print(i.recipeId)
        print(i.recipeName)
        print(i.recipeType)
        print(i.approxCalories)
    

#python "F:\cpp\random\cpp\prac2.py"    

"""
3
101
abcn
vegan
wheatFlour
bakingSoda
cornFlour
45.36
102
rec2
vegan
cornFlour
riceFlour
bakingSoda
58.1
103
rec3
veg
cornFlour
riceFlour
oil
26.36
5
wheatFlour
bakingSoda
cornFlour
riceFlour
butter
vegan
"""