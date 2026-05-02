#include<stdlib.h>
#include<stdio.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

int Mystrlen(char *str);
void MyStrCpy(char *str,char *dest);
void MyStrncpy(char *str,char *dest,int ino);
void MyStrcat(char *str1,char *str2,char *dest);
BOOL MyStrCmp(char *str1,char *str2);
BOOL MyStrnCmp(char *str1,char *str2,int iNo);
void MyStrRev(char *str,char *revString);
int MyStrchr(char *str,char ch);
int MyStrStr(char *str1,char *str2);
