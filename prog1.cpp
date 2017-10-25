//Lampson Nguyen
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>
using namespace std; 

// function
//Node for different type of data
struct Node  
{
    float data;
    Node* next;
};

// function
//initNode
void initNode(struct Node *head,float n)
{
    head->data = n;
    head->next =NULL;
}

// function
//apend
void addNode(struct Node *head, float n) 
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    Node *cur = head;
    while(cur) 
    {
        if(cur->next == NULL) 
        {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

// function
//display
void display(struct Node *head) 
{
    Node *list = head;
    while(list) 
    {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}
// function
//main
int main()
{
    Node * head = new Node;  
	head = new Node;
	float sum, init, info, mean,stddev;
	int counter = 0; 

	// read from text file
    ifstream txtFile("data.txt");  

	txtFile >> init;

	sum=init;

    initNode(head,init); 

	while(!txtFile.eof()) 
    {
        txtFile>>info; 
        addNode(head,info); 
		sum +=info;
		counter++;
    }

    txtFile.close();  

	display(head);

	cout<<"Sum:"<<sum <<endl;  

	mean = sum/(counter+1);

	cout<<"mean:"<<mean<<endl;

	Node *list = head;

	float subsquare, sub, sum_sub=0;

    while(list) 
    {
		cout<<list->data<<" ";
        sub = ((list->data)-mean);
		subsquare = sub*sub;
        list = list->next;
		sum_sub+=subsquare;
		cout<<"Sub: "<<sub<<" sum_sub: "<<sum_sub<<endl;
    }

	cout<<"sum_sub: "<<sum_sub;
    cout << endl;
	stddev = sqrt(sum_sub/counter);
	cout<<"standard deviation: "<<stddev<<endl;
    system("PAUSE");
    return 0;
}