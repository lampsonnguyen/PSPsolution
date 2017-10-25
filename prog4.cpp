#include <iostream>
#include <fstream>
using namespace std; 

ifstream inPut("Text.txt");   
ifstream inPut1("Text1.txt");   
ofstream outPut("Out.txt");

struct Node {
	double val;
	Node *next;
    Node(double x) : val(x), next(NULL) {}
};

Node * Add(Node *head, double d)
{
	Node *temp = new Node(d);
	temp->next = head;
	return temp;
}

void Print(Node *head)
{
	double dat;
	cout<<"Ascending Sort \n";
	while( head )
	{
		cout << head->val << " ";
		dat = head->val;
		outPut<<dat<<endl;
		head = head->next;
	}
	cout << endl; 
}
Node * SortedInsert(Node * head, Node *newNode )
{
	//special case: newnode to be added as first node
	if( head == NULL || head->val >= newNode->val)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}	
	Node *pointer = head;
	Node *prev = NULL;
	while ( pointer != NULL && pointer->val < newNode->val )
	{
		prev = pointer;
		pointer = pointer->next;
	}
	newNode->next = pointer;
	prev->next = newNode;
	return head;
}

Node* InsertionSort(Node *head)
{
	if( !head || !head->next )
		return head;
		
	Node * pointer = head->next;
	Node * result = head;
	result->next = NULL;

	while ( pointer )
	{
		Node *temp = pointer;
		pointer = pointer->next;
		result = SortedInsert(result,temp);
	}
	
	return result;
}

void initNode(struct Node *head, double n)
{
    head->val = n;
    head->next = NULL;
}

void firstSort()
{
	double init, input;
	Node *head = new Node(9);
	 
	inPut >> init; 
	initNode(head,init);  

	while(!inPut.eof()) 
	{
		inPut>>input; 
		head = Add(head,input);
	}  
	head = InsertionSort(head);
	Print(head);
	inPut.close();  
}

void secondSort()
{
	double init, input;
	Node *head1 = new Node(9);
	 
	inPut1 >> init; 
	initNode(head1,init);  

	while(!inPut1.eof()) 
	{
		inPut1>>input; 
		head1 = Add(head1,input);
	}  
	head1 = InsertionSort(head1);
	Print(head1);
	inPut1.close(); 
}

int main()
{ 
	outPut<<"\tObject LOC sort in ascending order\n";
	cout<<"Object LOC sort in ";
	firstSort();
	outPut<<"\n\tLOC/Method sort in ascending order\n";
	cout<<"\nLOC/Method sort in ";
	secondSort();

	system("pause");
	return 0;
}