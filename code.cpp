#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int menu();
void panel();
void login();
void voter();
int admin();
void panel_1();
void display();
void result();


int menu()
{
    int a;
    cout << "\n\n[1] Admin \n\n";
    cout << "[2] Voter \n\n";
    cout << "[3] Exit \n\n";
    cout << " Your Choice: ";
    cin >> a;
    return a;
}


void panel()
{
    int check = 0;
    check = menu();
    do
    {
      switch(check)
      {
        case 1:
        {
            login();
            panel();
        }
        break;
        case 2:
        {
          voter();
          panel();
        }
        break;
        case 3:
        {
          exit(0);
        }
        break;
        default:
        {
            cout<<"\nInvalid number\n";
            cin.get();
            cin.get();
            check = menu();
        }
      }
      check = menu();
    }while(check!=3);
}

void login()
{
    string uName;
    string uPass;
    system("cls");
    cout << "\n";
    cout << "-------------------------------------\n";
    cout << "\tLOGIN\n";
    cout << "-------------------------------------\n\n\n";
    cout << "Enter Username : ";
    cin>>uName;
    if(uName=="admin")
    {
      cout << "\nEnter Password : ";
      cin>>uPass;
      if(uPass=="12345")
      {
        cout<<"\nLogin successful.\n\n\n";
        panel_1();
      }
      else{
        cout<<"\nInvalid Password!";
        login();
      }
    }
    else{
      cout<<"\nInvalid Username.";
      login();
    }
}

void voter()
{
   string name;
	int i,j,ID;
	bool Id_exist=0;
	fstream file, file1;
	file.open("ID's.txt",ios::in);
	system("cls");
	cout<<"\n\nEnter Your Name : ";
	cin>>name;
	cout<<"\nEnter Your ID : ";
	cin>>ID;
	if(!(ID>=5555 && ID<=5755))
    {
        cerr<<"\nEnter a valid ID\n";
        cin>>ID;
    }
    file1.open("details.txt",ios::out|ios::app);
    file1<<" "<<name<<" "<<ID<<" \n";
    file1.close();
	int arr[200];
	for( i=0;i<200;i++)
	file>>arr[i];
	file.close();
	for( j=0;j<i;j++)
	{
		if(ID==arr[j])
		{
			arr[j]=0;
			Id_exist=1;
		}
	}
	file.open("ID's.txt",ios::out);
		for(i=0;i<200;i++)
		file<<arr[i]<<endl;
		file.close();

	int c=0,party;
	do
	{
	c++;
	cout<<"\nChoose a Party to cast your Vote \n\n";
	cout<<"1-PTI"<<endl;
	cout<<"2-PMLN"<<endl;
	cout<<"3-PPP"<<endl;
	cin>>party;
	}while((party<1 || party>3));
	int count;
	if(party==1)
	{
		file.open("PTI.txt",ios::in);
		file>>count;
		count++;
		file.close();
		file.open("PTI.txt",ios::out);
		file<<count;
		file.close();
	}
	else if(party==2)
	{
		file.open("PMLN.txt",ios::in);
		file>>count;
		count++;
		file.close();
		file.open("PMLN.txt",ios::out);
		file<<count;
		file.close();
	}
	else if(party==3)
	{
		file.open("PPP.txt",ios::in);
		file>>count;
		count++;
		file.close();
		file.open("PPP.txt",ios::out);
		file<<count;
		file.close();
	}
	cout<<"\nYour vote has been casted successfully :) "<<endl;
}

int admin()
{
     int b;
    cout << "\n\n[1] View results \n\n";
    cout << "[2] Display voters' details \n\n";
    cout << "[3] Exit \n\n";
    cout << " Your Choice: ";
    cin >> b;
    return b;
}

void panel_1()
{
    int check = 0;
    check = admin();
    do
    {
      switch(check)
      {
        case 1:
        {
            result();
            panel_1();
        }
        break;
        case 2:
        {
          display();
          panel_1();
        }
        break;
        case 3:
        {
          panel();
        }
      }
      check = admin();
    }while(check!=3);
}

void result()
{
    char res;
	int pti,pmln,ppp;
	fstream file;
    file.open("PTI.txt",ios::in);
    file>>pti;
    file.close();
    file.open("PMLN.txt",ios::in);
    file>>pmln;
    file.close();
    file.open("PPP.txt",ios::in);
    file>>ppp;
    file.close();
    system("cls");
    cout<<"\nNumber of votes casted to each party "<<endl<<endl;
    cout<<"PTI = "<<pti<<endl;
    cout<<"PMLN = "<<pmln<<endl;
    cout<<"PPP = "<<ppp<<endl;
}

void display()
{
    string name;
    int ID;
    system("cls");
    cout << "VOTERS WHO HAVE CASTED VOTES: \n\n";
    fstream file;
    file.open("details.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\t File Opening Error...";
    }
    else{
      cout<<"-----------------------------------------------\n";
      cout<<"NAME\t\t\tID\n";
      cout<<"------------------------------------------------\n\n";
      file>>name>>ID;
      while(!file.eof())
      {
        cout<<" "<<""<<name<<"\t\t"<<" "<<ID<<"\n\n";
        file>>name>>ID;
      }
      system("pause");
      file.close();
    }
}

int main()
{
	cout<<"\n\tVOTING MANAGEMENT SYSTEM\n";
	panel();
	return 0;
}
