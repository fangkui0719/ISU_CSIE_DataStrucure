#include <iostream>

using namespace std;
 
template <class T>
class Node {
    public:
        T data;
        Node<T> *link;
};
//以上為classNode 存在一個指標 一組數字 
template <class T> 
class NodeChain {
    public:
        NodeChain() {
            Last = new Node<T>;
            Last -> data = 0;
            Last -> link = 0;
            First = PreLast = Last; //大家都等於Last 
        };
        ~NodeChain();
        T NextNode(T x);
        T GetFirst() {return First -> data;}
        T GetNode(int k);
        NodeChain<T>& AppendNode(const T& x);
        NodeChain<T>& AddFrontNode(const T& x);
        NodeChain<T>& Insert(int k, const T& x);
        NodeChain<T>& Delete(int k, T& x) ;
        void OutputChain();
        bool IsInChain(T x);
        int Length() const;
        void GetNodeLine(NodeChain<T>& odd,NodeChain<T>& even);
        NodeChain<T>& NodeChain<T>::InLine(T& x);
    private:
        Node<T> *First;
        Node<T> *Last;   
        Node<T> *PreLast;//把它想成一組node外的指標 
};
 
template <class T>
NodeChain<T>::~NodeChain() {
    Node<T> *next;
    while(First != Last) {
        next = First -> link;
        delete First;
        First = next;
    }
    delete Last;
}
  
template <class T>
T NodeChain<T>::GetNode(int k) {
    int i = 0;
    Node<T> *current = First;
 
    while(i < k) {
        current = current -> link;
        i++;
    }
 
    return current -> data;
}
 
template <class T>
T NodeChain<T>::NextNode(T x){
    Node<T> *current = First;
     
    while(current != Last && current -> data != x) 
        current = current -> link;
     
    if(current == Last || current == PreLast) return Last -> data;
    else {
        current = current -> link; 
        return current -> data;
    }
}
 
template <class T>
NodeChain<T>& NodeChain<T>::AppendNode(const T& x) {
    Node<T> *y = new Node<T>;
    y -> data = x;
    y -> link = Last;
 
    if(First != Last) {
        PreLast -> link = y;
        PreLast = y;
    }
    else { 
        First = y; 
        PreLast = y;
    }
     
    return *this;
} 
 
template <class T>
NodeChain<T>& NodeChain<T>::AddFrontNode(const T& x) {
    Node<T> *y = new Node<T>;
    y -> data = x;
    y -> link = First;
    First = y;
     
    return *this;
}
 
template <class T>
void NodeChain<T>::OutputChain() {
    Node<T> *temp = First;
 
    while(temp != Last) {
        cout << temp -> data << " ";
        temp = temp -> link;
    }
}
 
template <class T>
NodeChain<T>& NodeChain<T>::Insert(int k, const T& x) {
       if(k < 0) {
            cout << "k < 0, Error!" << endl;
            return *this;
       }
        
       Node<T> *p = First;
        
       for(int index = 1; index < k && p; index++) p = p -> link;
       if(k > 0 && !p) {
            cout << " k out of the range" << endl;
            return *this;
       }
        
       Node<T> *y = new Node<T>;
       y -> data = x;
        
       if(k) {
            y -> link = p -> link;
            p -> link = y;
        }
         else {
                y -> link = First ->link; 
                First ->link = y;
       } 
        return *this;
}
 
template <class T>
NodeChain<T>& NodeChain<T>::Delete(int k, T& x){
      if(k < 1 || !First){
            cout << " k out of the range" << endl;
            return *this;
       } 
        
      Node<T> *p = First;
       
      if(k == 1) First -> link = First -> link -> link ;
      else {
            Node<T> *q = First -> link ;cout<<1;
            for(int index = 1; index < k - 1 && q; index++) q = q -> link;
            if(!q || !q -> link) {
                  cout << " k out of the range" << endl;
                  return *this;
            }  
             p = q -> link;
            q -> link = p -> link;
       }
       x = p -> data;
       delete p;
       return *this;
}
  
 
template <class T>
bool NodeChain<T>::IsInChain(T x) {
    Node<T> *temp = First;
    while(temp) {
        if(x == temp -> data) return true;
        else temp = temp -> link;
    }
    return false;  //有錯誤 true 改成 false 
}
 
template <class T>
int NodeChain<T>::Length() const {
      Node<T> *current = First;
      int len = 0;
      while(current) {
              len++;
              current = current ->link;
       }
       return len;
}
 
template <class T>
void NodeChain<T>::GetNodeLine(NodeChain<T>& odd,NodeChain<T>& even) {
      Node<T> *current = First;
      int len = 0,num;
  
      while(current-> link) {
              len++;
              if(len%2!=0){
              num=current -> data;
              odd.AppendNode(num);
              }
              if(len%2==0){
              num=current -> data;
              even.AppendNode(num);
              }
              current = current -> link;
       }
 
}
 
int main() {
    int number, item, sel, k;
    NodeChain<int> ChainA, ChainB, odd,even;
 
    while(1)
    {
            system("cls");
            cout<<"1.前置鏈結\n";
            cout<<"2.後置鏈結\n";
            cout<<"3.取得節點\n";
            cout<<"4.刪除鏈結\n";
            cout<<"5.是否鏈內\n";
            cout<<"6.插值入鏈\n";
            cout<<"7.刪值於鏈\n";
            cout<<"8.鏈結奇偶\n";
            cout<<"9.顯示鏈結\n";
            cin>>sel;
        switch(sel)
        {
                    
        case 1:
             cout << "Create a chain A by appending items: " << endl;
             cout << "Enter an number of items: ";
             cin >> number;
              
        for(int i = 0; i < number; i++) {
            cout << endl;
            cout <<"Enter an number: ";
            cin >> item;
         
            ChainA.AppendNode(item);        
        }
     
        cout << "The chain A is:";
        ChainA.OutputChain();    
        cout << endl;
        break;
        case 2:
        cout << "Create a chain B by adding to the front: ";
        cout << "Enter an number of items: ";
        cin >> number;
     
        for(int i = 0; i < number; i++) {
            cout << endl;
            cout <<"Enter an integer: ";
            cin >> item;
         
            ChainB.AddFrontNode(item);
        }
     
        cout << "The chain B is:";
        ChainB.OutputChain();
        cout << endl;
        break;
        case 3:
             cout<<"輸入尋找第k項(從0開始 input>k項自動爆炸)"; 
             cin>>k;
             cout<<ChainA.GetNode(k)<<" ";
             cout<<ChainB.GetNode(k);
        break;
        case 4:
             ChainA.~NodeChain();
             ChainB.~NodeChain();
        break;
        case 5:
             cin>>number;
             cout<<ChainA.IsInChain(number)<<"\n";
        break;
        case 6:
             cout<<"輸入第k位置要插入的x值:";
             cin>>k>>number;
             ChainA.Insert(k,number);
             ChainA.OutputChain();
        break;
        case 7:
             cout<<"輸入第k位置要插入的x值:";
             cin>>k>>number;
             ChainA.Delete(k, number);
        break;
        case 8:
             ChainA.GetNodeLine(odd,even);  
        break;
        case 9:
             ChainA.OutputChain();
             cout<<"\n";
             odd.OutputChain();
             cout<<"\n";
             even.OutputChain();
             cout<<"\n";
        break;     
        default:break;
        }system("pause");
    }
    return 0;
}
