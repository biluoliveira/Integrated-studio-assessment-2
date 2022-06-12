#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string CreateUsername;
    string CreatePassword;
    string userName;
    string userPassword;
    int loginAttempt = 0;

    cout <<">>>>>>>";
    cout <<" Please Create User Name and Password to loggin: ";
    cout <<"<<<<<<<\n";
    cout <<"Create your User Name: ";
    cin >> CreateUsername;
    cout <<"Create your password: ";
    cin >> CreatePassword;

    while (loginAttempt < 3)
    { 
        cout <<"----------------------------\n";
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == CreateUsername && userPassword == CreatePassword)
        {
            cout << "Welcome! "<<CreateUsername<<endl;
            break;
        }
       
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Thank you for logging in.\n";
}