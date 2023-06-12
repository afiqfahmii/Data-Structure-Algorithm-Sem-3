#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

const int max_users = 100;
string usernames[max_users];
string passwords[max_users];
int n_users = 0;

class Node //what will be in every node in the stack
{
    public:
    float price;
    string costume;
    Node *next; //pointing to next node
};

//-------------------------------------------------------------------------------------------------------------------------------

class Stack //stack for each type of costume
{
private:
    Node *head;

public:
    Stack() { head = NULL; }
    void push(string, float);
    void pop();
    void display();
    bool isEmpty();
    bool isFull();
    string stackTop(); //return data at top of the stack
};

//-------------------------------------------------------------------------------------------------------------------------------

class Admin
{
public:
    string admin_username;
    string admin_password;
    Admin(string a = NULL, string b = NULL)
    {
        admin_username = a;
        admin_password = b;
    }
    string getUsername()
    {
        return admin_username;
    }
    string getPassword()
    {
        return admin_password;
    }
};

//-------------------------------------------------------------------------------------------------------------------------------

void Stack::push(string costume, float price) //Function to add product by creating new node
{

    Node *temp = new Node;
    temp->costume = costume;
    temp->price = price;
    temp->next = head;
    head = temp;
}

//-------------------------------------------------------------------------------------------------------------------------------

