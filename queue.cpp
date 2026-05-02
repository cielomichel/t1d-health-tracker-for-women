#include <iostream>
#include <queue>
using namespace std;

class Customer
{
public:
    int id;
    int items;

    Customer() {}

    Customer(int i, int it)
    {
        id = i;
        items = it;
    }
};

void printLine(queue<Customer> line)
{
    if (line.empty())
    {
        cout << "The checkout line is empty.\n";
        return;
    }

    cout << "Customers in line:\n";
    while (!line.empty())
    {
        Customer c = line.front();
        cout << "Customer ID: " << c.id << ", Items: " << c.items << "\n";
        line.pop();
    }
}

int main()
{
    queue<Customer> checkoutLine;
    int choice;

    while (true)
    {
        cout << "\n===== GROCERY STORE MENU =====\n";
        cout << "1. Add customer to checkout line\n";
        cout << "2. Serve next customer\n";
        cout << "3. Show checkout line\n";
        cout << "4. Show next customer\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, items;
            cout << "Enter customer ID: ";
            cin >> id;
            cout << "Enter number of items: ";
            cin >> items;

            Customer newCustomer(id, items);
            checkoutLine.push(newCustomer);

            cout << "Customer added to line.\n";
        }
        else if (choice == 2)
        {
            if (checkoutLine.empty())
            {
                cout << "No customers to serve.\n";
            }
            else
            {
                Customer c = checkoutLine.front();
                cout << "Serving customer ID: " << c.id
                     << " with " << c.items << " items.\n";
                checkoutLine.pop();
            }
        }
        else if (choice == 3)
        {
            printLine(checkoutLine);
        }
        else if (choice == 4)
        {
            if (checkoutLine.empty())
            {
                cout << "No customers in line.\n";
            }
            else
            {
                Customer c = checkoutLine.front();
                cout << "Next customer is ID: " << c.id
                     << " with " << c.items << " items.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting grocery store simulation.\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}