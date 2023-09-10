def removeKDigits(num, k):
    st=[]
    for n in num:
        while k>0 and st and n < st[-1]:
            k-=1
            st.pop()
        st.append(n)
    st=st[:len(st)-k]
    res= "".join(st)
    return str(int(res)) if res else "0"

print(removeKDigits("123456", 3))