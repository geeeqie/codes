# 4734
# 
# GREG

#    2: A,B,C     5: J,K,L    8: T,U,V
#    3: D,E,F     6: M,N,O    9: W,X,Y
#    4: G,H,I     7: P,R,S
char_map = {
        'A':2, 'B':2, 'C':2,
        'D':3, 'E':3, 'F':3,
        'G':4, 'H':4, 'I':4,
        'J':5, 'K':5, 'L':5,
        'M':6, 'N':6, 'O':6,
        'P':7, 'R':7, 'S':7,
        'T':8, 'U':8, 'V':8,
        'W':9, 'X':9, 'Y':9,
        'Q':0, 'Z':0}
names = list(open("dict.txt"))
name_dict = {}
for name in names:
    name = name.strip()
    number = ''.join(map(lambda x:str(char_map[x]), list(name)))
    name_dict.setdefault(number, []).append(name)

number = raw_input().strip()
try:
    for name in name_dict[number]:
        print name
except Exception:
    print 'NONE'
