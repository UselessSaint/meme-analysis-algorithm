files = ["uMult_times_proc.txt", "wMult_times_proc.txt", "wMultU1_times_proc.txt", "wMultU2_times_proc.txt", "wMultU3_times_proc.txt"]
giles = ["uMult_times.txt", "wMult_times.txt", "wMultU1_times.txt", "wMultU2_times.txt", "wMultU3_times.txt"]

for i in range(len(files)):
    f = open(files[i], "w")
    g = open(giles[i], "r")
    
    t = dict()
            
    for line in g:
            temp = line.split()
        
            if not temp[0] in t.keys():
                temp = line.split()
                t.setdefault(temp[0], float(temp[1][:-1]))
            else:
                t[temp[0]] += float(temp[1][:-1])

    for key in t.keys():
        f.write(key + ' ' + str(t[key]/50) + '\n')

    f.close()
    g.close()
