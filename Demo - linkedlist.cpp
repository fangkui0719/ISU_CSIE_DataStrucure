#include <iostream>

using namespace std;

template <class T>
class Node 
{
	public:
		T data;
		Node<T> *link;
};

template <class T>
class NodeChain 
{
	public:
		NodeChain() 
        {
			Last = new Node<T>;
			Last -> data = 0;
			Last -> link = 0;
			First = PreLast = Last;
		};
		~NodeChain();
		T NextNode(T x);
		T GetFirst() {return First -> data;}
		T GetNode(int k);
		NodeChain<T>& AppendNode(const T& x);	
		NodeChain<T>& AddFrontNode(const T& x);
		NodeChain<T>& Insert(int k, const T& x);
		NodeChain<T>& Delete(int k, T& x) const;
		void OutputChain();
		bool IsInChain(T x);
	private:
		Node<T> *First;
		Node<T> *Last;
		Node<T> *PreLast;
};

template <class T>
NodeChain<T>::~NodeChain() 
{
	Node<T> *next;
	while(First != Last) 
    {
		next = First -> link;
		delete First;
		First = next;
	}
	delete Last;
}

template <class T>
T NodeChain<T>::GetNode(int k) 
{
	int i = 0;
	Node<T> *current = First;

	while(i < k) 
    {
		current = current -> link;
		i++;
	}

	return current -> data;
}

template <class T>
T NodeChain<T>::NextNode(T x)
{
	Node<T> *current = First;
	
	while(current != Last && current -> data != x) 
		current = current -> link;
	
	if(current == Last || current == PreLast) return Last -> data;
	else 
    {
		current = current -> link; 
		return current -> data;
	}
}

template <class T>
NodeChain<T>& NodeChain<T>::AppendNode(const T& x)
{
	Node<T> *y = new Node<T>;
	y -> data = x;
	y -> link = Last;

	if(First != Last) 
    {
		PreLast -> link = y;
		PreLast = y;
	}
	else
    { 
		First = y; 
		PreLast = y;
	}
		
	return *this;
}

template <class T>
NodeChain<T>& NodeChain<T>::AddFrontNode(const T& x) 
{
	Node<T> *y = new Node<T>;
	y -> data = x;
	y -> link = First;
	First = y;
	
	return *this;
}

template <class T>
void NodeChain<T>::OutputChain() 
{
	Node<T> *temp = First;

	while(temp != Last) 
    {
		cout << temp -> data << " ";
		temp = temp -> link;
	}
}

template <class T>
NodeChain<T>& NodeChain<T>::Insert(int k, const T& x) 
{
       if(k < 0) 
       {
	   		cout << "k < 0, Error!" << endl;
			return *this;
	   }
	   
       Node<T> *p = First;
       
       for(int index = 1; index < k && p; index++) p = p -> link;
       if(k > 0 && !p) 
       {
	   		cout << " k out of the range" << endl;
			return *this;
	   }
	   
       NodeChain<T> *y = new Node<T>;
       y -> data = x;
        if(k) 
        {
            y -> link = p -> link;
            p -> link = y;
        }
        else 
        {
                y -> link = First ->link; 
                First ->link = y;
        } 
        return *this;
}

template <class T>
NodeChain<T>& NodeChain<T>::Delete(int k, T& x) const 
{
      if(k < 1 || !First)
      {
	        cout << " k out of the range" << endl;
			return *this;
	  } 
	   
      Node<T> *p = First;
      
      if(k == 1) First -> link = First -> link -> link ;
      else 
      {
            Node<T> *q = First -> link ;
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
bool NodeChain<T>::IsInChain(T x) 
{
	Node<T> *temp = First;

	while(temp) 
    {
		if(x == temp -> data) return true;
		else temp = temp -> link;
	}
	return true;
}

int main() 
{
    int number, item;
    NodeChain<int> ChainA, ChainB;
    
    cout << "Create a chain A by appending items: " << endl;
    cout << "Enter an number of items: ";
    cin >> number;
    
    for(int i = 0; i < number; i++) 
    {
        cout << endl;
        cout <<"Enter an number: ";
        cin >> item;
        
        ChainA.AppendNode(item);        
    }
    
    cout << "The chain A is:";
    ChainA.OutputChain();    
    cout << endl;
    
    cout << "Create a chain B by adding to the front: ";
    cout << "Enter an number of items: ";
	cin >> number;
    
    for(int i = 0; i < number; i++) 
    {
        cout << endl;
        cout <<"Enter an integer: ";
        cin >> item;
        
        ChainB.AddFrontNode(item);        
    }
    
    cout << "The chain B is:";
	ChainB.OutputChain();
    cout << endl;
    system ("pause");    
    return 0;
}
