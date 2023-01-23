#include <iostream>
using namespace std;

int generateID();

class Transaction {
private:
    int transactionID;
    string transactionName;
    string transactionDate;

public:
    Transaction() {
        transactionID = 0;
        transactionName = "";
        transactionDate = "";
    }

    Transaction(int id, string name, string date) {
        transactionID = id;
        transactionName = name;
        transactionDate = date;
    }

    int getTransactionID() { return transactionID; }
    string getTransactionName() { return transactionName; }
    string getTransactionDate() { return transactionDate; }

    void setTransactionID(int id) { transactionID = id; }
    void setTransactionName(string name) { transactionName = name; }
    void setTransactionDate(string date) { transactionDate = date; }

    void printTransaction() {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Transaction Name: " << transactionName << endl;
        cout << "Transaction Date: " << transactionDate << endl;
    }
};

class Client{
protected:
    string clientName;
    string clientEmail;
    string clientPhone;
    string clientAddress;
    string clientPassword;
    int clientID;
    Transaction transactions[5];

public:
    Client(){
        clientName = "";
        clientEmail = "";
        clientPhone = "";
        clientAddress = "";
    }
    Client(string name, string email, string phone, string address)
    {
        clientName = name;
        clientEmail = email;
        clientPhone = phone;
        clientAddress = address;
    }

    void setName(string name) { clientName = name; }
    void setEmail(string email) { clientEmail = email; }
    void setPhone(string phone) { clientPhone = phone; }
    void setAddress(string address) { clientAddress = address; }
    void setPassword(string password) { clientPassword = password; }
    void setID(int id) { clientID = id; }
    void setTransaction(Transaction t, int index) { transactions[index] = t; }

    string getName() { return clientName; }
    string getEmail() { return clientEmail; }
    string getPhone() { return clientPhone; }
    string getAddress() { return clientAddress; }
    string getPassword() { return clientPassword; }
    int getID() { return clientID; }
    Transaction getTransaction(int index) { return transactions[index]; }

    void printClientInfo()
    {
        cout << "Name: " << clientName << endl;
        cout << "Email: " << clientEmail << endl;
        cout << "Phone: " << clientPhone << endl;
        cout << "Address: " << clientAddress << endl;
        cout << "ID: " << clientID << endl;
    }
};

template <class T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode *next;

    LinkedListNode(){
        data = 0;
        next = nullptr;
    }

    LinkedListNode(T D)
    {
        data = D;
        next = nullptr;
    }
};

template <class T>
class ClientsLinkedList:public Client{
    LinkedListNode<T> *head;
    LinkedListNode<T> *tail;
    int listSize;

public:
    ClientsLinkedList()
    {
        head = tail = nullptr;
        listSize = 0;
    }

    void newClientMenu(T data){
            LinkedListNode<T>* newNode = new LinkedListNode<T>(data);
            if(head == nullptr){
                cout<<"Enter E-Mail"<<endl;
                cin >>clientEmail;
                newNode->data.setEmail(clientEmail);
                cout<<"Enter Full Name"<<endl;
                cin >>clientName;
                newNode->data.setName(clientName);
                cout<<"Enter Phone Number"<<endl;
                cin >>clientPhone;
                newNode->data.setPhone(clientPhone);
                cout<<"Enter Password"<<endl;
                cin >>clientPassword;
                newNode->data.setPassword(clientPassword);
                cout<<"Enter Address"<<endl;
                cin >>clientAddress;
                newNode->data.setAddress(clientAddress);

                newNode->data.setID(generateID());

                head = tail = newNode;
                return ;
            }

            cout<<"Enter E-Mail"<<endl;
            cin >> clientEmail;
            newNode->data.setEmail(clientEmail);

            LinkedListNode<T>* here = head;
            while(here != nullptr){
                if(here->data.getEmail() == newNode->data.getEmail()){
                        cout<<"Employee already exists"<<endl;
                        delete newNode;
                        return ;
                    }
                here = here -> next;
            }
            
            cout<<"Enter Full Name"<<endl;
            cin >>clientName;
            newNode->data.setName(clientName);
            cout<<"Enter Phone Number"<<endl;
            cin >>clientPhone;
            newNode->data.setPhone(clientPhone);
            cout<<"Enter Password"<<endl;
            cin >>clientPassword;
            newNode->data.setPassword(clientPassword);
            cout<<"Enter Address"<<endl;
            cin >>clientAddress;
            newNode->data.setAddress(clientAddress);

            newNode->data.setID(generateID());

            tail->next = newNode;
            tail = newNode;

            return ;
    	}
};



int main()
{
    ClientsLinkedList<Client>clientsArray[10];
    ClientsLinkedList<Client>ll;

    ll.newClientMenu(clientsArray[0]);
    return 0;
}


int generateID(){
    static bool initialized = false;
    if (!initialized)
    {
        srand(time(0));
        initialized = true;
    }
    return rand();
}