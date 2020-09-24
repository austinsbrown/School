void GetNextImage(ifstream& datastream, int counters[], Record& data)
{
    int firstNumber; // first number in the csv file
    datastream >> firstNumber;
    data.digit = firstNumber;

    counters[data.digit] += 1;

    char comma; // gets commas so they can be ignored
    int num; 
    for(int i=0; i < MAXROWS; i++) // iterate through the csv file 
    {
        for(int j=0; j < MAXCOLS; j++)
        {
            datastream >> comma;
            datastream >> data.image[i][j];
        }
    }
    if(datastream.eof())
    {
        counters[data.digit] = counters[data.digit] - 1;
    }
}

void Transpose(int image[MAXROWS][MAXCOLS])
{
    int temp[MAXROWS][MAXCOLS];
    for(int i=0; i < MAXROWS; i++) // assign transposed values to temp 
    {
        for(int j=0; j < MAXCOLS; j++)
        {
            temp[j][i] = image[i][j];
        }
    }

    for(int i=0; i < MAXROWS; i++) // set the temp equal to the original
    {
        for(int j=0; j < MAXCOLS; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

}

void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
    int temp[MAXROWS][MAXCOLS]; // temporary var

    for(int i=0; i < MAXROWS; i++)
    {
        for(int j=0; j < MAXROWS; j++)
        {
            temp[i][j] = image[i][MAXCOLS - 1 - j];
        }
    }

    for(int i=0; i < MAXROWS; i++) // set the temp equal to the original 
    {
        for(int j=0; j < MAXCOLS; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

void FlipVertical(int image[MAXROWS][MAXCOLS])
{
    int temp[MAXROWS][MAXCOLS]; // temporary var

    for(int i=0; i < MAXROWS; i++)
    {
        for(int j=0; j < MAXROWS; j++)
        {
            temp[i][j] = image[MAXROWS - 1 - i][j];
        }
    }

    for(int i=0; i < MAXROWS; i++) // set the temp equal to the original 
    {
        for(int j=0; j < MAXCOLS; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}

void RotateCW(int image[MAXROWS][MAXCOLS])
{
    for(int i=0; i < MAXCOLS/2; i++)
    {
        for (int j=i; j < MAXCOLS-i-1; j++)
        {
            int temp = image[i][j];

            image[i][j] = image[j][MAXCOLS-1-i]; 
            image[j][MAXCOLS-1-i] = image[MAXCOLS-1-i][MAXCOLS-1-j];
            image[MAXCOLS-1-i][MAXCOLS-1-j] = image[MAXCOLS-1-j][i];
            image[MAXCOLS-1-j][i] = temp; 
        }
    }

    for(int i=0; i < MAXCOLS/2; i++)
    {
        for (int j=i; j < MAXCOLS-i-1; j++)
        {
            int temp = image[i][j];

            image[i][j] = image[j][MAXCOLS-1-i]; 
            image[j][MAXCOLS-1-i] = image[MAXCOLS-1-i][MAXCOLS-1-j];
            image[MAXCOLS-1-i][MAXCOLS-1-j] = image[MAXCOLS-1-j][i];
            image[MAXCOLS-1-j][i] = temp; 
        }
    }

    for(int i=0; i < MAXCOLS/2; i++)
    { 
        for (int j=i; j < MAXCOLS-i-1; j++)
        {
            int temp = image[i][j];

            image[i][j] = image[j][MAXCOLS-1-i]; 
            image[j][MAXCOLS-1-i] = image[MAXCOLS-1-i][MAXCOLS-1-j];
            image[MAXCOLS-1-i][MAXCOLS-1-j] = image[MAXCOLS-1-j][i];
            image[MAXCOLS-1-j][i] = temp; 
        }
    }
}

void RotateCCW(int image[MAXROWS][MAXCOLS])
{
    for(int i=0; i < MAXCOLS/2; i++)
    {
        for (int j=i; j < MAXCOLS-i-1; j++)
        {
            int temp = image[i][j];

            image[i][j] = image[j][MAXCOLS-1-i]; 
            image[j][MAXCOLS-1-i] = image[MAXCOLS-1-i][MAXCOLS-1-j];
            image[MAXCOLS-1-i][MAXCOLS-1-j] = image[MAXCOLS-1-j][i];
            image[MAXCOLS-1-j][i] = temp; 
        }
    }
}
