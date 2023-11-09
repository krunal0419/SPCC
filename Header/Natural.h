int fact(int n)
{
    int result = 1;
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            result = result * i;  
        }

        return result;
       
    }
}

int Natural(int n)
{
    int sum = 0 ;
    for(int i=1;i<=n;i++)
    {
        sum = sum+i;
    }
    return sum;
}