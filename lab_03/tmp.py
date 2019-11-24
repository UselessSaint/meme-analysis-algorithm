f = ["bSort_timesF_proc.txt",
     "inSort_timesF_proc.txt",
     "qSort_timesF_proc.txt"]

b = open(f[0], "r")
i = open(f[1], "r")
q = open(f[2], "r")

res = open("Fres.txt", "w")

res.write("\\begin{center}\n")
res.write("\t\\begin{tabular}{|c c c c|}\n")
res.write("\t\\hline\n")
res.write("\tРазмер & bSort (c) & inSort (c) & qSort (c) \\\\ [0.5ex]\n")


for j in range(11):
    tb = b.readline()
    print(tb.split())
    ti = i.readline()
    print(ti.split())
    tq = q.readline()
    print(tq.split())

    res.write("\t\t" + tb.split()[0] + " & " + tb.split()[1] + " & " + ti.split()[1] + " & " + tq.split()[1] + " \\\\ \n \t\t\\hline \n")

res.write("\t\\end{tabular}\n\\end{center}")

b.close()
i.close()
q.close()
res.close()
    
