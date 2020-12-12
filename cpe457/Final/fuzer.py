import os

count = 3072465
while(count < 9999999):
    exe_string = "final_exam.exe " + str(count) + " 1 >> out.txt"
    os.system('echo ' + str(count) + ' >> out.txt')
    os.system(exe_string)
    print(count)
    count = count+1
