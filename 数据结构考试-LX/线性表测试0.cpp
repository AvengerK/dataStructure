/*
   ��������ĿĿ���ǹ��̵��������ز���
   ���������todoע�͵ĳ�Ա�����Ķ���,��Ӧ�����Ѿ�ע��
   ����main�е���ʾ�Ĳ��Բ�������ɸ�����Ա�����Ĳ���

    ѭ�򽥽�,�����������,�������˼ά
*/

#include <iostream>
#include<stack>
using namespace std;
/* ջ���忪ʼ  */

template <class T>
class Stack{
public:
	Stack(int MaStackSize=10);
	~Stack() { delete [] stack;}
	bool IsEmpty() const {return top==-1;}
	bool IsFull() const {return top==MaxTop;}
	T Top() const;
	bool push(const T& x);
	bool pop(T& x);
	void MakeEmpty(){top=-1;} //���ջ
private:
	int top;//ջ��
	int MaxTop;//����ջ��ֵ
	T *stack;//��ջԪ������
};
template<class T>
Stack<T>::Stack(int MaxStackSize)
{
	MaxTop=MaxStackSize-1;
	stack=new T[MaxStackSize];
	top=-1;
}

template<class T>
T Stack<T>::Top() const
{
	if(IsEmpty())
	{cout<<"no element";return -1;}
	else
		return stack[top];
}
template<class T>
bool Stack<T>::push(const T& x)
{
	if(IsFull())
	{cout<<"no memory;"<<endl;return false;}
	top=top+1;
	stack[top]=x;
	return true;
}
template<class T>
bool Stack<T>::pop(T& x)
{
	if(IsEmpty())
	{cout<<"no element"<<endl;return false;}
	x=stack[top];
	top=top-1;
	return true;
}
/*  ջ�������   */
//////////////////////////////////////////////////////////////
/*  �����忪ʼ  */
class Node  //����������
{
public:
	int data;  //�������
	Node* next; //��ź�̽���ַ
	Node(int val,Node* ptr = 0)  //���캯��,��ʼ�����ݳ�Ա
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node* head; //��¼��ͷ����ַ

	List()
	{
		head = new Node(0,0);//������б�ͷ���Ŀյĵ�������
	}
	void insertToHead(int x)
	{
		//���ͷ��������ֵΪx�Ľ��
		Node* newNode = new Node(x,0);
		newNode->next = head->next;
		head->next = newNode;
	}

	~List()
	{
		//todo: 1-�ͷ���������н��
		Node* p=head;
		Node* q;
		while(p){
			q=p;
			p=p->next;
			delete q;
		}
	}
	void print()
	{
		// todo: 2-�����������ĸ�����������ֵ
		Node *p=head;
        while(p->next)
        {
            cout<<p->next->data<<" ";
            p=p->next;
        }
        cout<<endl;
	}
	void moveMinToFirst()
	{
		//todo:3-��������������ֵ��С���Ǹ�������Ƶ��������ǰ�档
		//Ҫ�󣺲��ö��������µ������
		Node *p=head;
        Node *p2=head;
		int num=p->next->data;

		Node *pmin=p->next ;

		while(p->next)
        {
            if(num>p->next->data)
            {
                num=p->next->data;
                pmin=p->next;
            }
            p=p->next;
        }

        while(p2->next!=pmin)
        {
            p2=p2->next;
        }
        p2->next=p2->next->next;
        p=head->next;
        head->next=pmin;
        pmin->next=p;
	}
	void delItem(int val)
	{
		//todo:4-ɾ����һ������ֵΪval�Ľ��
		Node *p1=head;
		while(p1->next->data!=val)
        {
            p1=p1->next;
        }
        Node *pde=p1->next;
        p1->next=pde->next;
        delete pde;
	}
	void reverse()
	{
		//todo:5-����ջ��������Ľ�㷴ת
		 stack<Node*>a;
        Node *p1=head;
        while(p1->next)
        {
            a.push(p1->next);
            p1=p1->next;
        }
        p1=a.top();
        Node *p2=p1;
        a.pop();
        while(!a.empty())
        {
            p1->next=a.top();
            a.pop();
            p1=p1->next;

         //   cout<<1<<endl;
        }
        p1->next=NULL;
      //  cout<<2;
        head->next=p2;
	}
};
/*  ���������  */
////////////////////////////////////////

/* main���Կ�ʼ  */
int main()
{
	List mylist;

	//���벹��: ѭ������insertToHead������mylist���������
	int num;
    cin>>num;
    while(num>0)
    {
        mylist.insertToHead(num);
        cin>>num;
    }

	/* ���濪ʼ���Ը�����Ա����,
	������ʵ��ÿ������Ŀ���ʱ��ע�͵�Ϊ�����������Ŀ�����ӵĴ���*/

	//����Ŀ��1: ������������----��������κδ���

	//����Ŀ��2:����print����
	  //   mylist.print();

	//����Ŀ��3:���� moveMinToFirst����,ִ�� moveMinToFirst������print���������鿴
	//mylist.moveMinToFirst();
	   //  mylist.print();

	//����Ŀ��4:����delItem����,ִ�� delItem������print���������鿴
	//mylist.delItem(3);
    //mylist.print();

	//����Ŀ��5:����reverse����,ִ��reverse������print���������鿴
	 mylist.reverse();
    mylist.print();

}
/* main���Խ���  */
