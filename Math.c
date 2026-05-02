int MyPow(int iNo,int iNo2)
{
    int i = 0;
    int Ans = 1;

    for(i = 0;i < iNo2;i++)
    {
        Ans = Ans * iNo; 
    }

    return Ans;
}

int MySqrt(int iNo)
{
    int i = 0;
    float Ans = 0;

    for(i = 1;i <= iNo;i++)
    {
        Ans = iNo / i;

        if(Ans == i)
        {
            break;
        }
    }

    if(Ans == i)
    {
        return Ans;
    }
    else 
    {
        return 0;
    }
}

int MyAbs(int iNo)
{
    if(iNo < 0)
    {
        iNo = -iNo;
    }

    return iNo;
}

int MyMax(int iNo,int iNo2)
{
    if(iNo > iNo2)
    {
        return iNo;
    }
    else 
    {
        return iNo2;
    }
}

int MyMin(int iNo,int iNo2)
{
    if(iNo < iNo2)
    {
        return iNo;
    }
    else
    {
        return iNo2;
    }
}

int MyFactorial(int iNo)
{
    int i = 0;
    int iMult = 1;

    for(i = iNo;i > 0;i--)
    {
        iMult = iMult * i;
    }

    return iMult;
}

int MyGCD(int iNo,int iNo2)
{
    int i = 0;
    int temp = 0;
    int iMax = 0;

    if(iNo > iNo2)
    {
        temp = iNo;
        iNo = iNo2;
        iNo2 = temp;
    }

    for(i = 1;i <= (iNo2 / 2);i++)
    {
        if(((iNo % i) == 0)&&((iNo2 % i) == 0))
        {
            if(i > iMax)
            {
                iMax = i;
            }
        }
    }

    return iMax;
}

int MyLCM(int iNo,int iNo2)
{
    int i = 0;
    int temp = 0;
    int iMin = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    if(iNo2 < 0)
    {
        iNo = -iNo2;
    }

    if(iNo > iNo2)
    {
        temp = iNo;
        iNo = iNo2;
        iNo2 = temp;
    }

    iMin = iNo * iNo2;

    for(i = 1;i <= iNo * iNo2;i++)
    {
        if(((i % iNo) == 0)&&((i % iNo2) == 0))
        {
            if(i < iMin)
            {
                iMin = i;
            }
        }
    }

    return iMin;
}