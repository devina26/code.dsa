#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,loc, high, mid,n, key,array[100];
printf("enter the number of element: ");
scanf("%d",n);
printf(enter%d integer :, n);
for(i=0;i<n;i++);
scanf("%d",&array[]);
printf("enter the number of find:\n");
scanf("%d" ,&key);
low=0;
high=n-1;
mid=(low+high)/2;
while low<=high
{
if(array[mid]<key)
low=mid+1;
}
else if(array[mid]==key)
{
printf("%d found at location %d \n",key,mid+1);
break;
}
else
{

high=mid-1;
mid=(low+high)/2;
}
if(low>high)
printf("element not found ",key);
return 0;
}
