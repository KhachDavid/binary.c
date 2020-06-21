int twopower(int number_222);
void binary(int bin);

int main(void)
{
    int a;
    do 
    {
       a = get_int("Enter a number: ");
    }
    while (a < 1);
    
    binary(a);
    
    return 0;
}

int twopower(int number_222) // finding the highest power of two that is smaller than the given number 
{
    int index12 = 0;
    
    for (int i = 0; 2 > 1; i++)
    {
        if (pow(2, i) > number_222)
        {
            break;
        }
        index12 = i;
    }
    
    if (number_222 == 1)
    {
        index12 = 0;
    }
    
    return index12;
}

void binary(int bin)
{
    int mnacord;
    int twopower_rep;
    int counter = 0; 
    
    int* temp = malloc(4);
    int* temp1;
    
    while (bin > 0) // creating an array of the powers of two that are used to represent a given num /// 13 = 2^3 + 2^2 + 2^0
    {
        twopower_rep = twopower(bin);
        mnacord = bin - pow(2, twopower_rep);
        bin = mnacord;
        counter++;
        temp1 = realloc(temp, sizeof(int) * (counter));
        temp1[counter] = twopower_rep;
    }
    
    long long int final = pow(10, temp1[1]); //setting up the digits of the binary representation
    
    for (int i = 0 ; i < counter - 1; i++)
    {
        final = final + pow(10, temp1[2 + i]); //need to start with the third element of the array
    }
    
    printf("%lli", final);
    
    free(temp1);
}
