#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<cstring>
#include<ctime>
#include<conio.h>
#include "Bank.h"
#include<stdlib.h>
using namespace std;

void Automactic_interest_calculator()
{
	double int_rate = 0.02; 
    double interest = 0;
    Customer c1;
    char ch;
    int c = 0;
   // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);
    int day,year,month;
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
  
    fstream file;
    
    file.open("Customer_detail.txt",ios :: in | ios :: out | ios :: ate);
    file.seekg(0);

    file.read((char *)&c1, sizeof(c1));
   	int start = file.tellp();
    
    while(!file.eof())
    {
    	if(strcmp(c1.get_accountType(),"current") == 0)
    	{
    		if(c1.get_day() == day && (c1.get_month() + 1) == month)
    		{
             	interest = ((c1.get_balance() * int_rate) / 12);
 	            
				int pointer = file.tellp();
				int set = pointer - start + c;
	    	    file.seekp(set);
	    	    file.write((char *)&c1, sizeof(c1));
	    	    cout << "\n\tTransaction Successfull.\n";
	    	    file.close();
			}
		}
		c++;
    	file.read((char *)&ch, sizeof(ch));
    	file.read((char *)&c1, sizeof(c1));
	}
}
void FrontPage()
{
    char s1[ ] = "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     **********************************************************";
    int i;
    for(i=0;i < 79;i++)
    {
         cout<<s1[i];
         Sleep(10);
    }

    char s2[ ] = "\n\t\t\t     *\t\t\t\t\t\t\t      *";

    for(i=0;i < 24;i++)
    {
         cout<<s2[i];
         Sleep(10);    
    }
    
    char s3[ ] = "\n\t\t\t     *\t\t   ******************************\t      *";
    for(i=0;i < 54;i++)
    {
         cout<<s3[i];
		 Sleep(10);    
    }
    
	char s4[ ] = "\t\t\t     *\t\t\t\t\t\t\t      *";
    for(i=0;i < 24;i++)
    {
         cout<<s4[i];
         Sleep(10);
    }
    
    char s5[ ] = "\n\t\t\t     *\t\t\t\t\t\t\t      *";
    for(i=0;i < 24;i++)
    {
         cout<<s5[i];
         Sleep(10);
    }
    cout << "\n\t\t\t     *\t\t        Welcome to Bank\t\t\t      *";
    char s6[ ] = "\n\t\t\t     *\t\t\t\t\t\t\t      *";
    for(i=0;i < 24;i++)
    {
         cout<<s6[i];
         Sleep(10);
    }
    cout << "\n\t\t\t     *\t\t\t   Management system    \t\t      *";
    char s7[ ] = "\n\t\t\t     *\t\t\t\t\t\t\t      *";
    
    for(i=0;i < 24;i++)
    {
         cout<<s7[i];
		 Sleep(10);   
	}
	
    char s8[ ] = "\n\t\t\t     *\t\t   ______________________________\t      *";
    for(i=0;i < 54;i++)
    {
         cout<<s8[i];
		 Sleep(10); 
    }
    
    char s9[ ] = "\n\t\t\t     *\t\t\t\t\t\t\t      *";
    for(i=0;i < 24;i++)
    {
         cout<<s9[i];
		 Sleep(10);    }
    cout << "\n\t\t\t     >          Place where you come first    <"<<endl;
    
    char s10[ ] = "\n\t\t\t     **********************************************************\n\n\n";
    for(i=0;i < 68;i++)
    {
         cout<<s10[i];
 		Sleep(10); 
    }
}


void gotoxy( int x, int y )
{
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}
void Loading()
{
	    char ch1;
	ch1 = 177;
	
	gotoxy(0,28);
	for(int i = 0; i<115; i++)
	{
		cout << ch1;
	//	Sleep(500);
	}
	char ch2 = 219;

	gotoxy(0,28);
	for(int i = 0; i<115; i++)
	{
		cout << ch2;
		Sleep(10);
	}
	
	cout << endl << "\t\t\t\t\tEnter any Key to Continue.\n";

}
  

int Login_menu()
{
    int choice;
    getch();
	system("cls");
	gotoxy(40,5);
	cout << "1) Employee Login.\n";
	cout << "\t\t\t\t\t2) Customer Login.\n";
    cout << "\t\t\t\t\t0) Exit";
	cout << "\nEnter your choice : ";
    cin >> choice;
   return choice;
}


