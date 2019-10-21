import os

n = int(input("Amount: "))

print("Range: ")
a = int(input("  a: "))
b = int(input("  b: "))

os.system("ghc --make -XBangPatterns main.hs")
os.system("echo Comp done")

for i in range (a, b+1, 100):
    for j in range(n):
        os.system("main.exe 1 %d" %i)
    os.system("echo lenProced %d" %i)