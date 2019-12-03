f = ["snd.txt"]

b = open(f[0], "r")

res = open("Sres.txt", "w")


for i in range(11):
    res.write("\\begin{center}\n")
    res.write("\t\\begin{tabular}{|c c c c c|}\n")
    res.write("\t\t\\hline\n")
    res.write("\t\t$\\alpha$ & $\\beta$ & $T_{max}$ & Len & Time (c) \\\\ [0.5ex]\n")


    for j in range(7):
        tb = b.readline()
        print(tb.split())

        res.write("\t\t" + tb.split()[0] + " & " + tb.split()[1] + " & " + tb.split()[2] + " & " + tb.split()[3] + " & " + tb.split()[4] + " \\\\ \n \t\t\\hline \n")

    res.write("\t\\end{tabular}\n\\end{center}\n\n")

b.close()

res.close()