void Stack::pop() //function to remove product/data from the stack
{
    if (head == NULL)
    {
        cout << "  The stack is empty." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

//-------------------------------------------------------------------------------------------------------------------------------

void Stack::display() //display all data/product from top to bottom in the stack
{
    if (head == NULL)
    {
        cout << "  The stack is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->costume << "----> RM " << temp->price << endl;

        temp = temp->next;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------

bool Stack::isEmpty() //check if the stack is empty/not
{
    return head == NULL;
}

bool Stack::isFull() //check if the stack is empty/not
{
    return head == NULL;
}

//-------------------------------------------------------------------------------------------------------------------------------

string Stack::stackTop() //return value/data from the top of the stack
{
    if (isEmpty())
        return "";
    else
        return head->costume;
}

//-------------------------------------------------------------------------------------------------------------------------------

void UserRegister() //for user to register in the system
{
    string username, password;
    cout << "-------------------------------------------------------------------" << endl;
    cout << " ||                          REGISTER                           ||" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "  Enter a username: ";
    cin >> username;
    for (int i = 0; i < n_users; i++)
    {
        if (usernames[i] == username)
        {
            cout << "  Error: that username is already in use." << endl;
            return;
        }
    }
    cout << "  Enter a password: ";
    cin >> password;
    usernames[n_users] = username;
    passwords[n_users] = password;
    n_users++;
    cout << "  Registration successful!" << endl
         << endl
         << endl;
    system("CLS");
}

//-------------------------------------------------------------------------------------------------------------------------------

bool login() //for admin to login 
{
    bool admin = false;

    Admin admin1("admin", "password");
    string username, password;
    cout << "-------------------------------------------------------------------" << endl;
    cout << " ||                         ADMIN LOGIN                         ||" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "  Enter your username: ";
    cin >> username;
    cout << "  Enter your password: ";
    cin >> password;
    cout << endl
         << endl;
    if (username == admin1.getUsername() && password == admin1.getPassword())
    {
        cout << "  Welcome admin!" << endl
             << endl;
        system("CLS");
        return admin = true;
    }

    cout << "  Error: incorrect username or password." << endl;
    return admin;
}

//-------------------------------------------------------------------------------------------------------------------------------

bool Userlogin() //for customer to login
{

    bool user = false;
    cout << "-------------------------------------------------------------------" << endl;
    cout << " ||                           LOGIN                             ||" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    string username, password;
    cout << "  Enter your username: ";
    cin >> username;
    cout << "  Enter your password: ";
    cin >> password;
    for (int i = 0; i < n_users; i++)
    {
        if (usernames[i] == username && passwords[i] == password)
        {
            cout << "  Hello ! Welcome " << username << "!" << endl
                 << endl;
            system("CLS");
            return user = true;
        }
    }
    cout << "  Error: incorrect username or password." << endl;
    return user;
}

//------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    system("Color F0");
    Stack batman, superman, wonderwoman, cart;
    int choice;
    string costume, costume1;
    bool admin;
    bool user;
    int stack;
    int cosnum;
    float total = 0;

    batman.push("Batman Costume #001", 130);
    batman.push("Batman Costume #002", 130);
    batman.push("Batman Costume #003", 130);

    superman.push("Superman Costume #001", 200);
    superman.push("Superman Costume #002", 200);
    superman.push("Superman Costume #003", 200);

    wonderwoman.push("Wonderwoman Costume #001", 120);
    wonderwoman.push("Wonderwoman Costume #002", 120);
    wonderwoman.push("Wonderwoman Costume #003", 120);
    cout << endl;

    cout << "-------------------------------------------------------------------" << endl;
    cout << "()()()()()()()()()()()()()||  WELCOME  ||()()()()()()()()()()()()()" << endl
         << ")()()()()()()()()()()()()(||    TO     ||)()()()()()()()()()()()()(" << endl
         << "()()()()()()()()()()()()()||  COSTUME  ||()()()()()()()()()()()()()" << endl
         << ")()()()()()()()()()()()()(||  BOOKING  ||)()()()()()()()()()()()()(" << endl
         << "()()()()()()()()()()()()()||  SYSTEM   ||()()()()()()()()()()()()()" << endl;
    cout << "-------------------------------------------------------------------" << endl <<endl;

    while (true)
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << " ||                       LOGIN OR SIGNUP                       ||" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "  1. Register" << endl;
        cout << "  2. Admin Login" << endl;
        cout << "  3. User Login" << endl;
        cout << "  4. Exit" << endl
             << endl;
        cout << "  Enter Your Choice: ";

        int choice, choice1, choice2;

        cin >> choice2;

        system("CLS");
        switch (choice2)
        {
        case 1://register

            UserRegister();
            break;

        case 2://for admin
            admin = login();

            if (admin)
            {

                while (choice != 4)
                {
                    cout << "-------------------------------------------------------------------" << endl;
                    cout << " ||                          ADMIN MENU                         ||" << endl;
                    cout << "-------------------------------------------------------------------" << endl;
                    cout << "  1. Add Costumes" << endl;
                    cout << "  2. Remove Costume" << endl;
                    cout << "  3. View Available Costume" << endl;
                    cout << "  4. Exit" << endl;
                    cout << "  Enter your choice: ";

                    cin >> choice;

                    system("CLS");
                    switch (choice)
                    {
                    case 1://add costume to stack
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << " ||                         ADD COSTUMES                        ||" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "       Enter the costume name Batman | Superman | Wonderwoman      " << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "-------------------------------------------------------------------" << endl << endl;
                        cout << "  Enter The Costume Here : ";
                        cin >> costume1;
                        
                        if (costume1 == "batman" || costume1 == "Batman")
                        {   
                            cout << "  Enter The Costume number : ";
                            cin >> cosnum;

                            if ( cosnum == 1){
                                    batman.push("Batman Costume #001", 130);
                                
                            }else if ( cosnum == 2){
                                    batman.push("Batman Costume #002", 130);
                                
                            }else if ( cosnum == 3){
                                    batman.push("Batman Costume #003", 130);
                                
                            }else{
                                cout << "  Please enter the number between 1-3." << endl;
                            }

                        }
                        else if (costume1 == "superman" || costume1 == "Superman")
                        {
                            cout << "  Enter The Costume number : ";
                            cin >> cosnum;

                            if ( cosnum == 1){
                                    superman.push("Superman Costume #001", 130);
                                
                            }else if ( cosnum == 2){
                                    superman.push("Superman Costume #002", 130);
                                
                            }else if ( cosnum == 3){
                                    superman.push("Superman Costume #003", 130);
                                
                            }else{
                                cout << "  Please enter the number between 1-3." << endl;
                            }
                        }
                        else if (costume1 =="wonderwoman" || costume == "Wonderwoman")
                        {
                            cout << "  Enter The Costume number : ";
                            cin >> cosnum;

                            if ( cosnum == 1){
                                    wonderwoman.push("Wonderwoman Costume #001", 130);
                                
                            }else if ( cosnum == 2){
                                    wonderwoman.push("Wonderwoman Costume #002", 130);
                                
                            }else if ( cosnum == 3){
                                    wonderwoman.push("Wonderwoman Costume #003", 130);
                                
                            }else{
                                cout << "  Please enter the number between 1-3." << endl;
                            }
                        }
                        else
                        {
                            cout << "  The costume does not exist" << endl;
                        }
                        break;

                        break;

                    case 2: //remove costume from stack
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << " ||                       REMOVE COSTUMES                       ||" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "  Choose : Batman | Superman | Wonderwoman " << endl;
                        cout << "  Enter the costume name: ";
                        cin >> costume;
                        
                        if (costume == "batman" || costume == "Batman")
                        {
                            if (batman.isEmpty())
                            {
                                cout << "  The stack is empty." << endl;
                            }
                            else
                            {
                                cart.push(batman.stackTop(), 130);
                                batman.pop();
                            }
                        }
                        else if (costume == "superman" || costume == "Superman")
                        {
                            if (superman.isEmpty())
                            {
                                cout << "  The stack is empty." << endl;
                            }
                            else
                            {
                                cart.push(superman.stackTop(), 200);
                                superman.pop();
                            }
                        }
                        else if (costume == "wonderwoman" || costume == "Wonderwoman")
                        {
                            if (wonderwoman.isEmpty())
                            {
                                cout << "  The stack is empty." << endl;
                            }
                            else
                            {
                                cart.push(wonderwoman.stackTop(), 120);
                                wonderwoman.pop();
                            }
                        }
                        else
                        {
                            cout << "  The costume does not exist" << endl;
                        }
                        break;

                    case 3: //check availability of costume in stack
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << " ||                      AVAILABLE COSTUMES                     ||" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "  Batman Costumes: " << endl;
                        batman.display();
                        cout << endl;
                        cout << "  Superman Costumes: " << endl;
                        superman.display();
                        cout << endl;
                        cout << "  Wonderwoman Costumes: " << endl;
                        wonderwoman.display();
                        cout << endl;
                        break;

                    case 4:
                        //exit
                        break;

                    default:
                        cout << "  Invalid choice." << endl;
                        break;
                    }
                }
            }
            else
                return 0;
            break;

        case 3://for customer
            system("CLS");
            user = Userlogin();
            if (user == false)
            {

                cout << "  Please Register : " << endl;
                UserRegister();
            }

            if (user)
            {

                while (choice1 != 4)
                {
                    cout << "-------------------------------------------------------------------" << endl;
                    cout << " ||                            MENU                             ||" << endl;
                    cout << "-------------------------------------------------------------------" << endl;
                    cout << "  1. Display Costumes" << endl;
                    cout << "  2. Add to Cart" << endl;
                    cout << "  3. View Cart" << endl;
                    cout << "  4. Exit" << endl;
                    cout << "  Enter your choice: ";
                    cin >> choice1;
                    system("CLS");
                    switch (choice1)
                    {
                    case 1://display costume
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << " ||                          COSTUMES                           ||" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "  Batman Costumes: " << endl;
                        batman.display();
                        cout << endl;
                        cout << "  Superman Costumes: " << endl;
                        superman.display();
                        cout << endl;
                        cout << "  Wonderwoman Costumes: " << endl;
                        wonderwoman.display();
                        cout << endl;
                        break;
                    case 2://add costume to cart
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << " ||                         ADD TO CART                         ||" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "  Choose : Batman | Superman | Wonderwoman " << endl;
                        cout << "  Enter the costume name: ";
                        cin >> costume;
                        
                        if (costume == "batman" || costume == "Batman")
                        {
                            if (batman.isEmpty())
                            {
                                cout << "  The stack is empty." << endl;
                            }
                            else
                            {
                                cart.push(batman.stackTop(), 130);
                                batman.pop();
                                total += 130;
                            }
                        }
                        else if (costume == "superman" || costume == "Superman")
                        {
                            if (superman.isEmpty())
                            {
                                cout << "  The stack is empty." << endl;
                            }
                            else
                            {
                                cart.push(superman.stackTop(), 200);
                                superman.pop();
                                total += 200;
                            }
                        }
                        else if (costume == "wonderwoman" || costume == "Wonderwoman")
                        {
                            if (wonderwoman.isEmpty())
                            {
                                cout << "  The stack is empty." << endl;
                            }
                            else
                            {
                                cart.push(wonderwoman.stackTop(), 120);
                                wonderwoman.pop();
                                total += 120;
                            }
                        }
                        else
                        {
                            cout << "  Invalid Costume Name < Try Again > " << endl;
                        }
                        break;
                    case 3: //view what in the cart
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << " ||                             CART                            ||" << endl;
                        cout << "-------------------------------------------------------------------" << endl;
                        cout << "  Cart: " << endl;

                        cart.display();
                        cout << "\nTotal Price : RM " << total << "\n\n";
                        break;
                    case 4:
                        //exit
                        break;
                    }
                }
            }
            break;
        case 4:
            exit(1);
            break;

        }
    }
}