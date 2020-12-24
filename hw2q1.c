#include <stdio.h>
#include <stdbool.h>
int count(int a[],int n,int x);
int check(int a[],int n);
bool exclusive(int a[],int n);
void call_count();
void call_check();
void call_exclusive();

#define N 100
void call_count()
{ int n;
printf("Enter n : ");
  scanf("%d",&n);// get from input a positive number n
  int a[N];
  printf("\nEnter numbers : ");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);// get from input n int numbers.
  int x;
  printf("\nEnter x : \n");
  scanf("%d",&x);// will get any x
  int k=count(a,n,x);
  printf("\n%d appears %d time%s\n",x,k,k==1?"":"s");// displays the number of different values in the series
}
void call_check()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);//get from input a positive number n
    printf("\nEnter numbers : \n");
    int a[N];
    for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);//get from input n int numbers
    }
    int k=check(a,n);
    printf("Total %d value%s\n",k,k==1?"":"s");//displays the number of different values in the series
}
void call_exclusive()
{
  int n;
  printf("Enter n : ");
  scanf("%d",&n);//get from input a positive number n
  int a[N];
  printf("\nEnter numbers : \n");
  for(int i=0;i<n;i++)
  scanf("%d",&a[i]);//get from input n int numbers
  printf("series %sexclusive\n",exclusive(a,n)?"":"NOT ");//displays the number of different values in the series
}
int count(int a[],int n,int x)
{ if(n==0) return 0;
 return count(a+1,n-1,x)+(a[0]==x?1:0);
}
int check(int a[],int n)
{   if(n==0) return 0;

  return check(a+1,n-1)+(count(a+1,n-1,a[0])?0:1);
}
bool exclusive(int a[],int n)
{
    return check(a,n)==n;
}
/*int main()
{
    call_exclusive();
    return 0;
}*/
