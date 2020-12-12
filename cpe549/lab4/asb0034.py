import sys
from Crypto.Hash import MD5

if(len(sys.argv) != 2):
    print("Error: The program accepts 1 binary file as an argument.")
    sys.exit()

hash_object = MD5.new()
filename = sys.argv[1]
with open(filename, 'rb') as infile:    
    byte = infile.read(1)
    while byte:
        hash_object.update(byte)
        byte = infile.read(1)

print(filename, ': MD5 Hash =', hash_object.hexdigest())

infile.close()