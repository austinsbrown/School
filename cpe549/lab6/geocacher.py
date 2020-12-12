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

country_dict = {}                       
for i in unique_ip.keys():
    country_name = gi.country_name_by_addr(i) 
    outfile.write(i + " is from " + country_name + " and was found " + str(unique_ip[i]) +  " time(s).\n")
    if country_name in country_dict.keys():  
            country_dict[country_name] += 1                                                     
    else:
        country_dict.update({country_name:1})  

for i in country_dict.keys():
    outfile.write(str(country_dict[i]) + " unique ip address(es) were found in " + i + "\n")

infile.close()
outfile.close()