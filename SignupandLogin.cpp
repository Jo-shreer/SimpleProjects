#include <iostream>
#include <fstream>
using namespace std;

class temp
{
private:
  string username, Email, password, address;
  fstream file;

public:
  void signup();
  void login();
} obj;

int main()
{
  char choice;
  cout << "\n Press 1 for login";
  cout << "\n Press 2 for Signup";
  cin >> choice;

  switch (choice)
  {
  case '1':
    obj.login();
    break;

  case '2':
    obj.signup();
    break;

  default:
    cout << "Invalid choice";
    break;
  }
  return 0;
}

void temp::signup()
{
  cout << "\nEnter the username:" << endl;
  getline(cin, username);
  cout << "\nEnter the Email:";
  getline(cin, Email);
  cout << "\nEnter the address:";
  getline(cin, address);
  cout << "\nEnter the password:";
  getline(cin, password);

  file.open("UserData.txt", ios::out | ios::app);
  file << username << "*" << Email << "*" << address << "*" << password << endl;
  file.close();
}

void temp::login()
{
  string searchUsername, searchPassword;
  cout << "------------LOGIN--------" << endl;
  cout << "Enter the username:";
  getline(cin, searchUsername);
  cout << "\nEnter the Password:";
  getline(cin, searchPassword);

  file.open("UserData.txt", ios ::in);
  getline(file, username, '*');
  getline(file, Email, '*');
  getline(file, password, '\n');

  while (!file.eof())
  {
    if (username == searchUsername)
    {
      if (password == searchPassword)
      {
        cout << "Login successful" << endl;
      }
      else
      {
        cout << "Invalid password" << endl;
      }
    }
    else
    {
      cout << "Invalid username" << endl;
    }
  }
}
