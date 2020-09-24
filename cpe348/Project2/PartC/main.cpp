 #include <iostream>
 #include <fstream>
 #include <cmath>
 using namespace std;

struct Station                                                      // struct to define station
{
    int stationNumber;
    int value;
    int slot;
    int attempts;
    int modvalue;
    char status;
    int first;
    int numOfSuccess;
};

const int NUMOFSTATIONS = 5;                                        // total number of stations            

int main()
{
    ifstream infile;                                                // input file stream
    ofstream outfile;
    infile.open("Project2_part1_rn.txt");                           // open input file of random numbers
    outfile.open("report.txt");
    if (!infile.is_open())                                          // handle input file errors   
	{
		cout << "Error - unable to open input file" << endl;            
		infile.close();                                              
		return 0;                                                       
	} 
    
    Station stations[NUMOFSTATIONS];                                // array of stations

    for(int i=0; i < NUMOFSTATIONS; i++)                            // populate all of the stations with initial values
    {
        stations[i].stationNumber   = i;
        stations[i].value           = 0;
        stations[i].slot            = 0;
        stations[i].attempts        = 1;
        stations[i].modvalue        = 2;
        stations[i].status          = 'f';
        stations[i].first = 0;
        stations[i].numOfSuccess = 0;
    }
    
    int slotCount = 0;                                              
    int numInSlot;
    int line;
    int incrementSlot = 0;
    bool allSent = false;

    while (allSent == false)
    {
        for(int i=0; i < NUMOFSTATIONS; i++)
        {
            if(stations[i].status == 's')
                allSent = true;
            else
            {
                allSent = false;
                break;
            }
        }
        numInSlot = 0;
        for(int i=0; i < NUMOFSTATIONS; i++)
        {
            if(stations[i].slot == slotCount)
                numInSlot++;
        }

        for(int i=0; i < NUMOFSTATIONS; i++)
        {
            if(stations[i].slot == slotCount)
            {
                if(numInSlot != 1)
                {
                    infile >> line;
                    stations[i].value = line;

                    incrementSlot = 1 + stations[i].value % stations[i].modvalue;
                    stations[i].slot += incrementSlot;
                    stations[i].attempts++;
                    stations[i].modvalue = pow(2, stations[i].attempts);
                    cout << stations[i].stationNumber << " is moved " << stations[i].slot << endl;

                }
                else
                {
                    stations[i].modvalue = 2;
                    stations[i].attempts = 1;
                    stations[i].status = 's';
                    cout << stations[i].stationNumber << " succsessful at slot " << stations[i].slot << endl;
                    stations[i].numOfSuccess++;
                    if(stations[i].numOfSuccess == 1)
                    {
                        stations[i].first = slotCount;
                    }
                                   
                    //stations[i].attempts = 0;
                    stations[i].slot = stations[i].slot + 3;
                }         
            }
        }
        slotCount++;
    }

    float timeout;
    outfile << "Final Values:" << endl;
    for(int i=0; i < NUMOFSTATIONS; i++)
    {
        timeout = stations[i].first * 51.2;
        outfile << stations[i].stationNumber << " was transmitted at slot " << stations[i].first << "." << 
        " It times out at " << timeout << " microseconds " << endl;
    }   
}
