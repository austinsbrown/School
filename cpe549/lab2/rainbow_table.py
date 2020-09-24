import sys
import hashlib as hsh

if(len(sys.argv) != 3):
    print("Error: The program accepts 2 text files as arguments.")
    sys.exit()

rainbow_table = {}

with open(sys.argv[1]) as infile:
    for i in infile:
        p = i.strip()
        encoded_password = p.encode('utf_16_le')
        hashed = hsh.new('MD4', encoded_password)
        hashed.update(encoded_password)
        rainbow_table[hashed.hexdigest()] = p

outfile = open(sys.argv[2], 'w')
for i in sorted(rainbow_table.keys()):
    print(i + ':' + rainbow_table[i])
    outfile.write(i + ':' + rainbow_table[i] + '\n')

infile.close()
outfile.close()