from crypt import crypt
from hmac import compare_digest

with open('shadow.txt') as infile:                                          # open the shadow file
    for i in infile:                                                        # iterate throught it
        total_hash = i.split(':')                                           # split each entry into components
        user = total_hash[0]                                                # get the username
        salt = total_hash[1]                                                # get the salt
        match_found = False

        with open('dictionary.txt') as dictionary:                          # open the dictionary file
            for j in dictionary:                                            # iterate through it
                val = j.split('\n')                                         # get rid of newline characters to get the word
                word = val[0]                                               
                encrypted = crypt(word, salt)                               # hash the value
                match = compare_digest(salt, encrypted)                     # compare it to the hash in the shadow file

                if(match):
                    match_found = True
                    print('Match found for userid ' + user + \
                          '.Password = ' + word)
                    break

            if(match_found == False):
                print('No match was found for ' + user)
                continue
            
                    

dictionary.close()
infile.close()        