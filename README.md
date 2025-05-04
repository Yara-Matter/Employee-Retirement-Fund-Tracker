Project Title: Employee Transaction Management System


📝 Description:

This C++ program manages employees' retirement fund transactions using a singly linked list. It allows recording of deposit and withdrawal transactions per employee, displays their transaction history, allows searching by date, and calculates current balance.


🎯 Features:

    Add multiple employees with unique ID and name.
    
    Record deposits and withdrawals for each employee.
    
    Maintain a linked list of transactions per employee.
    
    Display all transactions of a specific employee.
    
    Search for a transaction by date.
    
    Show the current balance of an employee.
    
    Transaction status is recorded (successful or failed).

    

📂 Data Structures Used:

    struct Transaction: Represents each transaction with attributes: date, amount, type (deposit/withdrawal), source, status, and a next pointer.

    map<pair<int, string>, Transaction*>: Maps each employee to their linked list of transactions.

    map<pair<int, string>, double>: Stores the current balance for each employee.

    

🔧 Functions:

Add_Transaction(...)
Adds a new transaction node to the employee’s transaction list.

withdrawls(...)
Attempts to withdraw money from employee balance. Fails if balance is insufficient.

Deposits(...)
Adds money to employee balance and records the transaction.

Display_Transactions(...)
Prints all transactions of a given employee.

Calculate_Balance(...)
Calculates the employee’s balance based on successful transactions.

search_By_Date(...)
Searches for a transaction by a specific date.


🖥️ How to Use:

    Enter the number of employees and their details.

    Use the menu to:

        Add a transaction.

        View all transactions for a specific employee.

        Search a transaction by date.

        View current balance.

    Each transaction must specify the employee, type (deposit or withdrawal), amount, and source.