int Employee_menu()
{
    int choice;
    getch();
	system("cls");
	cout << "1) Open Account.\n"
         << "2) Close Account.\n"
         << "3) To View All CustOmer details.\n"
         << "4) To View All Transaction.\n"
         << "5) Change Password.\n";
    cout << "Enter Your Choice : ";
	cin >> choice;
	return choice;
}

int account_menu()
{
	int choice;
    getch();
	system("cls");
	cout << "1) To Withdraw.\n"
	     << "2) To Deposit.\n"
	     << "3) To View Account Details.\n"
	     << "4) To View Transaction.\n"
	     << "5) To View Ramaining Balance.\n"
	     << "6) Close Account.\n"
	     << "7) Change Password.\n"
	     << "0) To Exit.\n";
 
    cout << "Enter Your Choice : ";
	cin >> choice;
	return choice;
}

char* current_time()
{
	time_t tm;
	tm = time(NULL);
	char* str = ctime(&tm);
     return str; 
}

void Address:: set_Address()
{
	cin.ignore();
	cout << "Street : ";
	cin.getline(street,19);
	
	cout << "City : ";
	cin.getline(city,19);
	
	cout << "Country : ";
	cin.getline(country,19);
	
	cout << "State : ";
	cin.getline(state,19);
	
	cout << "Zip Code : ";
	cin.getline(zip,19);
}

void Address:: set_street(char *street)
{
	strcpy(this->street,street);
}

void Address:: set_city(char *city)
{
    strcpy(this->city,city);	
}

void Address:: set_country(char *country)
{
    strcpy(this->country,country);	
}

void Address:: set_state(char *state)
{
	strcpy(this->state,state);
}

void Address:: set_zip(char *street)
{
    strcpy(this->zip,zip);	
}	

void Address:: Display_Address()	
{
	cout << "Address : \n\n";
	cout << "\tStreet : " << street;
	cout << "\n\tCity : " << city;
	cout << "\n\tCountry : " << country;
	cout << "\n\tState : " << state;
	cout << "\n\tZip Code : " << zip << endl;
}

void Customer :: set_date(int d,int m, int y)
{
	day = d;
	month = m;
	year = y;
}

int Customer :: get_day()
{
	return day;
}
		
int Customer :: get_month()
{
	return month;
}

int Customer :: get_year()
{
	return year;
}

void Person :: set_person()
{
   cin.ignore();
   cout << "Enter First Name : ";
   cin.getline(f_name,14);
   
   cout << "Enter Last Name : ";
   cin.getline(l_name,14);
   
   A.set_Address();
   
   cout << "Enter Phone NO. : ";
   cin >> phoneNo;

}

char * Person :: get_f_name()
{
	return this->f_name;
}
char * Person :: get_l_name()
{
	return this->l_name;
}

char * Person :: get_nic()
{;
	return this->nic;
}

long long Person :: get_phone_no()
{
    return this->phoneNo;	
}	

void Person :: Display_per()
{
	cout << "First  Name : " << f_name << endl
         << "Last  Name : " << l_name << endl;
         A.Display_Address();
    cout << "NIC  N0. : " << nic << endl
  		 << "Phone N0. : " <<phoneNo << endl;
 }

void Customer :: Display()
{
	
}

int Account_No()
{
	ifstream fin;
	Customer c1;
	char ch;

	fin.open("Customer_detail.txt",ios::in | ios::app);
	if(!fin)
	{
        cout << "\n\tFile Doesnot Exist.\n";
	}
	else
	{
		fin.seekg(0);
	    fin.read((char *)&c1,sizeof(c1));

	    while(!fin.eof())
	    {
	       fin.read((char *)&ch,sizeof(ch));
	       fin.read((char *)&c1,sizeof(c1));
 		}
        return (c1.get_accountNo() + 1);
    }
}


void  Login :: set_login()
{
  	cout << "Enter PIN : ";
    cin >> id;
    cout << "Enter the Password : ";
    cin >> pass;
}

void Login :: set_id_pass(int id_temp, char* pass_temp)
{
    this->id = id_temp;
	strcpy(pass,pass_temp);	
}

