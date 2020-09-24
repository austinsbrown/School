#include <stdio.h>
#include <msp430.h>
#include "limits.h"
#include "float.h"

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;

    int charSize = sizeof(char);                        // size of a char
    int shrtIntSize = sizeof(short int);                // size of short int
    int lngIntSize = sizeof(long int);                  // size of long int
    int lngLngIntSize = sizeof(long long int);          // size of long long int   
    int floatSize = sizeof(float);                      // size of float
    int doubleSize = sizeof(float);                     // size of double
    int uCharSize = sizeof(unsigned char);
    int uShrtIntSize = sizeof(unsigned short int);
    int uIntSize = sizeof(unsigned int);
    int uLngIntSize = sizeof(unsigned long int);
    int uLngLngIntSize = sizeof(unsigned long long int);
    int intSize = sizeof(int);

    /* print the header */
    printf("---------------------------------------------------------------------------------------\n");
    printf("%-17s", "| Data Type");
    printf("%-19s", "| Size (in bytes)");
    printf("%-23s", "| Minimum");
    printf("%-27s", "| Maximum");
    printf("|\n");
    printf("---------------------------------------------------------------------------------------\n");

    printf("%-17s", "| Char");                          
    printf("| ");
    printf("%-17d", charSize);                          // print char size
    printf("| ");
    printf("%-21d", CHAR_MIN);                          // print unsigned char minimum
    printf("| ");
    printf("%-25d", CHAR_MAX);                          // print the max
    printf("| \n");

    printf("%-17s", "| Short Int");
    printf("| ");
    printf("%-17d", shrtIntSize);                       // print short int size
    printf("| ");
    printf("%-21d", SHRT_MIN);                          // print short int min    
    printf("| ");
    printf("%-25d", SHRT_MAX);                          // print short int max
    printf("| \n");

    printf("%-17s", "| Int");
    printf("| ");
    printf("%-17d", intSize);                      
    printf("| ");
    printf("%-21d", INT_MIN);                          
    printf("| ");
    printf("%-25d", INT_MAX);                          
    printf("| \n");

    printf("%-17s", "| Long Int");
    printf("| ");
    printf("%-17d", lngIntSize);                        // print long int size             
    printf("| ");
    printf("%-21ld", LONG_MIN);                         // print long int min
    printf("| ");
    printf("%-25ld", LONG_MAX);                         // print long int max
    printf("| \n");

    printf("%-17s", "| Long Long Int");
    printf("| ");
    printf("%-17d", lngLngIntSize);                     // print long long int size
    printf("| ");
    printf("%-21lld", LLONG_MIN);                       // print long long int min
    printf("| ");
    printf("%-25lld", LLONG_MAX);                       // print long long int max
    printf("| \n");

    printf("%-17s", "| Unsigned Char");
    printf("| ");
    printf("%-17d", uCharSize);                         // unsigned char size
    printf("| ");
    printf("%-21d", 0);                                 // unsigned char min
    printf("| ");
    printf("%-25d", UCHAR_MAX);                         // unsigned char max
    printf("| \n");

    printf("%-17s", "| U Short Int");
    printf("| ");
    printf("%-17d", uShrtIntSize);                      // unsigned short int size
    printf("| ");
    printf("%-21d", 0);                                 // unsigned short int min
    printf("| ");
    printf("%-25u", USHRT_MAX);                         // unsigned short int max
    printf("| \n");

    printf("%-17s", "| U Int");
    printf("| ");
    printf("%-17d", uIntSize);                          // unsigned int
    printf("| ");
    printf("%-21d", 0);                                 // unsigned int min
    printf("| ");
    printf("%-25u", UINT_MAX);                          // unsigned int max
    printf("| \n");

    printf("%-17s", "| U Long Int");
    printf("| ");
    printf("%-17d", uLngIntSize);
    printf("| ");
    printf("%-21d", 0);
    printf("| ");
    printf("%-25lu", ULONG_MAX);
    printf("| \n");

    printf("%-17s", "| U Long Long Int");
    printf("| ");
    printf("%-17d", uLngLngIntSize);
    printf("| ");
    printf("%-21d", 0);
    printf("| ");
    printf("%-25llu", ULLONG_MAX);
    printf("| \n");

    printf("%-17s", "| Float");
    printf("| ");
    printf("%-17d", floatSize);                         // print float size
    printf("| ");
    printf("%-21.2e", FLT_MIN);                         // print float min
    printf("| ");
    printf("%-25.2e", FLT_MAX);                         // print float max
    printf("| \n");

    printf("%-17s", "| Double");
    printf("| ");
    printf("%-17d", doubleSize);                        // print double size
    printf("| ");
    printf("%-21e", DBL_MIN);                           // print double min
    printf("| ");
    printf("%-25e", DBL_MAX);                           // print double max
    printf("| \n");

    printf("---------------------------------------------------------------------------------------\n");
    printf("\n");
}
