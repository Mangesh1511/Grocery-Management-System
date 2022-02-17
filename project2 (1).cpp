//*******************Final draft**********************

#include <bits/stdc++.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <algorithm>

using namespace std;

//***********Some important global functions definitions**********
int current_year()
{
    time_t curr_time;
    curr_time = time(NULL);
    struct tm *atime = localtime(&curr_time);
    return atime->tm_year + 1900;
}

int current_month()
{
    time_t curr_time;
    curr_time = time(NULL);
    struct tm *atime = localtime(&curr_time);
    return atime->tm_mon + 1;
}

void SetCharArray(string str, char arr[])
{
    for (int i = 0; i < str.size(); i++)
    {
        arr[i] = str[i];
    }
    arr[str.size()] = '\0';
}

//************Class declarations********************

class shop
{

public:
    int loginscreen(int man);
    int loginscreen(char work);
    inline void heading();
};

class Item
{
public:
    float rate;
    int exp_month;
    int exp_year;
    int manu_month;
    int manu_year;
    int quantity;
    char item_name[30];
    char category[30];
    int exp;

    Item()
    { // Default Constructor call on every object creation of class Item
        this->rate = 0;
        this->exp_month = 0;
        this->exp_year = 0;
        this->manu_month = 0;
        this->manu_year = 0;
        this->quantity = 0;
    }
};

class ItemFunc : public Item
{
public:
    void Delete_Item();
    void Add_Item();
    void Search();
    void Exp_Reminder();
    void Quan_Reminder();
    void Stock_Details();
    void Category_Listing();
    void main_menu();
    void Menu(char staff);
    void Menu(int manager);
};

class Sales
{
public:
    char Item_Name[30];
    int Quantity;
    char Time[50];
    int amount;

    void Sales_Record();
    void Sales_Details();
};

//**************main******************

int main()
{
    ItemFunc obj;
    obj.main_menu();

    return 0;
}

//***********Class Shop Function Defintion***********

int shop::loginscreen(int man)
{
    cout << " \n\t\t\t HI MANAGER !!! " << endl;
    string username, password;
    string original_password = "1234";
    string original_username = "admin";

    try
    {
        cout << "\n\n\t\t\t\tUSERNAME:";
        cin >> username;
        cout << "\n\n\t\t\t\tPASSWORD:";
        cin >> password;

        if (username == original_username && password == original_password)
        {

            cout << "\n\nLogged in Successfully!!!\n\n";
            return 1;
            // needs the next function call here; next screen;
        }
        else
        {
            throw 101;
        }
    }
    catch (int x)
    {
        static int try_no = 2;
        if (try_no > 0)
        {
            cout << "Incorrect Password!!!" << endl
                 << "Only " << try_no << " chances remaining" << endl;
            try_no--;
            loginscreen(5);
        }
        else
        {
            cout << "Exceeded Limits!!!!Come back in a while" << endl;
            exit(0);
        }
    }
    // system("cls");

    return 0;
}

int shop::loginscreen(char work)
{
    cout << "\n\t\t\tHI STAFF!!!!!" << endl;
    try
    {
        // static int try_no = 0;
        string username, password;
        string original_password = "4321";
        string original_username = "work";

        cout << "\n\n\t\t\t\tUSERNAME:";
        cin >> username;
        cout << "\n\n\t\t\t\tPASSWORD:";
        cin >> password;
        if (username == original_username && password == original_password)
        {
            cout << "\n\nLogged in Successfully!!!\n\n";
            return 1;
            // needs the next function call here; next screen;
        }
        else
        {
            throw 101;
        }
    }
    catch (int x)
    {
        static int try_no = 2;
        if (try_no > 0)
        {
            try_no--;
            cout << "Incorrect Password!!!" << endl
                 << "Only " << try_no + 1 << " chances remaining" << endl;
            loginscreen('a');
        }
        else
        {
            cout << "Exceeded Limits!!!!Come back in a while" << endl;
            exit(0);
        }
    }
    // system("cls");
    return 0;
}

