import os

os.system("ghc --make -O3 main.hs")
os.system("echo done")

for i in range (1000, 2001, 100):
    for j in range (1, 11):
        os.system("main.exe %d" %i)
    os.system("echo %d" %i)