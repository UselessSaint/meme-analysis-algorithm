from random import *

N = int(input("Amount: "))

A = int(input("A: "))
B = int(input("B: "))

mtr = list()

for i in range(N):
    mtr.append(list())
    for j in range(N):
        mtr[i].append(0)


for i in range(N):
    for j in range(i+1, N):
        tmp = randint(A, B)
        mtr[i][j] = tmp
        mtr[j][i] = tmp
    print(mtr[i])

F = open("../" + str(N) + "x" + str(N) + "_" + str(A) + "-" + str(B) + ".txt", "w")


F.write(str(N) + "\n")

for i in range(N):
    for j in range(N):
        F.write(str(mtr[i][j]) + " ")
    F.write("\n")

F.close()
