#include<stdio.h>
#include<conio.h>
int main()
{
	int a[20],i,n,loc,item;
	int lsearch(int a[],int n,int item);
	printf("enter number of elements:");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("enter element a[%d]:");
		scanf("%d",&a[i]);
	}
	printf("enter item to search=");
	scanf("%d",&item);
	loc=lsearch(a,n,item);
	if(loc==-1)
	printf("item does not exist in array");
	else
	printf("item %d\t exist at index= %d",item,loc);
	return 0;
}
	int lsearch(int a[],int n, int item)
	{
		int loc=-1,i=1;
		while(i<n && a[i]!=item)
		i=i+1;
		if(a[i]==item)
		loc=i;
		return (loc);
	}