int Login :: get_id()
{
	return this->id;
}

char* Login :: get_pass()
{
	return this->pass;
}

int Login :: check_access()
{
	Login l1;
	char ch;
	ifstream fin;
	fin.open("password.txt", ios::in);
	if(!fin)
	{
		cout << "\n\tFile doesnot exist\n";
	}
	else
	{
		fin.seekg(0);
        fin.read((char *)&l1, sizeof(l1));
		while(!fin.eof())
		   {
				if(l1.get_id() == this->id && (strncmp(l1.pass, this->pass,4)==0))
				 {
					cout << "\n\tLogin Succcessful.\n";
					fin.close();
					return 1;
				 }
			
			fin.read((char *)&ch, sizeof(ch));	 
			fin.read((char *)&l1, sizeof(l1));
				 
		   }
	}
	
	    cout << "\n\tLogin Unsuccessful.\n";
	    fin.close();
	    return 0;
}

void Login :: change_password(Login &t)
{
	char ch;
	Login temp;
	int c = 0,choice = 0;

	char pass_temp[4],new_pass[4] ,con_temp[4];
    label : 1;
	cout << "Enter the Old Password : ";
	cin>>pass_temp;
	
	if(strncmp(pass_temp,t.get_pass(),4)==0 )
	{
	    cin.ignore();
		cout << "Enter the New Password : ";
		cin >> con_temp;
		
	    cout << "Confiramtion Password : ";
	    cin >> new_pass;
	    
	    cout << pass_temp;
 
	    if(strncmp(new_pass,con_temp,4)==0)
	    {
	        fstream login;
		    login.open("Password.txt",ios :: in | ios :: out| ios :: ate);
		    login.seekg(0);
		    
		    login.read((char *)&temp,sizeof(temp));
		    int start = login.tellg();
	    	while(!login.eof())
	    	{
	    		if(temp.get_id() == t.get_id())
                {
				    temp.set_id_pass(temp.get_id(),con_temp);
					int pointer = login.tellp();
					int set = pointer - start + c;
		    	    login.seekp(set);
		    	    login.write((char *)&temp, sizeof(temp));
		    	    cout << "\n\tPassword Successfully changed.\n";
		    	    login.close(); 
			    }
			    c++;
			    login.read((char *)&ch,sizeof(ch));
	            login.read((char *)&temp,sizeof(temp));
            }
	    }
		else
		{
			cout << "1) To Re_enter Password : \n"
		         << "2) To Exit.\n";
		    cin >> choice;
		}
	}
	else
	{
		cout << "1) To Re_enter Password : \n"
		     << "2) To Exit.\n";
		cin >> choice;     
	}
	if(choice == 1)
	{
		choice = 0;
		goto label;
	}
	else
	{
		return;
	}  
}

Customer :: Customer()
{
	strcpy(accountType,"NULL");
	balance = 0;
	account_no = 99;
	request = 0;
	strcpy(pass,"");
	day=month=year=0;
	
	
}

void Customer :: set_password()
{
	ofstream fout;
	Login l1;
	char ch = '\n';
	char temp_pass[4];
	cout << "Enter the Password : ";
	cin>>pass;
    cout << "Confiramtion Password : ";
    cin >> temp_pass;

	while(strcmp(pass,temp_pass)!=0)
	{
	cout << "Enter the Password : ";
	cin>>pass;
    cout << "Confiramtion Password : ";
    cin >> temp_pass;
	}
	
	fout.open("password.txt", ios :: out | ios :: app);
	if(!fout)
	{
		cout << "File doesnot Exist.\n";
	}
	else
	{
		l1.set_id_pass(this->account_no,this->pass);
		fout.write((char *)&l1,sizeof(l1));
		fout.write((char *)&ch, sizeof(ch));
	    fout.close();
	}
}
Customer :: ~Customer()
{
}

void Customer :: set_balance(double temp_balance, int trip = 0)
{
	if(trip == 1)
	  this->balance += temp_balance;
	else
	if(trip == 0)
	  this->balance -= temp_balance;
}

int Customer :: get_accountNo()
{
	return this->account_no;
}

char* Customer :: get_accountType()
{
	return this->accountType;
}

