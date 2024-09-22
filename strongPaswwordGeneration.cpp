#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string getPassword(int size)
{
    string password = "";
    string chars = "aquickbrownforjumpsoverthelazydogAQUICKBROWNFORJUMPSOVERTHELAZYDOG0123456789";
    int size1 = chars.size();
    srand(time(0));
    int randomIndex;
    for(int i =0; i < size; i++)
    {
        randomIndex = rand()%size1;
        password = password + chars[randomIndex];
    }
    return password;
}

int main()
{
    int lenght;
    cout <<"Enter the length:" << endl;
    cin >> lenght;
    string password =  getPassword(lenght);
    cout << "Password Generated:" << password;
    return 0;
}
