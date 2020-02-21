#include<cstring>
#include<string>


using namespace std;

class Customer;
class Person;
struct Transaction;
class Account;

class Login
{
	int id;
	char pass[4];
	
	public:
		void set_login();
        int get_id();
		char* get_pass();
		int check_access();
		void change_password(Login &);
		void set_id_pass(int, char*);
};


class Transaction
{
	public:
		int account_no;
		char customer_name[20];
		char trans_type[9];
		double previous_balance;
		double new_balance;
		char TIME[25];
	
	public:
		void set_transaction(const int, const char*, const double);	
		void Add_Transaction();
};


class Account
{
	private:
		int balance;
			
	public:
		Transaction t1;
		Account();
		~Account();
		void Deposit(const int);	
		void withdrawl(const int);
		void view_Transaction_of_Customer(const int);
		void view_Customer_details(const int id);
		void Req_closeAccount(int);
	    bool sufficient_balance(double, double);
	    void view_balance();
};

class Address
{
	private:
		  char street[20];
		  char city[10];
		  char country[10];
		  char state[10];
		  char zip[10];
		  
	public:
	    void set_Address();
		void set_street(char *street);
		void set_city(char *street);
		void set_country(char *street);
		void set_state(char *street);
		void set_zip(char *street);	
		void Display_Address();		  
		
};

class Person
{
    private:
	char f_name[15];
	char l_name[15];
	Address A;
	char nic[20];
	long long phoneNo;
	
    public:
    	
    	void  set_person();
		char*        get_f_name();
		char*        get_l_name();
		char*        get_nic();
		long long    get_phone_no();		
    	void         Display_per();		
    	virtual void Display() = 0;
};




class Customer : public Person
{
	private:
		char accountType[20];
		int  balance;
		int  account_no;
		int  request;
		char pass[4];
		int  day,month,year;
			
	public:
		Account acc;
		Login l1;	
		Customer();
		~Customer();
//		void mem_customer();
		void set_customer();
		void set_balance(double, int);
		void set_password();
		void set_request(int);
		int get_request();
		void set_date(int ,int ,int);
		int get_day();
		int get_month();
		int get_year();
		int get_accountNo();
		char * get_accountType();
		void Display();
		double get_balance();
		int get_id();
		char* get_pass();
};

class Employee : public Person
{
	private:
		char post[20];
		double salary;
		int id;
		int pass;
		
	public:
		Customer *c1;
		Transaction t1;
	    Login *l1;
	    Employee();
	    ~Employee();
		void open_account();
		void close_account();
		char * get_emplyeeName();
		void View_All_Transaction();
		void interest_rate();
		void View_All_CustomerDetails();
		void Display();
};

class Bank
{
	string id_No;
	string Address;
	
	public:
		Bank();
		~Bank();
		Customer *c;
		Employee *e;
		Account acc;
		Login l;
};
