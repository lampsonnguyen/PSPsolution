//Lampson Nguyen
#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<cmath>
using namespace std; 

const int n = 10, xk = 386;
const string Est_Prox = "A.txt", Act_AddMod = "C.txt",
	         Plan_AddMod = "B.txt", Act_DevHr = "D.txt";
// function
//Node
struct Node  
{
    double data;
    Node* next;
};

// function
//initNode
void initNode(struct Node *head,double n)
{
    head->data = n;
    head->next =NULL;
}

// function
//apend
void addNode(struct Node *head, double n) 
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
//DataInput
void DataInput(string namefile, double & sum, double & sumSquare )
{
	double init, input;
	Node * head0;
	head0 = new Node;   

	// read from text file
	ifstream txtFileX(namefile);   
	txtFileX >> init; 
	sum = init; 
	sumSquare = init*init;
	initNode(head0,init);  

	while(!txtFileX.eof()) 
	{
		txtFileX>>input; 
		addNode(head0,input); 
		sum += input; 
		sumSquare += (input*input); 
	}  
	txtFileX.close();    
}

// function
//sumXY
void SumXY(string xfile, string yfile, double & sumxy)
{
	double initX, initY, inputX, inputY, xtimesy;
	Node * head0;
	head0 = new Node; 

	Node * head1;
	head1 = new Node;   

	sumxy = 0;

	// read from text file
	ifstream txtFileX(xfile);   
	txtFileX >> initX;  
	initNode(head0,initX);  
 
	ifstream txtFileY(yfile);  
	txtFileY >> initY; 
	initNode(head1,initY);  

	xtimesy = initX * initY;  
	sumxy = xtimesy; 

	while(!txtFileX.eof()) 
	{
		txtFileX>>inputX; 
		addNode(head0,inputX); 

		txtFileY>>inputY; 
		addNode(head1,inputY); 

		xtimesy = (inputX * inputY); 
		 
		sumxy += xtimesy;  
	} 

	txtFileX.close();    
	txtFileY.close();  

}

// function
//AverageY
double AverageY(double & sumY, double & aveY) 
{
	aveY = sumY/n;
	return aveY;
}

// function
//AverageX
double AverageX(double & sumX, double & aveX) 
{
	aveX = sumX/n;
	return aveX;
}

// function
//Beta1
double Beta1(double & sumXX, double & sumXY, double & aveX, double & aveY, double & beta1)
{
	beta1 = ((sumXY)-(n*aveX*aveY))/((sumXX)-(n*aveX*aveX));
	return beta1;
}

// function
//Beta0
double Beta0(double & aveX, double & aveY, double & beta1, double & beta0)
{
	beta0 = aveY - beta1*aveX;
	return beta0;
} 

// function
//Rxy
double Rxy(double & sumX, double & sumY, double & sumXX, double & sumYY, double & sumXY, double & aveX, double & aveY, double & rxy)
{
	rxy = ((n*sumXY)-(sumX*sumY))/sqrt(((n*sumXX)-(sumX*sumX))*((n*sumYY)-(sumY*sumY)));	 
	return rxy;
}

// function
//Yk
double Yk(double & beta0, double & beta1, double & yk)
{
	yk = beta0 + beta1 * xk; 
	return yk;
}

// function
//Test
void Test(int test_num, string xfile, string yfile)
{
	Node * headX; 
	double sumX, sumXX,   inputX, sumY, sumYY, inputY, sumXY, aveY, aveX, rxy, yk, beta0, beta1;
	 
	DataInput(xfile, sumX, sumXX);  
	DataInput(yfile, sumY, sumYY); 

	AverageX(sumX, aveX) ;
	AverageY(sumY, aveY) ;

	SumXY(xfile, yfile, sumXY);
	 
	Beta1(sumXX, sumXY, aveX, aveY, beta1);
	Beta0(aveX, aveY, beta1, beta0);

	Rxy(sumX, sumY, sumXX, sumYY, sumXY,aveX, aveY, rxy);

	Yk(beta0, beta1, yk);  
	cout<<fixed<<setprecision(6)<<"Test "<<test_num<<"\t\t"<<beta0<<"\t"<<beta1<<"\t"<<rxy<<"\t"<<rxy*rxy<<"\t"<<yk;
	cout<<endl;
 
}
	
// function
//main
int main()
{
	string A, B, C, D;
	A = Est_Prox;
	B = Plan_AddMod;
	C = Act_AddMod;
	D = Act_DevHr;
	 
	cout<<"Test\t\t\t\t\tExpected Values"<<endl<<endl;
	cout<<"\t\t B0\t\t B1\t\t r(xy)\t\t r2\t\t yk "<<endl<<endl;
	Test(1,A,C);
	Test(2,A,D);
	Test(3,B,C);
	Test(4,B,D); 
	 
	system("PAUSE");
	return 0;
}