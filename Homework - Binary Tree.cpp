#include <iostream>
#include <cstdlib>
using namespace std;

	int *a , n;

//參考資料 chapter5 PPT page 35, 37, 39, 42 
//Pre-Order Inversal
void preorder(int node) 
{
	cout<< a[node] << " " ; //先顯示 
	if(node*2+1 < n) //判斷有沒有左兒子 因為沒有大於n 所以一定存在左兒子
		preorder(node*2+1); //因為從'0'開始算所以要node *2+1 
   	if(node*2+2 < n) //判斷有沒有右兒子 因為沒有大於n 所以一定存在右兒子 
		preorder(node*2+2);
} //假如從1開始算 左兒子 = node *2 右兒子 = node *2 + 1 

//In-Order Inversal
void inorder(int node)
{
 	if(node*2+1 < n)
    	inorder(node*2+1);
   		cout<< a[node] << " " ; //先不斷遞迴跑左兒子，跑到最左邊，再顯示，有右兒子，再跑遞迴
   	if(node*2+2 < n)
    	inorder(node*2+2);
}

//Post-Order Inversal
void postorder(int node)
{
	if(node*2+1 < n)
    	postorder(node*2+1); //先不斷遞迴跑 左兒子 跑到最左邊 在檢查有沒有右兒子  
   	if(node*2+2 < n)
    	postorder(node*2+2 ); //如果沒有右兒子，再顯示，如果有，再跑遞迴，檢查左右兒子，沒有就顯示 
 		cout<< a[node] << " " ;
}


int main ()
{
	a = new int[n]; //向系統要記憶體 
	cout << "輸入 binary tree 的 node 總量:";
	cin >> n;
    for(int i=0;i<n;i++)
    {
    	cout << "輸入Node:";
		cin>>a[i];
	}	
	cout << "輸入的Node: ";
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


