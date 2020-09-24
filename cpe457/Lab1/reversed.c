#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("What is the answer to the Ultamate Question of life, the universe.\n");
        return 0;
    }

    int shift_result = atoi(argv[1]) * 16;
    int add_result = shift_result;
    add_result = add_result / 128;
    add_result++;

    if(add_result == 42)
    {
        printf("Yes, a completely ordinary number, a number not just divisible by two but also seven.");
        printf("In fact it's the sort of number that yoy could without fear introduce to your parents.\n");
    }
    else
        printf("No, Binary representations, base 13, Tibetan monks are all complete nonsence.\n");
    
    return 0;
}