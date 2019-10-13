#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
	int size;  
	int temp; //暫存用  
	int i;
	double start,end; //start為開始排序時間; end為結束計算時間 
	for (size=100000;size<=500000;size=size+100000)
	{
		int a[size];
		cout << "Size:" << size <<"\n";
	
		for(i=0;i<size;i++){
			a[i]=(rand()%100+1); //給定 1 ~ 100中的隨機變數 
			//cout << a[i] << " ";
		}
		
		/* Insert Sort 演算法*/ 
		start=clock();
		for(i=0;i<size;i++)
		{	
			int j=i;
			while(j>0&&a[j]<a[j-1])
			{
				temp = a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				j--;
			}
		}
				
		cout << "\n";
		end=clock();
		cout << "Time:" << (end-start)/1000 <<"s\n\n"; //計算排序所需時間 
	}

	system ("pause");
	return 0;
}
