#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int a[500000]; 
void merge(int,int,int);

/*找中間值*/ 
void merge_sort(int low,int high)
{
 	int mid;
 	if(low<high)
 	{
  		mid=(low+high)/2;
  		merge_sort(low,mid);
  		merge_sort(mid+1,high);
  		merge(low,mid,high);
 	}
}

/* Merge Sort 演算法*/ 
void merge(int low,int mid,int high)
{
 	int h,i,j,b[500000],k;
 	h=low;
 	i=low;
 	j=mid+1;

 	while((h<=mid)&&(j<=high))
 	{
  		if(a[h]<=a[j])
  		{
   			b[i]=a[h];
   			h++;
  		}
  		else
  		{
  	 		b[i]=a[j];
   			j++;
  		}
  		i++;
 	}
 	
 	if(h>mid)
 	{
  		for(k=j;k<=high;k++)
  		{
   			b[i]=a[k];
   			i++;
  		}
 	}
 	else
 	{
  		for(k=h;k<=mid;k++)
 	 	{
   			b[i]=a[k];
   			i++;
  		}
 	}
 	
 	for(k=low;k<=high;k++) a[k]=b[k];
}

int main()
{
 	int num,i;
	for(num=100000;num<=500000;num=num+100000)
	{
		for(i=1;i<=num;i++)
 		{
  			a[i]=(rand()%100+1); 
 		}
 	cout << "Size:" << num << endl << endl;
 	double start=clock();
 	merge_sort(1,num); //執行 Merge Sort 
 	double end=clock();
 	cout << "Time:"<< (end-start)/1000 << "s\n\n\n";
	}
 	cout<<endl<<endl;
}
