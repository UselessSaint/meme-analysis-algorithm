giles = ["bSort_timesR.txt", "qSort_timesR.txt", "inSort_timesR.txt",
         "bSort_timesF.txt", "qSort_timesF.txt", "inSort_timesF.txt", 
         "bSort_times.txt", "qSort_times.txt", "inSort_times.txt"]
files = ["bSort_timesR_proc.txt", "qSort_timesR_proc.txt", "inSort_timesR_proc.txt",
         "bSort_timesF_proc.txt", "qSort_timesF_proc.txt", "inSort_timesF_proc.txt",
         "bSort_times_proc.txt", "qSort_times_proc.txt", "inSort_times_proc.txt"]

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
        f.write(key + ' ' + str(round(t[key]/10, 5)) + '\n')

    f.close()
    g.close()