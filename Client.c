#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

//For String.h library
typedef int (*fp)(char *);
typedef void (*fp2)(char *,char *);
typedef void (*fp3)(char *,char *,int);
typedef void (*fp4)(char *,char *,char *);
typedef BOOL (*fp5)(char *,char *);
typedef BOOL (*fp6)(char *,char *,int);
typedef int (*fp7)(char *,char);
typedef int (*fp8)(char *,char *);

//For Math.h Library

typedef int (*fptr1)(int);
typedef int (*fptr2)(int,int);

int main()
{
    void * handle = NULL;
    void * handle2 = NULL;

    int iRet = 0;
    int iOption = 0;
    int value = 0;
    
    int iNo1 = 0;
    int iNo2 = 0;

    BOOL bret = FALSE;
    char ch = '\0';

    char arr[50] = {'\0'};
    char brr[50] = {'\0'};
    char crr[50] = {'\0'};
    
    fp mystrlen = NULL;
    fp2 mystrcpy = NULL;
    fp3 mystrncpy = NULL;
    fp4 mystrcat = NULL;
    fp5 mystrcmp = NULL;
    fp6 mystrncmp = NULL;
    fp2 mystrrev = NULL;
    fp7 mystrchr = NULL;
    fp8 mystrstr = NULL;

    fptr1 mysqrt = NULL;
    fptr1 myabs = NULL;
    fptr1 myfactorial = NULL;
    fptr2 mypow = NULL;
    fptr2 mymax = NULL;
    fptr2 mymin = NULL;
    fptr2 mygcd = NULL;
    fptr2 mylcm = NULL;

    printf("Jay Ganesh....\n");

    handle = dlopen("./libmystring.so",RTLD_LAZY);
    
    if(!handle)
    {
        fprintf(stderr,"Unable to load shared object: %s",dlerror());

        return 1;
    }

    handle2 = dlopen("./libmymath.so",RTLD_LAZY);

    if(!handle2)
    {
        fprintf(stderr,"Unable to load shared object: %s",dlerror());

        return 1;
    }

    while(1)
    {
        printf("------------------Select Operation You Want To Perform:-------------------\n");
        printf("-----String Operations-------\n");
        printf("1  : MyStrlen\n");
        printf("2  : MyStrcpy\n");
        printf("3  : MyStrncpy\n");
        printf("4  : MyStrcat\n");
        printf("5  : MyStrCmp\n");
        printf("6  : MyStrnCmp\n");
        printf("7  : MyStrRev\n");
        printf("8  : MyStrchr\n");
        printf("9  : MyStrStr\n");
        printf("-----Mathematical Operations-----\n");
        printf("10 : MyPow\n");
        printf("11 : MySqrt\n");
        printf("12 : MyAbs\n");
        printf("13 : MyMax\n");
        printf("14 : MyMin\n");
        printf("15 : MyFactorial\n");
        printf("16 : MyGCD\n");
        printf("17 : MyLCM\n");
        printf("0 : Exit\n");

        printf("Enter option Number: \n");
        scanf("%d",&iOption);

        switch(iOption)
        {
            case 1:
            {
                mystrlen = (fp)dlsym(handle,"MyStrlen");

                if(!mystrlen)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);
                
                iRet = mystrlen(arr);

                printf("Length of Entered String %s is: %d\n",arr,iRet);

                break;
            }
            case 2:
            {
                mystrcpy = (fp2)dlsym(handle,"MyStrCpy");

                if(!mystrcpy)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);
                
                mystrcpy(arr,brr);

                printf("Copied String is: %s\n",brr);

                break;
            }
            case 3:
            {
                mystrncpy = (fp3)dlsym(handle,"MyStrncpy");

                if(!mystrncpy)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);
                
                printf("Enter number of character you want to copy:\n");
                scanf("%d",&value);

                mystrncpy(arr,brr,value);

                printf("Copied String is: %s\n",brr);

                break;
            }
            case 4:
            {
                mystrcat = (fp4)dlsym(handle,"MyStrcat");

                if(!mystrcat)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);

                printf("Enter Second String: \n");
                scanf(" %[^'\n']s",brr);

                mystrcat(arr,brr,crr);

                printf("Concatinated string is: %s\n",crr);

                break;
            }
            case 5:
            {
            
                mystrcmp = (fp5)dlsym(handle,"MyStrCmp");

                if(!mystrcmp)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);

                printf("Enter Second String: \n");
                scanf(" %[^'\n']s",brr);

                bret = mystrcmp(arr,brr);

                if(bret == TRUE)
                {
                    printf("Entered Strings Matched\n");
                }
                else 
                {
                    printf("Entered Strings Not Matched\n");
                }

                break;
            }
            case 6:
            {
                mystrncmp = (fp6)dlsym(handle,"MyStrnCmp");

                if(!mystrncmp)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);

                printf("Enter Second String: \n");
                scanf(" %[^'\n']s",brr);

                printf("Enter Number of Character You Want to compare: \n");
                scanf("%d",&value);

                bret = mystrncmp(arr,brr,value);

                if(bret == TRUE)
                {
                    printf("Entered Number of Characters Matched\n");
                }
                else 
                {
                    printf("Entered Number of Characters Not Matched\n");
                }

                break;
            }
            case 7:
            {
                mystrrev = (fp2)dlsym(handle,"MyStrRev");

                if(!mystrrev)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);

                mystrrev(arr,brr);

                printf("Reversed String is: %s\n",brr);

                break;
            }
            case 8:
            {
                mystrchr = (fp7)dlsym(handle,"MyStrchr");

                if(!mystrchr)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);

                printf("Enter One Character You Want to Find First Occurance of: \n");
                scanf(" %c",&ch);

                iRet = mystrchr(arr,ch);

                if(iRet != 0)
                {
                    printf("First Occurance of %c character in %s String Found at index number %d\n",ch,arr,iRet);
                }
                else 
                {
                    printf("%c Character Not Found in Entered String: %s\n",ch,arr);
                }


                break;
            }
            case 9:
            {
                mystrstr = (fp8)dlsym(handle,"MyStrStr");

                if(!mystrstr)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter one string: \n");
                scanf(" %[^'\n']s",arr);

                printf("Enter Second string: \n");
                scanf(" %[^'\n']s",brr);

                iRet = mystrstr(arr,brr);

                if(iRet != 0)
                {
                    printf("First Occurence of String %s found in String %s starting from index Number %d\n",brr,arr,iRet);
                }
                else 
                {
                    printf("%s String Not Found in %s String",brr,arr);
                }

                break;
            }
            case 10:
            {
                mypow = (fptr2)dlsym(handle2,"MyPow");

                if(!mypow)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter Number: \n");
                scanf("%d",&iNo1);

                printf("Enter Power: \n");
                scanf("%d",&iNo2);

                iRet = mypow(iNo1,iNo2);

                printf("Value of Power of %d of %d is: %d\n",iNo2,iNo1,iRet);
                
                break;
            }
            case 11:
            {
                mysqrt = (fptr1)dlsym(handle2,"MySqrt");

                if(!mysqrt)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter Number: \n");
                scanf("%d",&iNo1);

                iRet = mysqrt(iNo1);

                printf("Square Root of Number %d is: %d\n",iNo1,iRet);

                break;
            }    
            case 12:
            {
                myabs = (fptr1)dlsym(handle2,"MyAbs");

                if(!myabs)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter Number: \n");
                scanf("%d",&iNo1);

                iRet = myabs(iNo1);
                
                printf("Absolute Value of %d is: %d\n",iNo1,iRet);

                break;
            }
            case 13:
            {
                mymax = (fptr2)dlsym(handle2,"MyMax");

                if(!mymax)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter First Number: \n");
                scanf("%d",&iNo1);

                printf("Enter Second Number: \n");
                scanf("%d",&iNo2);

                iRet = mymax(iNo1,iNo2);
                
                printf("Max Number Between %d and %d is: %d\n",iNo1,iNo2,iRet);
                break;
            }
            case 14:
            {
                mymin = (fptr2)dlsym(handle2,"MyMin");

                if(!mymin)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter First Number: \n");
                scanf("%d",&iNo1);

                printf("Enter Second Number: \n");
                scanf("%d",&iNo2);

                iRet = mymin(iNo1,iNo2);
                
                printf("Min Number Between %d and %d is: %d\n",iNo1,iNo2,iRet);

                break;
            }
            case 15:
            {
                myfactorial = (fptr1)dlsym(handle2,"MyFactorial");

                if(!mymin)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter Number: \n");
                scanf("%d",&iNo1);

                iRet = myfactorial(iNo1);
                
                printf("Factorial of Number %d is: %d\n",iNo1,iRet);

                break;
            }
            case 16:
            {
                mygcd = (fptr2)dlsym(handle2,"MyGCD");

                if(!mygcd)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter First Number: \n");
                scanf("%d",&iNo1);

                printf("Enter Second Number: \n");
                scanf("%d",&iNo2);

                iRet = mygcd(iNo1,iNo2);
                
                printf("GCD of numbers %d and %d is: %d\n",iNo1,iNo2,iRet);

                break;
            }
            case 17:
            {
                mylcm = (fptr2)dlsym(handle2,"MyLCM");

                if(!mylcm)
                {
                    fprintf(stderr,"Unable to link shared object symbol: %s",dlerror());

                    return 1;
                }

                printf("Enter First Number: \n");
                scanf("%d",&iNo1);

                printf("Enter Second Number: \n");
                scanf("%d",&iNo2);

                iRet = mylcm(iNo1,iNo2);
                
                printf("LCM of numbers %d and %d is: %d\n",iNo1,iNo2,iRet);

                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
            default:
                printf("Invalid Option selected. Please Enter Option Number again !!!\n");
        }
    }

    dlclose(handle);
    dlclose(handle2);

    return 0;
}