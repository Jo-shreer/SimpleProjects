#include <iostream>
using namespace std;

void displayMenu()
{
  cout << "Simple Calculator" << endl;
  cout << "1. Addition" << endl;
  cout << "2. Subtraction" << endl;
  cout << "3. Multiplication" << endl;
  cout << "4. Division" << endl;
  cout << "5. Exit" << endl;
  cout << "Choose an operation (1-5): ";
}

double add(double a, double b)
{
  return a + b;
}

double subtract(double a, double b)
{
  return a - b;
}

double multiply(double a, double b)
{
  return a * b;
}

double divide(double a, double b)
{
  if (b == 0)
  {
    throw invalid_argument("Cannot divide by zero");
  }
  return a / b;
}

int main()
{
  int choice;
  double num1, num2;

  while (true)
  {
    displayMenu();
    cin >> choice;
    if (choice == 5)
    {
      cout << "Exiting the calculator. Goodbye!" << endl;
      break;
    }
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    try
    {
      switch (choice)
      {
      case 1:
        cout << "Result: " << add(num1, num2) << endl;
        break;
      case 2:
        cout << "Result: " << subtract(num1, num2) << endl;
        break;
      case 3:
        cout << "Result: " << multiply(num1, num2) << endl;
        break;
      case 4:
        cout << "Result: " << divide(num1, num2) << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
      }
    }
    catch (const exception &e)
    {
      cout << "Error: " << e.what() << endl;
    }
  }

  return 0;
}
