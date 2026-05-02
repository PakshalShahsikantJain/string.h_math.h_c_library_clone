#include "String.h"

int MyStrlen(char *str)
{
    int iCnt = 0;

    if(str == NULL)
    {
        return 0;
    }

    while(*str != '\0')
    {
        iCnt++;

        str++;
    }

    return iCnt;
}

void MyStrCpy(char *str,char *dest)
{
    while(*str != '\0')
    {
        *dest = *str;
        dest++;
        str++;
    }

    *dest = '\0';
}

void MyStrncpy(char *str,char *dest,int ino)
{
    int i = 1;

    while((*str != '\0') && (i <= ino))
    {
        *dest = *str;
        dest++;
        str++;
        i++;
    }

    *dest = '\0';
}

void MyStrcat(char *str1,char *str2,char *dest)
{ 
    while(*str1 != '\0')
    {
        *dest = *str1;

        dest++;
        str1++;
    }

    *dest = ' ';
    dest++;

    while(*str2 != '\0')
    {
        *dest = *str2;

        dest++;
        str2++;
    }

    *dest = '\0';
}

BOOL MyStrCmp(char *str1,char *str2)
{
    while((*str1 != '\0')&&(*str2 != '\0'))
    {
        if(*str1 != *str2)
        {
            break;
        }

        str1++;
        str2++;
    }

    if(*str1 != *str2)
    {
        return FALSE;
    }
    else 
    {
        return TRUE;
    }
}

BOOL MyStrnCmp(char *str1,char *str2,int iNo)
{    
    int i = 1;

    while((i <= iNo) && (*str1 != '\0') && (*str2 != '\0'))
    {
        if(*str1 != *str2)
        {
            break;
        }

        str1++;
        str2++;
        i++;
    }

    if(*str1 != *str2)
    {
        return FALSE;
    }
    else 
    {
        return TRUE;
    }
}

void MyStrRev(char *str,char *revString)
{
    char *temp = str;
    while(*temp != '\0')
    {
        temp++;
    }    

    temp--;
    
    while(*temp != *str)
    {
        *revString = *temp;
        printf("%c\n",*revString);

        revString++;
        temp--;
    }
    
    
    *revString = *temp;
    
    revString++;

    *revString = '\0';

    printf("%s\n",revString);
}

int MyStrchr(char *str,char ch)
{
    int i = 0;

    while(*str != '\0')
    {
        if(*str == ch)
        {
            break;
        }

        i++;

        str++;
    }

    if(*str == ch)
    {
        str = NULL;
        return i;
    }
    else 
    {
        return 0;
    }
}

int MyStrStr(char *str1,char *str2)
{
    char *temp = str2;
    int i = 0;

    while(*str1 != '\0')
    {
        while(*temp != '\0')
        {
            if(*temp != *str1)
            {
                break;
            }

            str1++;
            temp++;
        }

        if(*temp == '\0')
        {
            break;
        }

        if(*temp != *str1)
        {
            temp = str2;
        }

        i++;
        str1++;
    }

    if(*temp == '\0')
    {
        *str1 ='\0';

        return i;
    }
    else 
    {
        return 0;
    }
}