double Customer :: get_balance()
{
	return this->balance;
}

char* Customer :: get_pass()
{
	return this->pass;
}

void Customer :: set_request(int s)
{
	request = s;
}

int Customer :: get_request()
{
	return request;
}

void Customer :: set_customer()
{
	Person :: set_person();
	cin.ignore();
	cout << "Enter Which Account Type (saving/current) : ";
	
	cin.getline(accountType,19);

	strcpy(accountType,strlwr(accountType));

	while(!(!strcmp(accountType, "saving") || !strcmp(accountType, "current")))
	{
		cout << "Enter Correct Account Type (saving/current) : ";
//		cin.ignore();
		cin.getline(accountType,19);
	}
	
	cout << "Enter Primary Balance greater than (1000) : ";
	cin >> balance;
	
	while(balance < 1000)
	{
		cout << "Primary Balance Should Be atleast 1000 : ";
		cin >> balance;
	}
	
	this->account_no = Account_No();
	cout << account_no << endl;
	this->set_password();
	cout << "\n\tThankYou Sir.\n";
}

Employee :: Employee()
{
	c1 = new Customer;
}


Employee :: ~Employee()
{
	delete c1;
}


void Employee :: open_account()
{
	Customer c1;
	c1.set_customer();
	char ch = '\n';
	ofstream fout;
	fout.open("Customer_detail.txt",ios::out | ios::app);
	if(!fout.is_open())
	{
		cout << "\n\t\tFile doesnot Exist.\n";
	}
	else
	{
		fout.write((char *)&c1, sizeof(c1));
		fout.write((char *)&ch,sizeof(ch));
		fout.close();
	}
}

void Employee :: close_account()
{
        char close[3],check = 0; 
        ifstream in;
 	    in.open("Request.txt", ios :: in);
 	     int temp = 0;

 	   if(!in.eof() && in)    
	 	{ 	
	 	   in >> close[0] >> close[1] >> close[2];
	 	   
	 	   temp = close[0] - 48;
	 	   temp = (temp *10) + (close[1] - 48);
	 	   temp = (temp *10) + (close[2] - 48);
	 	   		    
		  while(!in.eof())  
           {
			    ofstream fout;
			    ifstream fin;
    
	            fin.open("customer_detail.txt",ios::in);
			    fin.seekg(0);
	            fout.open("temporaryfile.txt",ios::out | ios::app);	
		        char ch;

		     fin.read((char *)c1,sizeof(*c1)); 
		  
		   while(!fin.eof())
	           {
		  	     if(temp != c1->get_accountNo())
		      	    {
		      	    	   
						  fout.write((char *)c1,sizeof(*c1));
			        	  fout.write((char *)&ch,sizeof(ch));
		      	    }
   	    
		    	    fin.read((char *)&ch,sizeof(ch));
		    	    fin.read((char *)c1,sizeof(*c1));
		        }
				          
				   fout.close();
				   fin.close();
			       remove("Customer_detail.txt");
			       rename("temporaryfile.txt","Customer_detail.txt");
			       
			       in >> ch;
			       in >> close[0] >> close[1] >> close[2];

			 	   temp = close[0] - 48;
			 	   temp = (temp *10) + (close[1] - 48);
			 	   temp = (temp *10) + (close[2] - 48); 

			}		 
	    }
	    else
		{
	       cout << "\n\t\tNO Request.\n";	
		}
	 in.close();
	 remove("Request.txt");	
}


void Employee :: View_All_CustomerDetails()
{
	    Customer c1;
		ifstream fin;
		char ch;
	    fin.open("Customer_detail.txt",ios::in);
		
		if(!fin)
		{
			cout << "\n\t\tFile doesnot Exist.\n";
		}
		else
        {
        	fin.seekg(0);
        	fin.read((char *)&c1,sizeof(c1));

			while(!fin.eof())
				{
					cout << "\n***************************************************************\n";
				         c1.Display_per();
					cout << "Account Type : " << c1.get_accountType() << endl
			             << "Account No : " << c1.get_accountNo() << endl
			             << "Balance : " << c1.get_balance() << endl;
		         	cout << "***************************************************************\n\n";
                    
    			   fin.read((char *)&ch,sizeof(ch));
				   fin.read((char *)&c1,sizeof(c1));
	
               }
		}
		
		fin.close();
		return;
}
	