inline void shop ::heading()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "*" << setw(55) << "*" << endl;
    cout << "*" << setw(25) << "SHOP" << setw(30) << "*" << endl;
    cout << "*" << setw(55) << "*" << endl;
    cout << "--------------------------------------------------------" << endl;
}

//************ Class ItemFunc Function Definition**************

void ItemFunc ::main_menu()
{
    shop A;
    A.heading();

    int ch = 1, choice;
    shop obj;
    while (true)
    {
        cout << "\t\t\t 1 - MANAGER LOGIN\n\n\n\t\t\t 2 - STAFF LOGIN\n\n\n\t\t\t 3 - EXIT !\n";
        cout << "\n\n\t\t\tEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
            A.heading();
            obj.loginscreen(3);
            cout << "\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
            Menu(3);
            break;

        case 2:
            cout << "\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
            char c;
            A.heading();
            obj.loginscreen(c);
            cout << "\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
            Menu(c);
            break;

        case 3:
            cout << "Program Terminated !!!" << endl;
            exit(0);
            break;

        default:
            cout << "\nInvalid Input!! Please Try Again\n";
            break;
            cout << "\n\nPress any key to continue..." << endl;
            getch();
            system("cls");
        }
    }
    cout << "\n\nPress any key to continue..." << endl;
    getch();
    system("cls");
}

void ItemFunc::Menu(int)
{
    shop A;
    Sales obj;
    int ch = 1, choice;
    while (ch)
    {
        A.heading();
        cout << "\t\t --- WELCOME MANAGER --- " << endl;
        cout << "\t\t 1 - ADD TO STOCK" << endl;
        cout << "\t\t 2 - CHECK STOCK DETAILS" << endl;
        cout << "\t\t 3 - SEARCH ITEM FROM STOCK" << endl;
        cout << "\t\t 4 - DELETE ITEM FROM STOCK" << endl;
        cout << "\t\t 5 - CHECK SALES RECORD SHEET" << endl; // sales detail function
        cout << "\t\t 6 - EXPIRY REMINDER " << endl;
        cout << "\t\t 7 - QUANTITY REMINDER " << endl;
        cout << "\t\t 8 - CATEGORY WISE ITEM LISTING " << endl;
        cout << "\t\t 9 - GO TO MAIN MENU" << endl;

        cout << "\nEnter your choice: ";

        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            A.heading();
            Add_Item();
            break;

        case 2:
            A.heading();
            Stock_Details();
            break;

        case 3:
            A.heading();
            Search();
            break;

        case 4:
            A.heading();
            Delete_Item();
            break;

        case 5:
            A.heading();
            obj.Sales_Details();
            break;

        case 6:
            A.heading();
            Exp_Reminder();
            break;

        case 7:
            A.heading();
            Quan_Reminder();
            break;
        case 8:
            A.heading();
            Category_Listing();
            break;

        case 9:
            main_menu();
            break;

        default:
            cout << "\nInvalid Input!!Try Again :)\n";
            break;
        }
        cout << "\n\nPress any key to continue..." << endl;
        getch();
        system("cls");
    }
}

void ItemFunc::Menu(char)
{
    int ch = 1, choice;
    Sales obj;
    shop A;

    while (ch)
    {
        A.heading();
        cout << "\t\t --- WELCOME STAFF --- " << endl;
        cout << "\t\t 1 - CHECK STOCK DETAILS" << endl;
        cout << "\t\t 2 - SEARCH ITEM FROM STOCK" << endl;
        cout << "\t\t 3 - SALES ENTRY" << endl; // sales RECORD Function
        cout << "\t\t 4 - EXPIRY REMINDER " << endl;
        cout << "\t\t 5 - QUANTITY REMINDER " << endl;
        cout << "\t\t 6 - CATEGORY WISE ITEM LISTING " << endl;
        cout << "\t\t 7 - GO TO MAIN MENU " << endl;

        cout << "\n\t\t ENTER YOUR CHOICE : ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            A.heading();
            Stock_Details();
            break;

        case 2:
            A.heading();
            Search();
            break;

        case 3:
            A.heading();
            obj.Sales_Record();
            break;

        case 4:
            A.heading();
            Exp_Reminder();
            break;

        case 5:
            A.heading();
            Quan_Reminder();
            break;

        case 6:
            A.heading();
            Category_Listing();
            break;

        case 7:
            main_menu();
            break;
        }
        cout << "\n\nPress any key to continue..." << endl;
        getch();
        system("cls");
    }
}

