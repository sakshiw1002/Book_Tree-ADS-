#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
struct dt_node
{
	char label_name[100];//points to the name given to the chapter or the section or the subsection
	int label_number;//stores the number of chapters or sections or subsections
	struct dt_node *cnode[100];//pointer part in the node
}*root;//object of the structure which indicates that a node with name root is created which consist of abve mentioned entities

class Book//creating class Book which consist of required data and operations
{
	public:
		void create();
		void display(dt_node *r1);
		Book()//creating a default constructor
		{
			root=NULL;
		}
		void menu();
};

void Book::create()
{
	int chap_cnt;//variable to count the number of nodes at a given level
	int i,j,k;//taken as counter variables for the for loops in the tree
	root=new dt_node;
	cout<<"Enter the name of the book";
	cin>>root->label_name;//Storing the name of the book in the first root(This is the root node)
	cout<<"Enter number of chapters in your book";
	cin>>chap_cnt;//Storing the number of chapters in chap_cnt
	root->label_number=chap_cnt;//Storing the input chap_cnt in the label_number of the root node
	for(i=0;i<chap_cnt;i++)//Loop which denotes the branches of the root node that is in this case denotes the chapters of the book
	{
		root->cnode[i]=new dt_node;
		cout<<"Enter the name of the chapter";
		cin>>root->cnode[i]->label_name;//stored the chapter name in the node
		cout<<"Enter the number of sections in the chapter";
		cin>>root->cnode[i]->label_number;//storing the number of sections in the chapter in the node
		for(j=0;j<root->cnode[i]->label_number;j++)
		{
			root->cnode[i]->cnode[j]=new dt_node;
			cout<<"Enter the section of the chapter";
			cin>>root->cnode[i]->cnode[j]->label_name;//stored the section name in the node
			cout<<"Enter the number of sub-sections in the chapter";
			cin>>root->cnode[i]->cnode[j]->label_number;//storing the number of sub-sections in the chapter in the node
			for(k=0;k<root->cnode[i]->cnode[j]->label_number;k++)
			{
			root->cnode[i]->cnode[j]->cnode[k]=new dt_node;
			cout<<"Enter the sub-section of the chapter";
			cin>>root->cnode[i]->cnode[j]->cnode[k]->label_name;//stored the sub-section name in the node
			}
		}
	}
}

void Book::display(dt_node *r1)
{	int i,j,k;//loop for counting
	int chap_cnt;//variable to count the number of chapters in the book
	if(r1!=NULL)//If the information is filled then only go to the next partt of printing
	{
		cout<<"\t\t-----*****BOOK HIERARCHY*****-----\n";
		cout<<"\tBOOK TITTLE\n"<<r1->label_name<<endl;
		chap_cnt=r1->label_number;
		for(i=0;i<chap_cnt;i++)
		{
			cout<<"CHAPTER\n\t"<<i+1<<r1->cnode[i]->label_name<<endl<<"\t\t";
			
			for(j=0;j<r1->cnode[i]->label_number;j++)
			{
				cout<<"SECTIONS\n\t\t\t";
				cout<<j+1<<r1->cnode[i]->cnode[j]->label_name<<endl<<"\t\t\t\t";
				;
				for(k=0;k<r1->cnode[i]->cnode[j]->label_number;k++)
				{
					cout<<"SUB-SECTION\n\t\t\t\t\t";
					cout<<k+1<<r1->cnode[i]->cnode[j]->cnode[k]->label_name<<endl;
				}
			}
		}
	}
	else
	{
		cout<<"OOPS!!!SORRY NO DATA FILLED";
	}
}

void Book::menu()
{
	cout<<"\t\t*****SELECT YOUR CHOICE*****\n";
	cout<<"1.Enter the information \n";
	cout<<"2.Print the information \n";
	cout<<"3.Exit \n";
}

int main()
{
	int choice;
	int exit_choice;
	Book b;
	do
	{
		b.menu();
		cin>>choice;
		switch(choice)
		{
			case 1:
				b.create();
				break;
			case 2:
				b.display(root);
				break;
			case 3:
				exit;
			default:
				cout<<"Enter wrong choice.....\n";
				cout<<"Enter either one or two\n";
		}
		cout<<"Do you want to continue???\n";
		cout<<"Enter 1 to continue or any other number to stop\n";
		cin>>exit_choice;
	}while(exit_choice==1);
}
			
	
			
		
		





















	
		






















	




		