void Employee :: View_All_Transaction()
{
    ifstream fin;
    Transaction trans;
	char ch = '\n';
	fin.open("Transaction.txt", ios::in | ios::app);
	
	if(!fin)
	{
	    cout << "\n\tFile Doesnot Exist.\n";	
	}
	else
	{
	    fin.read((char *)&trans,sizeof(trans));
		
		while(!fin.eof())
	    {
		   
		   cout << "Account No : " << trans.account_no << endl
		        << "Customer Name : " << trans.customer_name << endl
		        << "Transaction : " << trans.trans_type << endl
		        << "Previous Balance : " << trans.previous_balance << endl
		        << "New balance : " << trans.new_balance <<endl
	            << "Transaction Time : " << trans.TIME << endl;
	            
		    fin.read((char *)&ch, sizeof(ch));
			fin.read((char *)&trans,sizeof(trans));
		}
	}	
	
	fin.close();
}

void Employee :: Display()
{
    cout << "Using only For making person Class Virtual.";
}

void Transaction :: Add_Transaction()
{
    ofstream fout;
	char ch = '\n';
	fout.open("Transaction.txt", ios::out | ios::app);
	
	if(!fout)
	{
	    cout << "\n\tFile Doesnot Exist.\n";	
	}   
	else
	{
	    fout.write((char *)this,sizeof(*this));
		fout.write((char *)&ch, sizeof(ch));	
	}	
	
	fout.close();
}

void Account :: view_Customer_details(int id)
{
    ifstream fin;
    Customer c1;
    Transaction trans;
	char ch = '\n';
	fin.open("Customer_detail.txt", ios::in | ios::app);
	
	if(!fin)
	{
	    cout << "\n\tFile Doesnot Exist.\n";	
	}
	else
	{
		fin.seekg(0);
	    fin.read((char *)&c1,sizeof(c1));
		
		while(!fin.eof())
	    {
		    if(id == c1.get_accountNo())
			   {
					cout << "\n***************************************************************\n";
 				    c1.Display_per();
				    cout <<"Account Type : " << c1.get_accountType() << endl
			             << "Account No : " << c1.get_accountNo() << endl
			             << "Balance : " << c1.get_balance() << endl;
		         	cout << "***************************************************************\n\n";
		   	   }
			fin.read((char *)&ch, sizeof(ch));
			fin.read((char *)&c1,sizeof(c1));
		}
	}	
	
	fin.close();
}


Account :: Account()
{
	balance = 0;
}


Account :: ~Account()
{
}

void Account :: Deposit(const int temp_id)
{
	Customer temp;
	char ch;
	int c=0;
 	cout << "Enter how many amount would you like to Deposit : ";
    cin >> balance;
	
	fstream file;
    file.open("Customer_detail.txt",ios::in | ios::out | ios::ate); 

   	file.seekg(0);

	file.read((char *)&temp, sizeof(temp));
	int start = file.tellp();

	while(!file.eof())
    {
    	if(temp.get_accountNo() == temp_id)
    	{  
    		Transaction t1;
    		
    		t1.previous_balance = temp.get_balance();    	    
			strcpy(t1.trans_type,"Deposit");
			temp.set_balance(balance,1);
			
			t1.set_transaction(temp.get_accountNo(), temp.get_f_name(), temp.get_balance());
    	    
			t1.Add_Transaction();
    	    
			int pointer = file.tellp();
			int set = pointer - start + c;
    	    file.seekp(set);
    	    file.write((char *)&temp, sizeof(temp));
    	    cout << "\n\tTransaction Successfull.\n";
    	    file.close();
			return;
		}
		c++;
		file.read((char *)&ch, sizeof(ch));
		file.read((char *)&temp, sizeof(temp));
	}
	file.close();
}

bool Account :: sufficient_balance(double account_balance, double withdrawl_amount)
{
      if(account_balance > withdrawl_amount)
        return 1;
      else
	    return 0;   
}

void Account :: view_balance()
{
   cout << "Balance : " << balance;	
}

