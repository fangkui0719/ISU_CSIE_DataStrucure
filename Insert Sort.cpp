#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
	int size;  
	int temp; //�Ȧs��  
	int i;
	double start,end; //start���}�l�ƧǮɶ�; end�������p��ɶ� 
	for (size=100000;size<=500000;size=size+100000)
	{
		int a[size];
		cout << "Size:" << size <<"\n";
	
		for(i=0;i<size;i++){
			a[i]=(rand()%100+1); //���w 1 ~ 100�����H���ܼ� 
			//cout << a[i] << " ";
		}
		
		/* Insert Sort �t��k*/ 
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
		cout << "Time:" << (end-start)/1000 <<"s\n\n"; //�p��Ƨǩһݮɶ� 
	}

	system ("pause");
	return 0;
}