void ItemFunc ::Add_Item()
{
    Item obj;
    fstream op;
    op.open("data.txt", ios::app);

    cout << "\t\t----ADD ITEM TO INVENTORY----" << endl;
    cout << "\tEnter Item Name: ";
    cin >> obj.item_name;

    cout << "\tItem Quantity: ";
    cin >> obj.quantity;
a:
    cout << "\tManufacturing Month Followed By Year (Example- 05 2020) :";
    cin >> obj.manu_month >> obj.manu_year;
    try
    {
        if (obj.manu_month <= 0 || obj.manu_month > 12 || obj.manu_year < 2018) // MONTH BETWEEN 1  TO  12  and 4 digit year
            throw 101;

        if (current_year() < obj.manu_year)
        { // MANU YEAR SHOULD NOT BE OF FUTURE DATE
            throw 103;
        }
        if (current_year() == obj.manu_year && current_month() < obj.manu_month)
        { // MANU MONTH SHOULD NOT BE OF FUTURE
            throw 102;
        }
    }
    catch (int x)
    {
        if (x == 101)
        {
            cout << "Invalid ! \n";
        }
        if (x == 102 || x == 103)
        {
            cout << "Date Yet To Arrive!!! Check Again !\n";
        }
        if (x == 104)
        {
            cout << "INVALID MANUFACTURING YEAR !!!\n";
        }
        goto a;
    }
b:
    cout << "\tExpiry Month Followed By Year (Example- 10 2021) :";
    cin >> obj.exp_month >> obj.exp_year;
    try
    {
        if (obj.exp_month <= 0 || obj.exp_month > 12) // month should be in between 1 to 12
            throw 102;

        if (obj.exp_year == current_year())
        {
            if (current_month() >= obj.exp_month)
            {
                throw 103;
            }
        }

        if (obj.exp_year <= obj.manu_year)
        {
            if (obj.exp_month <= obj.manu_month)
            {
                throw 104;
            }
        }
        if (current_year() > obj.exp_year)
        {
            throw 103;
        }
    }
    catch (int x)
    {
        if (x == 102)
            cout << "Invalid ! \n";

        if (x == 103)
            cout << "Item is already Expired !!!!"
                 << "\n";

        if (x == 104)
            cout << "ERROR : Expiry is early than manufacturing " << endl;

        goto b;
    }

    cout << "\tEnter Rate : Rs. ";
    cin >> obj.rate;
    // Dairy, Cheese, Eggs - Dairy
    // Cereals and Pulses - Cereals
    // Cleaners - Dishwash, soap - Cleaners
    // Spices, Salt - Spices
    // Snacks,  Packed Food - Snacks
    // Others
    int x;
y:
    cout << "\tItem Category :\n \t1. Dairy/Cheese/Eggs\n \t2. Cereals/Pulses\n \t3. Cleaners(Soap,Shampoos)\n \t4. Spices/Salts\n \t5. Snacks/Packed Food\n \t6. Others\n";
    cout << "\tEnter Your Choice:";
    cin >> x;
    switch (x)
    {
    case 1:
        SetCharArray("Dairy", obj.category);
        break;

    case 2:
        SetCharArray("Cereals", obj.category);
        break;

    case 3:
        SetCharArray("Cleaners", obj.category);
        break;

    case 4:
        SetCharArray("Spices", obj.category);
        break;

    case 5:
        SetCharArray("Snacks", obj.category);
        break;

    case 6:
        SetCharArray("Others", obj.category);
        break;

    default:
        cout << "\nInvalid Input";
        goto y;
        break;
    }
    cout << "\n";
    op.write((char *)&obj, sizeof(obj));
    op.close();
}

