import numpy as np
import subprocess
import os

# To generate random test input for Nim and get their output

if 'input' not in os.listdir():
    os.mkdir('./input')

if 'output' not in os.listdir():
    os.mkdir('./output')

subprocess.run("g++ -o znim zero_move_nim.cpp; g++ -o znimDP zero_move_nim_DP.cpp;", shell = True)

for i in range(5):
    n = np.random.randint(2,100)
    file = 'input/input' + str(i) + '.txt'
    with open(file, 'w') as fp:
        fp.write(str(n))
        fp.write('\n')
        for j in range(n):
            fp.write(str(np.random.randint(1,1000)))
            fp.write(' ')

    data, temp = os.pipe()

    os.write(temp, bytes("5 10\n", "utf-8"))
    os.close(temp)

    s1 = subprocess.check_output("./znim < input/input" + str(i) + ".txt > output/output" + str(i) + ".txt;", stdin = data, shell = True)
    s2 = subprocess.check_output("./znimDP < input/input" + str(i) + ".txt > output/outputDP" + str(i) + ".txt;", stdin = data, shell = True)

    if s1 != s2:
        print(i)

subprocess.run("rm znim; rm znimDP;", shell = True)
