def isIsomorfic(s: str, t: str) -> bool:
    s_dic, t_dic = {}, {}
    for i in range(len(s)):
        c1, c2 = s[i], t[i]
        if (c1 in s_dic and s_dic[c1] != c2) or (c2 in t_dic and t_dic[c2] != c1):
            return False
        s_dic[c1] = c2
        t_dic[c2] = c1
    return True

print(isIsomorfic("bar","foo"))