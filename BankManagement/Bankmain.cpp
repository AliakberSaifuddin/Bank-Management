#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<windows.h>
#include<cstring>
#include<conio.h>
#include "Bank definition.cpp"
#include<stdlib.h>

using namespace std;

int main()
{
    system("COLOR 70");

	FrontPage();

	Loading();

	Bank b;
	char ch = '\n';
//	Login l1;
	int checker=0;
//	ofstream  fout;
//	fout.open("password.txt",ios::out | ios::app);
//	l1.set_login();
//	fout.write((char *)&l1,sizeof(l1));
//	fout.write((char *)&ch, sizeof(ch));
//	fout.close();
		     
	while(1)
	{
	 switch(Login_menu())
		{
			// If Employee Logins 
			case 1:
				system("CLS");
				b.l.set_login();
				
				if(b.l.check_access())
					while(1)
						{
							switch(Employee_menu())
							{
								case 1:
									b.e->open_account();
									break;
								
								case 2:
									b.e->close_account();
								    break;
								  
								case 3:
								    b.e->View_All_CustomerDetails();
									break;
								
								case 4:
								    b.e->View_All_Transaction();
									break;
								
								case 5:
								    b.e->l1->change_password(b.l);	
									    
								case 0:
								  checker = 1;
								  break;	
							}
							if(checker == 1)
							{
								checker = 0; 
								break;
							}
						}
				break;		
				
			// If Customer Logins
			case 2:
				b.l.set_login();
				if(b.l.check_access())
				while(1)
				{
					switch(account_menu())
					{				
					    case 1:
				     	   b.c->acc.withdrawl(b.l.get_id());
				     	   break;
				     	
						case 2:
						   b.c->acc.Deposit(b.l.get_id());
						   break;
						
						case 3:
						   b.c->acc.view_Customer_details(b.l.get_id());
						   break;
						
						case 4:
						   b.c->acc.view_Transaction_of_Customer(b.l.get_id());
						   break;
						
						case 5:
					       b.c->acc.view_balance();
					       break;
					    
						case 6:
						   b.c->acc.Req_closeAccount(b.l.get_id());
						   break;
						
						case 7:
						   b.c->l1.change_password(b.l);      
						
						case 0:
						checker = 1;	
						   break;   
				    }
				    if(checker == 1)
					{
						checker = 0; 
						break;
					}
			    }
			 break;   
			case 0:
			   exit(0); 
			      
	    }
    }
    
    return 0;
 
}