void ItemFunc ::Stock_Details()
{
    Item obj;
    ifstream file;
    file.open("data.txt");
    cout << "\nName\t\tQuantity\tMFG\t\tExpiry\t\tRate\t\tCategory\n";
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    while (file.read((char *)&obj, sizeof(obj)))
    {
        cout << obj.item_name << "\t\t";
        cout << obj.quantity << "\t\t";
        cout << obj.manu_month << "/" << obj.manu_year << "\t\t";
        cout << obj.exp_month << "/" << obj.exp_year << "\t\t";
        cout << obj.rate << "\t\t";
        cout << obj.category << "\t\t";
        cout << endl;
    }
    file.close();
}

void ItemFunc ::Exp_Reminder()
{
    Item obj;
    ifstream file;
    file.open("data.txt");
    int i = 0;
    while (file.read((char *)&obj, sizeof(obj)))
    {

        if (current_year() == obj.exp_year)
        {
            if (obj.exp_month - current_month() <= 2)
            {
                cout << obj.item_name << " with quantity " << obj.quantity << " Will be Expiring " << obj.exp_month - current_month() << " months.\n";
                i++;
            }
        }
    }
    if (i == 0)
        cout << "\n\t\tNOTHING TO WORRY ! NO ITEM NEAR TO EXPIRY !!!" << endl;
    file.close();
}

void ItemFunc ::Quan_Reminder()
{
    ifstream file;
    Item obj;
    file.open("data.txt", ios::in | ios::out);
    int i = 0;
    while (file.read((char *)&obj, sizeof(obj)))
    {

        if (obj.quantity <= 5)
        {
            cout << obj.item_name << " is less than minimum quantity\n"
                 << obj.quantity << " remaining only\n";
            i++;
        }
    }
    if (i == 0)
        cout << "\n\t\tNO ITEM WITH LESS QUANTITY\n";
    file.close();
    return;
}

void ItemFunc::Search()
{
    ifstream file;
    Item obj;
    bool fnd = false;
    char name[30];
    file.open("data.txt", ios::in | ios::out);
    cout << "\n Item name to search: ";
    cin >> name;
    while (file.read((char *)&obj, sizeof(obj)))
    {
        if (strcmp(name, obj.item_name) == 0)
        {
            fnd = true;
            cout << "\nITEM FOUND!!!" << endl;
            cout << "The Details of the Product found is as follows: " << endl;
            cout << "\t\tITEM NAME : " << obj.item_name << "\n";
            cout << "\t\tITEM QUANTITY : " << obj.quantity << "\n";
            cout << "\t\tMANUFACTURING : " << obj.manu_month << "/" << obj.manu_year << "\n";
            cout << "\t\tEXPIRY : " << obj.exp_month << "/" << obj.exp_year << "\n";
            cout << "\t\tRATE Rs. " << obj.rate << "\n";
            cout << "\t\tITEM CATEGORY : " << obj.category << "\n";
            cout << endl;
        }
    }
    if (fnd == false)
    {
        int ch;
        cout << "ITEM NOT FOUND\n";
        cout << "ENTER 0 to RETURN ELSE ANY NUMBER TO CONTINUE\n";
        cin >> ch;
        if (ch)
            Search();
        else
        {
            file.close();
            return;
        }
    }
    file.close();
    return;
}

