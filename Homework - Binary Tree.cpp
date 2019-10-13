#include <iostream>
#include <cstdlib>
using namespace std;

	int *a , n;

//�ѦҸ�� chapter5 PPT page 35, 37, 39, 42 
//Pre-Order Inversal
void preorder(int node) 
{
	cout<< a[node] << " " ; //����� 
	if(node*2+1 < n) //�P�_���S������l �]���S���j��n �ҥH�@�w�s�b����l
		preorder(node*2+1); //�]���q'0'�}�l��ҥH�nnode *2+1 
   	if(node*2+2 < n) //�P�_���S���k��l �]���S���j��n �ҥH�@�w�s�b�k��l 
		preorder(node*2+2);
} //���p�q1�}�l�� ����l = node *2 �k��l = node *2 + 1 

//In-Order Inversal
void inorder(int node)
{
 	if(node*2+1 < n)
    	inorder(node*2+1);
   		cout<< a[node] << " " ; //�����_���j�]����l�A�]��̥���A�A��ܡA���k��l�A�A�]���j
   	if(node*2+2 < n)
    	inorder(node*2+2);
}

//Post-Order Inversal
void postorder(int node)
{
	if(node*2+1 < n)
    	postorder(node*2+1); //�����_���j�] ����l �]��̥��� �b�ˬd���S���k��l  
   	if(node*2+2 < n)
    	postorder(node*2+2 ); //�p�G�S���k��l�A�A��ܡA�p�G���A�A�]���j�A�ˬd���k��l�A�S���N��� 
 		cout<< a[node] << " " ;
}


int main ()
{
	a = new int[n]; //�V�t�έn�O���� 
	cout << "��J binary tree �� node �`�q:";
	cin >> n;
    for(int i=0;i<n;i++)
    {
    	cout << "��JNode:";
		cin>>a[i];
	}	
	cout << "��J��Node: ";
	for (int j=0;j<n;j++)
		cout << a[j] << " ";
	cout << endl << endl;
	
	cout << "preorder:";
	preorder(0);
	cout << endl << endl;

	cout << "inorder:";
	inorder(0);
	cout << endl << endl;

	cout << "postorder:";
	postorder(0);
	cout << endl << endl;

    system ("pause");
    return 0;
    
}