void Account :: withdrawl(const int temp_id)
{
	Customer temp;
	char ch;
	int c=0;
 	cout << "Enter how many amount would you like to withdrawl : ";
    cin >> balance;
	  
	fstream file;
	
    file.open("Customer_detail.txt",ios::in | ios::out | ios::ate);

   	file.seekg(0);
   	
	file.read((char *)&temp, sizeof(temp));
	
	int start = file.tellp();
    cout << start;
	while(!file.eof())
    {
    	if(temp.get_accountNo() == temp_id)
    	{
    		if(sufficient_balance(temp.get_balance(),this->balance))
	    	  {
			   	t1.previous_balance = temp.get_balance();    	    
			    strcpy(t1.trans_type,"withdrawl");

			    temp.set_balance(balance);
			    
			   	t1.set_transaction(temp.get_accountNo(), temp.get_f_name(), temp.get_balance());
    	   
			    t1.Add_Transaction();

	    	    int pointer = file.tellp();
				int set = pointer - start + c;
	    	    file.seekp(set);
	    	    file.write((char *)&temp, sizeof(temp));
	    	    cout << "\n\tTransaction Successfull.\n";
	    	    file.close();
			    return;
			  }
			  else
			  {
			  	cout << "\n\tTransaction Unsuccessful.\n";
			  }
		}
		c++;
		file.read((char *)&ch, sizeof(ch));
	    file.read((char *)&temp, sizeof(temp));
    }
    
    file.close();
}	

void Account :: view_Transaction_of_Customer(const int acc_no)
{
	ifstream fin;
	char ch;
	fin.open("Transaction.txt", ios::in);
	
	if(!fin)
	{
	    cout << "\n\tFile Doesnot Exist.\n";	
	}
	else
	{
	    fin.read((char *)&t1,sizeof(t1));
		
		while(!fin.eof())
	    {
			if(acc_no == t1.account_no)	
			  {
				cout << "Account No : " << t1.account_no << endl
					 << "Customer Name : " << t1.customer_name << endl
					 << "Previous Balance : " << t1.previous_balance << endl
					 << "New balance : " << t1.new_balance <<endl
					 << "Transaction Time : " << t1.TIME << endl;
			  }
	            
		    fin.read((char *)&ch, sizeof(ch));
			fin.read((char *)&t1,sizeof(t1));
		}
	}
	fin.close();
}

void Account :: Req_closeAccount(int id)
{
    Customer c1;
    char ch;
	int Account_no;
	int choice = 0;
	cout << "\n\t\tFor Closing Account System Needs to Check Your Balance for Deducting Charges.\n";
	cout << "(1) Allow-> " 
	        "(2) Not Allow->";
	cin >> choice;
	if(choice == 1)
		{
			    ifstream fin;
			    
		   	    fin.open("Customer_detail.txt", ios::in | ios::app);
				
				if(!fin)
				{
				    cout << "\n\tFile Doesnot Exist.\n";	
				}
				else
				{
					fin.seekg(0);
				    fin.read((char *)&c1,sizeof(c1));
					
					while(!fin.eof())
				    {
					    if(id == c1.get_accountNo())
						   {
 	  		                   if(c1.get_balance() >= 500)
 	  		                   {
 	  		                   	   c1.set_request(1);
 	  	         	          	   ofstream fout;
 	  		                   	   fout.open("Request.txt", ios :: out | ios :: app);
 	  		                   	   
 	  		                   	   fout << c1.get_accountNo();
 	  		                   	   fout << '\n';
 	  		                   	   break;
				               }
				               
				               else
				               {
				               	  cout << "\n\n\t\t\tIn-Sufficient Balance To close Account.\n";
				               	  break;
							   }
		   
						   }
						fin.read((char *)&ch, sizeof(ch));   
						fin.read((char *)&c1,sizeof(c1));   
				
		            }
		            fin.close();
	            }
        }
   Loading();   
	     
}

void Transaction :: set_transaction(const int acc_no,const char* cus_name,const double balance)
{
	account_no = acc_no;
    strcpy(customer_name,cus_name);
    new_balance = balance;
    strcpy(TIME, current_time());
}

Bank :: Bank()
{
	c = new Customer;
	e = new Employee;
}

Bank :: ~Bank()
{
	delete c;
	delete e;
}
 
