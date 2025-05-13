#include <bits/stdc++.h>
using namespace std;


struct Transaction {
    string date;
    double amount ;
    string type;
    string source ;
    Transaction* next = nullptr;
    string status;
};



//we add new node (Transaction)
void Add_Transaction(Transaction*& head ,string date , double amount , string type , string source , string status) {
    Transaction* Newnode = new Transaction{date,amount,type,source,nullptr,status};
    if(head == nullptr) {
        head=Newnode;
    } else {
        Transaction* temp=head;
        while (temp->next!=nullptr) {
            temp = temp->next;
        }
        temp->next = Newnode;
    }
}




void withdrawls(double value , double& current_amount,Transaction*&head,string date , string type , string source) {
    if (value < 0) {
            cout << "Invalid value!\n";
            addTransaction(date, current_amount, "withdrawal", source, "Transaction Failed: Invalid value!");
            return;
        }
    if(current_amount>=value) {
        current_amount -= value;
        Add_Transaction(head, date, value, type, source, "Successful Transaction.");
    } else {
        cout<<"NOT Enough Money !"<<endl;
        Add_Transaction(head, date, current_amount, type, source, "Transaction Failed: Not enough balance");
    }
}





void Deposits(double value, double& current_amount, Transaction*& head, string date, string type, string source) {
    if (value < 0) {
            cout << "Invalid value!\n";
            addTransaction(date, current_amount, "withdrawal", source, "Transaction Failed: Invalid value!");
            return;
        }
    current_amount += value;
    Add_Transaction(head, date, current_amount, type, source, "Successful Transaction.");
}




void Display_Transactions(Transaction* head) {
    if(head == nullptr) {
        cout << "No transactions found."<<endl;
        return;
    }
    Transaction* temp = head;
    while (temp != nullptr) {
        cout << "Date: " << temp->date << endl;
        cout << "Type: " << temp->type << endl;
        cout << "Amount: " << temp->amount << endl;
        cout << "Source: " << temp->source << endl;
        cout << "Status: " << temp->status << endl;
        cout << "-----------------------------\n";
        temp = temp->next;
    }
}






double Calculate_Balance(Transaction* head) {
    double balance=0;
    Transaction* temp = head ;

    while (temp != nullptr) {
        if(temp->status == "Successful Transaction.") {
            if(temp->type == "deposit" ) {
                balance += temp->amount;
            } else if (temp->type == "withdrawal") {
                balance -= temp->amount;
            }
        }
        temp = temp->next;
    }
    return balance;
}





void search_By_Date(Transaction* head, const string& date) {
    bool found = false;
    Transaction* temp = head;

    while (temp != nullptr) {
        if (temp->date == date) {
            cout << "Transaction Found:\n";
            cout << "Type: " << temp->type << ", Amount: " << temp->amount
                 << ", Source: " << temp->source << "\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No transaction found on this date.\n";
}





int main() {
    map<pair<int, string>, Transaction*> employeeRecords;
    map<pair<int, string>, double> employeeBalances;

    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;
    cout<<endl;

    for (int i = 1; i <= numEmployees; i++) {
        int id;
        string name;
        cout << "Enter employee #" << i << " ID: ";
        cin >> id;
        cout<<endl;

        cout << "Enter employee #" << i << " Name: ";
        cin >> name;
        cout<<endl;

        pair<int, string> key = {id, name};
        employeeRecords[key] = nullptr;
        employeeBalances[key] = 0.0;
    }

    int option;
    while (true) {
        cout << "\n1. Add Transaction\n2. Display Employee Data\n3. Search by Date\n4. Show Employee Balance\n5. Exit\n";
        cout << "Enter choice: ";
        cin>>option;
        cout<<endl;

        if(option == 1) {
            int id;
            double amount;
            string name, date, type, source;

            cout << "Enter employee ID : "; cin>>id ;cout<<endl;
            cout << "Enter employee name: "; cin >> name;cout<<endl;

            cout << "Enter date (YYYY-MM-DD): "; cin >> date;cout<<endl;
            cout << "Enter transaction type (deposit/withdrawal): "; cin >> type;cout<<endl;

            while (type != "deposit" && type != "withdrawal") {
                cout << "Invalid type! Please enter 'deposit' or 'withdrawal': ";
                cin >> type;cout<<endl;
            }

            cout << "Enter amount: "; cin >> amount;cout<<endl;
            cout << "Enter fund source: "; cin >> source;cout<<endl;

            pair<int , string > key = {id,name};

              if (employees.find(key) == employees.end()) {
                cout << "Employee not found.\n";
                continue;
            }

            if (type == "deposit") {
                Deposits(amount, employeeBalances[key], employeeRecords[key], date, type, source);
            } else {
                withdrawls(amount, employeeBalances[key], employeeRecords[key], date, type, source);
            }

            cout << "Transaction added.\n";

        } else if(option == 2) {
            int id;
            string name;
            cout << "Enter employee ID: "; cin >> id;cout<<endl;
            cout << "Enter employee name: "; cin >> name;cout<<endl;

            pair<int, string> key = {id, name};
            Display_Transactions(employeeRecords[key]);

        } else if (option == 3) {
            int id;
            string name, date;
            cout << "Enter employee ID: "; cin >> id;cout<<endl;
            cout << "Enter employee name: "; cin >> name;cout<<endl;
            cout << "Enter date to search (YYYY-MM-DD): "; cin >> date;cout<<endl;

            pair<int, string> key = {id, name};
            
              if (employees.find(key) == employees.end()) {
                cout << "Employee not found.\n";
                continue;
            }
            
            search_By_Date(employeeRecords[key], date);

        } else if (option == 4) {
            int id;
            string name;
            cout << "Enter employee ID: "; cin >> id;cout<<endl;
            cout << "Enter employee name: "; cin >> name;cout<<endl;

            pair<int, string> key = make_pair(id, name);

              if (employees.find(key) == employees.end()) {
                cout << "Employee not found.\n";
                continue;
            }
            
            double balance = Calculate_Balance(employeeRecords[key]);
            cout << "Current balance for " << name << " (ID: " << id << "): " << balance << "\n";

        } else if (option == 5) {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
