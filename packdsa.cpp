#include<iostream>
#include<cstdlib>
#include<limits.h>
#include<time.h>
using namespace std;
//-------------------------------------------------------------HASH TABLE FOR SEARCHING A PARTICULAR PERSON'S DETAILS------------------------------------------------------------------------
const int SIZE = 100; // size of the hash table
struct Person_details
{
    string name;
    int phonenumber;
    string address;
};
class HashTable
{
	private:
    	Person_details table[SIZE]; // the hash table
	public:
    	int hashing(string key); //  converting  a key to an index
    	void insert(string key, Person_details p);
    	Person_details search(string key); // search for a person in the hash table
};
int HashTable::hashing(string key)
{
    int val = 0;
    for (int i = 0; i < key.length(); i++)
    {
        val += key[i];
    }
    return val % SIZE;
}

void HashTable::insert(string key, Person_details p)
{
    int index = hashing(key);
    table[index] = p;
}

Person_details HashTable::search(string key)
{
    int index = hashing(key);
    return table[index];
}

//----------------------------------------------------------------------------CALL LOGS--------------------------------------------------------------------------------
struct nodex
{
        string name;
	string phone_number;
	string time;
        struct nodex *lchild,*rchild;
};
class tree
{
        public:
        struct nodex *root,*N;
        void create(string,string,string);
        void insert(string,string,string);
        void inorder(struct nodex *p);//to display the call history

};
void tree::create(string a,string b,string c)//creating the root
{
        struct nodex *N=new nodex;
        N->name=a;
	N->phone_number=b;
	N->time=c;
        N->lchild=NULL;
        N->rchild=NULL;
        root=N;
}
void tree::insert(string a,string b,string c)//inserting the calls
{
        struct nodex *prev;
        struct nodex *ptr1=root;
        while(ptr1!=NULL)
        {
                if(ptr1->time<c)
                {
                        prev=ptr1;
                        ptr1=ptr1->rchild;
                }
                else
                {
                        prev=ptr1;
                        ptr1=ptr1->lchild;
                }
        }
	if(prev->time <c)
        {
                struct nodex *N=new nodex;
		N->name=a;
		N->phone_number=b;
                N->time=c;
                N->lchild=NULL;
                N->rchild=NULL;
                prev->rchild=N;
        }
        else
        {
                struct nodex *N=new nodex;
                N->name=a;
		N->phone_number=b;
		N->time=c;
                N->lchild=NULL;
                N->rchild=NULL;
                prev->lchild=N;
        }
}
void tree::inorder(struct nodex *p)//displaying the call history using inorder traversal
{
        if(p!=NULL)
        {
                inorder(p->lchild);
                cout<<p->name<<"\t\t\t"<<p->phone_number<<"\t\t\t"<<p->time<<"\n";
                inorder(p->rchild);
        }
}
//--------------------------------------------------STACK TO DISPLAY NOTIFICATIONS  IN LATEST-FIRST ORDER-------------------------------------------------------------
class stackx {
    private:
            int top;
            int n;
            string s[100];
    public:
            stackx()
            {
                top=-1;
                n=10;
            }
            void push(string elt);
            void topi();
            void display();
};
void stackx::push(string elt) {
    if(top==n)
    {
        cout<<"Too many notifications\n";//limit for the notification in 10
    }
    else
    {
        top++;
        s[top]=elt;
    }
}
void stackx::display()//displaying the notifications
{
    cout<<"_________________________________________________________________NOTIFICATIONS_____________________________________________________________________\n";
    while(top>-1)
    {
        cout<<"\t\t\t\t\t\t\t\t"<<s[top]<<"\n";
        top--;
    }
}
void stackx::topi()//it is used to display the latest notification
{
        int v=top;
        cout<<"\t\t"<<s[top+1]<<"\n";
}
//------------------------------------------------------LINKED LIST IS USED TO ENTER INTO ANY NOTIFICATION------------------------------------------------------
struct node
{
	int nuva;
        string appname;
	string content;
        struct node*link;
};
struct node *start,*ptr;
class lil
{
        string x;
        public:
        void create();
        void insend(string,string,int);
        void display();
	void search(int);
};
void lil::create()
{
        struct node *N=new node;
        N->appname="NOTIFICATIONS";
	N->nuva=0;
	N->content="  ";
        N->link=NULL;
        start=N;
}
void lil::display()
{
        ptr=start;
        while(ptr!=NULL)
        {
                cout<<ptr->appname<<":\t\t\t"<<ptr->content<<"\n";
                ptr=ptr->link;
        }
}
void lil::insend(string a,string b,int c)
{
        struct node *N=new node;
        ptr=start;
        while(ptr->link!=NULL)
        {
                ptr=ptr->link;
        }
	N->nuva=c;
        N->appname=a;
	N->content=b;
        N->link=NULL;
        ptr->link=N;
}
void lil::search(int x)//search the particular app and display its respective message
{
	int f=0;
        ptr=start;
       	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
		if(ptr->nuva==x)
		{
			f++;
			cout<<"___________________________________________________________"<<ptr->appname<<"___________________________________________________________________________\n";
			cout<<" \t\t\t\t\t\t\tWELCOME\n";
			cout<<"NOTIFICATION:\t"<<ptr->content<<"\n";
		}
	}
	if(f==0)
	{
		cout<<"NO NOTIFICATIONS FROM THE APP\n";
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
        stackx obs;
	lil obl;
        string choice;
        int i,num,n;

	obl.create();//creating object for linked list


        string Noti[]={"App store","Clock","Duolingo","Google","Instagram","LinkedIn","Mail","Swiggy","WhatsApp","YouTube"};
	string act[]={"app update","\ttime over","finish your daily task","\tlatest news","trending reels",
			"job alerts","mail from your husband","fall in love with food","gopal has sent you a msg","new vedio posted"};
	int renu[]={1,2,3,4,5,6,7,8,9,10};


        for(i=0;i<10;i++)
        {
        	int m=rand()%5;
                obs.push(Noti[m]);
		obl.insend(Noti[m],act[m],renu[m]);//passing the values to store in linked list
        }
	obs.display();//stack display


        cout<<"The latest notification is:";
        obs.topi();
	obl.display();//lil display


	cout<<"DO YOU WANT TO ENTER INTO ANY NOTIFICATION?";
	cin>>choice;
	if(choice=="yes"||choice=="YES")
	{
		for(i=0;i<=10;i++)
		{
			cout<<i+1<<"\t"<<Noti[i]<<"\n";
		}
		cout<<"enter the respective number";
		cin>>num;
		obl.search(num);
	}
	//------------------------------------------------------------------------------------------------------------------------------------------------------------
	int x;                                                                          //call log history
	cout<<"\nDO YOU WANT TO CHECK YOUR CALL HISTORY?enter 1\n";
	cin>>x;
	if(x==1)
	{
		string a,b,c;
        	tree ob;
        	ob.create("NAME","PHONENUMBER"," ");
        	cout<<"enter the number of  call details that you have to check";
        	cin>>n;
		string callname[]={"induja","harshitha","vedha","vana","ramya"};          //random generation of inputs
		string callnum[]={"123","345","567","789","145"};
		string calltime[]={"12am","12pm","4pm","6pm","1am"};
        	for(i=0;i<n;i++)
        	{
                	int v=rand()%5;
                	ob.insert(callname[v],callnum[v],calltime[v]);
        	}
        	cout<<"\n---------------------------------------------------------------HISTORY------------------------------------------------------------------------------\n";
        	ob.inorder(ob.root);
	}
	//hashtable person details
	int z;
	cout<<"DO YOU WANT TO SEARCH FOR A PARTICULAR PERSONS DETAIL?enter 1\n";
	cin>>z;
	if(z==1)
	{
		HashTable ht;
    		Person_details p1 = {"ramya",997867880, "Laxmi nagar,tiruppur"};
    		Person_details p2 = {"ridu vadhana",882765467, "kumar nagar,coimbatore"};
		Person_details p3 = {"rithika",997867560, "SAP nagar,tiruppur"};
		Person_details p4 = {"Arvik",9978674350, "ram nagar,vellore"};
		Person_details p5 = {"kavya",990067800, "new bus stand,avinashi"};
    		ht.insert(p1.name, p1);
    		ht.insert(p2.name, p2);
		ht.insert(p3.name, p3);
		ht.insert(p4.name, p4);
		ht.insert(p5.name,p5);
		cout<<"\n----------------------------------------------------PERSON NAMES\n";
		cout<<"\n"<<p1.name<<"\n"<<p2.name<<"\n"<<p3.name<<"\n"<<p4.name<<"\n"<<p5.name<<"\n";
    		string name;
    		cout << "Enter a name to search for: ";
    		cin >> name;
    		Person_details result = ht.search(name);
    		cout << "Name: " << result.name << endl;
    		cout << "Phone Number: " << result.phonenumber << endl;
    		cout << "Address: " << result.address << endl;
	}


}