void ItemFunc ::Category_Listing()
{
    Item obj;
    ifstream file;
    char categ[30];
    int x, i = 1;
    string name;
    file.open("data.txt", ios::in | ios::out);
y:
    cout << "\t\tItem Category :\n 1. Dairy/Cheese/Eggs\n 2. Cereals/Pulses\n 3. Cleaners(Soap,Shampoos)\n 4. Spices/Salts\n 5. Snacks/Packed Food\n 6. Others\n";
    cout << "\nEnter category number to search:";
    cin >> x;
    switch (x)
    {
    case 1:
        SetCharArray("Dairy", categ);
        break;

    case 2:
        SetCharArray("Cereals", categ);
        break;

    case 3:
        SetCharArray("Cleaners", categ);
        break;

    case 4:
        SetCharArray("Spices", categ);
        break;

    case 5:
        SetCharArray("Snacks", categ);
        break;

    case 6:
        SetCharArray("Others", categ);
        break;

    default:
        cout << "\nInvalid Input";
        goto y;
        break;
    }
    while (file.read((char *)&obj, sizeof(obj)))
    {
        if (strcmp(categ, obj.category) == 0)
        {
            if (i == 1)
            {
                cout << "\nThe products under " << categ << " are:" << endl;
            }
            cout << i << ". " << obj.item_name << endl;
            i++;
        }
    }
    if (i == 1)
    {
        cout << "\n\t\tNO ITEM UNDER THIS CATEGORY !!!" << endl;
    }
    file.close();
    return;
}

void ItemFunc ::Delete_Item()
{
    Item obj;
    ifstream file;
    ofstream temp;
    file.open("data.txt");
    temp.open("temp.txt");
    int count = 0;
    char data[30];
    cout << "Enter Item Name to be deleted :";
    cin >> data;

    while (file.read((char *)&obj, sizeof(obj)))
    {
        if (strcmp(obj.item_name, data) != 0)
        {
            temp.write((char *)&obj, sizeof(obj));
        }
    }
    file.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

//************* Class Sales Function Definition*****************

// Keep Record of Sold items Only
void Sales::Sales_Record()
{
    Item obj;
    Sales obj2;
    fstream file, temp;
    ofstream sales;
    bool fnd = false;

    char data[30];
    // int quantity; // Number of Items sold

    char name[30];
    int inp_quantity;
    file.open("data.txt", ios::in | ios::out);
    temp.open("temp.txt", ios::in | ios::out | ios::trunc);
    sales.open("sales.txt", ios::app);
    file.seekg(0);

    cout << "Item  you sold:\n";
    cin >> name;
    while (file.read((char *)&obj, sizeof(obj)))
    {
        if (strcmp(name, obj.item_name) == 0)
        {
            cout << "\nEnter the Number of Items required: ";
            cin >> inp_quantity;
            strcpy(obj2.Item_Name, obj.item_name);
            obj2.Quantity = inp_quantity;
            obj2.amount = inp_quantity * obj.rate;
            time_t ttime = time(NULL);
            char *dt = ctime(&ttime);
            strcpy(obj2.Time, dt);

            sales.write((char *)&obj2, sizeof(obj2));
            obj.quantity -= inp_quantity;
            temp.write((char *)&obj, sizeof(obj));
            fnd = true;

            cout << "\n\t\tUPDATED IN SALES AS WELL AS STOCK DATA !!!\n";
        }
        else
        {
            temp.write((char *)&obj, sizeof(obj));
        }
    }
    if (!fnd)
    {
        int ch;
        cout << "\nItem Not Found!!!" << endl;

        cout << "ENTER 0 TO RETURN MENU ELSE ANY NUMBER TO CONTINUE\n";
        cin >> ch;
        if (ch)
        {
            temp.close();
            Sales_Record();
        }
    }
    temp.close();
    file.close();
    sales.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void Sales ::Sales_Details()
{
    Sales obj;
    fstream file;
    file.open("sales.txt", ios::in);
    cout << "Name\t\tSold Item\t\tAmount\t\tDate and Time" << endl;
    cout << "---------------------------------------------------" << endl;
    while (file.read((char *)&obj, sizeof(obj)))
    {
        cout << obj.Item_Name << "\t\t";
        cout << obj.Quantity << "\t\t";
        cout << obj.amount << "\t\t";
        cout << obj.Time << endl;
    }
    file.close();
}
