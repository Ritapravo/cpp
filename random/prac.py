


class Volcano:
    def __init__(self, a, b, c, d, e):
        self.volcanoName = a
        self.country = b
        self.elevation = c 
        self.areaInKmSq = d 
        self.lastEruptionYear = e 
    

class Eruption:
    def __init__(self, li):
        self.li = li 

    def findVolcanoByCountry(self, li, cnt):
        cntList = []
        for x in li:
            t = x.country
            #print(t, cnt)
            if (t.lower() == cnt.lower()):
                #print("#")
                cntList.append(x)
        #print(cntList)
        if(cntList==[]):
            return None 
        else :
            return cntList 

    def getVolcanoCategorization(self, li, name):
        for x in li:
            t = x.volcanoName
            if (t.lower() == name.lower()):
                z = x.lastEruptionYear 
                if(z==2021):
                    return "Active"
                elif(z<=2020 and (2021-z) <= 25):
                    return "High probability"
                elif(2021-z>=25 and 2021-z<=50):
                    return "Low probability"
                else:
                    return "Inactive"
        return None






if __name__=="__main__":
    n = int(input())
    li = []
    for i in range(n):
        a = input()
        b = input()
        c = int(input())
        d = int(input())
        e = int(input())
        temp = Volcano(a,b,c,d,e)
        li.append(temp)

    ob = Eruption(li)
    cnt = input()
    name = input()
    ans1 = ob.findVolcanoByCountry(li, cnt)
    ans2 = ob.getVolcanoCategorization(li, name)
    
    if(ans1==None):
        print("No Matching records found")
    else:
        for i in ans1:
            print(i.volcanoName)
            print(i.country)
            print(i.lastEruptionYear)
    if(ans2==None):
        print("No Volcano is available with the given name")
    else:
        print(ans2)
    



#python "F:\cpp\random\prac.py"
""" 
5
Mount Loa
United States
4169
5271
1984
Mount Etna
Italy
3350
1190
2021
Mount Merapi
Indonesia
2930
1356
2020
Mount Vesusius
Italy
1281
1232
1944
Mount Pinatubo
Philippine
1486
1486
1991
ItaLy
Mount Etna
 """

""" 
5
mount loa
united st
1513
212
1984
Mount Etna
Italy
2123
213
2021
Mount Merapi
Indonesia
231
1231
2020
Mount Vesuvius
Italy
1981
2312
1944
Mount Pinatubo
Pjilipine
13
231
1991
Italy
Mount Etna
 """