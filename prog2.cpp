//Lampson Nguyen
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

ifstream Input;
ofstream Output; 
const string FileName = "prog2.txt";
// function
//display
// display in a table in console
void display(int funcount, int funcsize[], string namelist[], int counter)
{
	cout<<"\t\tTable 1"<<endl;
	cout<<setw(65)<<setfill('-')<<"-"<<endl;
	cout<<" Program Name\t| Section Name\t | Size\t\t | Prog Size\t|"<<endl;
	cout<<setw(65)<<setfill('-')<<"-"<<endl;
	cout<<" "<<FileName<<"\t| \t\t | \t\t | \t\t|"<<endl;
	cout<<setw(65)<<setfill('-')<<"-"<<endl;
	for(int h = 0; h < funcount; h++)
	{
		cout<<"\t\t|"<<setw(14)<<setfill(' ')<<namelist[h+1]<<"\t | \t "<<funcsize[h+1]<<"\t |\t\t|"<<endl;
	}
	cout<<setw(65)<<setfill('-')<<"-"<<endl;
	cout<<" No. Funcs: "<<funcount<<"\t| \t\t | \t\t | \t"<<counter+1<<"\t|"<<endl;
	cout<<setw(65)<<setfill('-')<<"-"<<endl; 
}
// function
//counting
// the algorithm to count loc
void counting()
{
	int counter = 1, funcsize[8], funcposition[9], funcount = 0, i=0, nonfunction=0, linecount=0;
	string line, namelist[9]; 
	Output.open ("Out.txt");
	Input.open(FileName);
	funcsize[0]=0; 
	while(getline(Input,line))
	{  
		if(line == "// function") //code
		{	//Output<<"    "<<line<<endl;
			++funcount; 
			Input>>line; 
			namelist[funcount] = line;
			Output<<"\t"<<line;
			namelist[funcount].erase(0,2);  
			funcposition[funcount] = counter;     
			while(Input.eof());
		}

		else if ((line.find("//")!=-1 || line == "\0" ) || line.empty()) //code
		{ 
			if (line.find("code")!=-1 )
			{
				Output << setw(3) << setfill('0') << counter << " " << line << endl;
				++counter;	
			}
			else
			{
				Output << "    " << line << endl;
			}
		}
		else if( line.find("{")!=-1 || line.find("}")!=-1 ) //code
		{ 
			if (line.find("code")!=-1 )
			{
				Output << setw(3) << setfill('0') << counter << " " << line << endl;
				++counter;	
			}
			else
			{
				Output<<"    "<<line<<endl;
			}
		}
		else
		{ 
			Output << setw(3) << setfill('0') << counter << " " << line << endl;
			++counter;			
		}
	} 
	counter-=2;
	funcsize[funcount] = counter - funcposition[funcount];
	for(int l = funcount-1; l>=0; l--)
	{
		funcsize[l] = funcposition[l+1] - funcposition[l];
	}  
	cout<<endl; 
	display(funcount,funcsize, namelist, counter);  
	Output.close(); 
	Input.close();
}

// function
//main
// Main function
int main()
 {
	//counting("prog1.txt");
	counting();
    system("PAUSE");
    return 0;
} 