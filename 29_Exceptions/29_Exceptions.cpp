#include <iostream>
using namespace std;

class List
{
private :
    int size;
public :
	List() :size(0) {}
	List(int s) :size(s) {}
	float GetByPos(int pos)
	{
		if (size == 0)return 1;
		if (pos < 1 || pos >= size)return 2;

		return rand() % 10;//0.....9

		if (pos == 1)
		{
			return 404.0000000;//int
		}
		if (pos == 5)
		{
			//return "Divide by 5";//const char *
		}
	}

};

float Divide(float a, float b)
{
	//try catch throw
	
	float res ;
	if (b == 0)
	{
		throw exception("Can't divide by zero!!!");
		///cout << "Can't divide by zero!!!" << endl;
	}
	if (b == 1)
	{
		throw 404;//int
	}
	if (b == 5)
	{
		throw "Divide by 5";//const char *
	}
	
		res = a / b;
		cout << "Result : " << res << endl;
		return res;
	

}

//void Login(const char* login, const char* password)
//{
//	if (strlen(password) < 6)
//		cout << "To short password" << endl;
//	if(!islower(password[0]) || !isalpha(password[0]))
//		cout << "Password invalid" << endl;
//	if (!isupper(login[0]) || isalpha(login[0]))
//		cout << "Login invalid" << endl;
//	cout << "Loading........" << endl;
//}

class PasswordInvalidException: public exception
{
public :
	PasswordInvalidException(const char * message): exception(message){}
};
class PasswordIsShortException : public exception
{
	int length;
public:
	PasswordIsShortException(const char* message, int length) : length(length),
		exception(message) {}
	void Message()const
	{
		cout << what() << endl;
		cout << "Actual lenght : " << length << endl;
	}
};


void Login(const char* login, const char* password)
{
	if (strlen(password) < 6)
		throw PasswordIsShortException("To short password", strlen(password)) ;
	if (!islower(password[0]) || !isalpha(password[0]))
		throw PasswordInvalidException("Password invalid" );
	if (!isupper(login[0]) || !isalpha(login[0]))
		throw exception("Login invalid" );


	cout << "Loading........" << endl;
}

int main()
{

	// Login
	char login[100];
	char pass[100];

	for (int i = 0; i < 5; ++i)
	{
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> pass;

		try
		{
			Login(login, pass);
			break;
		}		
	    catch (PasswordInvalidException& e)
		{
			cout << "Invalid... do something:\n";
			cout << e.what() << endl;
			cout << "A-Z, a-z, 0-9\n";
		}
		catch (PasswordIsShortException& e)
		{
			cout << "Small... do something:\n";
			e.Message();
			cout << "Length must be more than  6 symbols\n";
		}
		catch (exception& e)
		{
			cout << "General error...\n";
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown exception!\n";
		}
	
	}

	/*	float a, b;
	cout << "Enter a and b ";
	cin >> a >> b;

	try
	{
		float res = Divide(a, b);
		cout << "Result in main : " << res << endl;

	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	catch (int ex)
	{
		cout << ex << endl;
	}
	catch (const char*  ex)
	{
		cout << ex << endl;
	}
	catch (...)
	{
		cout << "Unknown exception" << endl;
	}

	cout << "Countinue........." << endl;
	cout << "Countinue........." << endl;
	cout << "Countinue........." << endl;
	*/
}

