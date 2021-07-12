
def evalPostfix(cls, input1):
    st = []
    for c in input1:
        if(c.isdigit()):
            st.append(int(c))
        else:
            y = st.pop()
            x = st.pop()
            if(c=='+'):
                st.append(x+y)
            elif(c=='-'):
                st.append(x-y)
            elif(c=='*'):
                st.append(x*y)
            elif(c=='/'):
                st.append(x//y)
    return st.pop()

print(evalPostfix('879-2*+'))
print(evalPostfix('84-'))
print(evalPostfix('84/'))
#print(evalPostfix(''))


#python "F:\cpp\random\py\new.py"