import itertools
#[(a,b,c) for a in "R"*8 for b in "C"*7 for c in "4"*5]
#[*[a for a in "R"*8], *[b for b in "C"*7], *[c for c in "4"*5]]

list1 = [*[f"R{i}" for i in range(1,9)], *[f"C{i}" for i in range(1,8)], *[f"K{i}" for i in range(1,6)]]

test = [(x,y,z) for x in list1
                for y in list1
                for z in list1]

filtrar = lambda tup: tup[0] != tup[1] and tup[0] != tup[2] and tup[1] != tup[2]
filtrar2 = lambda tup: tup[0][0] == tup[1][0] or tup[0][0] == tup[2][0] or tup[1][0] == tup[2][0]
res = [i for i in test if filtrar(i) and filtrar2(i)]
#print(res)
print(len(res))
            

