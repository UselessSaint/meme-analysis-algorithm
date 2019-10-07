f = open("wMult_times_proc.txt", "w")
g = open("wMult_times.txt", "r")

t = dict()

         
for line in g:
        temp = line.split()
    
        if not temp[0] in t.keys():
             temp = line.split()
             t.setdefault(temp[0], float(temp[1][:-1]))
        else:
            t[temp[0]] += float(temp[1][:-1])
        

for key in t.keys():
    f.write(key + ' ' + str(t[key]/10) + '\n')
             

f.close()
g.close()
