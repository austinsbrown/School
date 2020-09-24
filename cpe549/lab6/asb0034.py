import pygeoip as geo

gi = geo.GeoIP('GeoIP.dat')
unique_ip = {}

with open('logins.txt', 'r') as infile:                                             # open the text file
    for i in infile:
        line = infile.readline()
        line = line.split(' ')
        
        items = []                                                                  # turn a line into an array
        for i in line:
            if(i != ''):
                items.append(i)

        ip = items[2]                                                               # get the ip address
        if ip in unique_ip.keys():  
            unique_ip[ip] += 1                                                      # increment dictionary
        else:
            unique_ip.update({ip:1})                                                # add to the dictionary

outfile = open('report.txt', 'w')

outfile.write(str(len(unique_ip)) + " unique IP addresses were found.\n")

                            
for i in unique_ip.keys():
    country_name = gi.country_name_by_addr(i) 
    outfile.write(i + " is from " + country_name + " and was found " + str(unique_ip[i]) +  " time(s).\n")


infile.close()
outfile.close()