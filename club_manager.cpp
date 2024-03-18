#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <vector>

using namespace std;

// Structure to hold member information
struct Member
{
    int ID;
    char name[20];
    char post[20];
    string club; // Changed to string to hold club name
    long long int Phone_no;
};

// Function prototypes
void mainmenu();
void addmember();
void deletemember();
void searchmember();
void viewmember();
void editmember();
void returnfunc();
void password();
void addclub();
void viewclubs();
void deleteClub();
string selectClub(); // Function to select club by name

// Main function
int main()
{
    password(); // Prompt for password on startup
    return 0;
}

// Main menu function
void mainmenu()
{
    system("cls"); // Clear screen
    cout << "============== MAIN MENU ==============" << endl;
    cout << "==\t1. Add Members               ==" << endl;
    cout << "==\t2. Delete Members            ==" << endl;
    cout << "==\t3. Search Members            ==" << endl;
    cout << "==\t4. View Members              ==" << endl;
    cout << "==\t5. Edit Members Information  ==" << endl;
    cout << "==\t6. Add Club                  ==" << endl;
    cout << "==\t7. Delete Club               ==" << endl;
    cout << "==\t8. View Clubs                ==" << endl;
    cout << "==\t9. Close application         ==" << endl;
    cout << "=======================================" << endl;
    cout << "Enter Your Choice: ";
    switch (getch())
    {
    case '1':
        addmember();
        break;
    case '2':
        deletemember();
        break;
    case '3':
        searchmember();
        break;
    case '4':
        viewmember();
        break;
    case '5':
        editmember();
        break;
    case '6':
        addclub();
        break;
    case '7':
        deleteClub();
        break;
    case '8':
        viewclubs();
        break;
    case '9':
        system("cls");
        cout << "\n\n\n======================================================================\n\n\n";
        cout << "\n\n\tTHANK YOU FOR USING DAIIT CLUB Management System\t\n\n";
        cout << "\n\n\n======================================================================\n\n\n";
        exit(0);
    default:
        system("cls"); // Clear screen
        cout << "\a";  // Beep sound for invalid choice
        cout << "Enter Valid Choice !";
        _sleep(500); // Wait for 0.5 sec.
        mainmenu();
    }
}

// Function to add a new member
void addmember()
{
    system("cls"); // Clear screen
    Member stu;
    ofstream fout("record_nxt.txt", ios::app); // Open file in append mode
    cout << "Add MEMBER INFO" << endl;
    cout << "Member ID: ";
    cin >> stu.ID;
    cout << "Name: ";
    cin.ignore();
    cin.getline(stu.name, 20);
    cout << "Post: ";
    cin.getline(stu.post, 20);
    stu.club = selectClub(); // Select club by name
    cout << "Phone Number: ";
    cin >> stu.Phone_no;
    fout << stu.ID << "\t" << stu.name << "\t" << stu.post << "\t" << stu.club << "\t" << stu.Phone_no << endl; // Write to file
    fout.close();
    cout << "The record is successfully added" << endl;
    cout << "Add any more (Y/N)? ";
    if (getch() == 'n' || getch() == 'N')
        mainmenu(); // Return to main menu
    else
        addmember(); // Add another member
}

// Function to delete a member
void deletemember()
{
    system("cls");                  // Clear screen
    ifstream fin("record_nxt.txt"); // Open file for reading
    ofstream fout("temp.txt");      // Temporary file for writing
    int d;
    bool found = false;
    Member stu;
    cout << "Enter the Member ID to delete: ";
    cin >> d;
    while (fin >> stu.ID >> stu.name >> stu.post >> stu.club >> stu.Phone_no)
    {
        if (stu.ID != d)
            fout << stu.ID << "\t" << stu.name << "\t" << stu.post << "\t" << stu.club << "\t" << stu.Phone_no << endl; // Write to temporary file
        else
            found = true;
    }
    fin.close();
    fout.close();
    remove("record_nxt.txt");             // Remove original file
    rename("temp.txt", "record_nxt.txt"); // Rename temporary file
    if (found)
        cout << "The record is successfully deleted" << endl;
    else
        cout << "No record found with ID " << d << endl;
    returnfunc();
}

// Function to search for a member
void searchmember()
{
    system("cls");                  // Clear screen
    ifstream fin("record_nxt.txt"); // Open file for reading
    int choice;
    cout << "=====================================" << endl;
    cout << "==\tSearch by:                 ==" << endl;
    cout << "==\t1. Member ID               ==" << endl;
    cout << "==\t2. Member Name             ==" << endl;
    cout << "==\t3. club Name               ==" << endl;
    cout << "==\t4. Return to MainMenu      ==" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice: ";
    switch (getch())
    {
    case '1':
    {
        system("cls"); // Clear screen
        int s;
        bool found = false;
        Member stu;
        cout << "Enter the Member ID to search: ";
        cin >> s;
        while (fin >> stu.ID >> stu.name >> stu.post >> stu.club >> stu.Phone_no)
        {
            if (stu.ID == s)
            {
                cout << "The Member is available" << endl;
                cout << "ID: " << stu.ID << endl;
                cout << "Name: " << stu.name << endl;
                cout << "Post: " << stu.post << endl;
                cout << "club: " << stu.club << endl; // Display club ID
                cout << "Phone Number: " << stu.Phone_no << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "No record found with ID " << s << endl;
        break;
    }
    case '2':
    {
        system("cls"); // Clear screen
        char s[20];
        bool found = false;
        Member stu;
        cout << "Enter the Member Name to search: ";
        cin.ignore();
        cin.getline(s, 20);
        while (fin >> stu.ID >> stu.name >> stu.post >> stu.club >> stu.Phone_no)
        {
            if (strcmp(stu.name, s) == 0)
            {
                cout << "The Member is available" << endl;
                cout << "ID: " << stu.ID << endl;
                cout << "Name: " << stu.name << endl;
                cout << "Post: " << stu.post << endl;
                cout << "club: " << stu.club << endl; // Display club ID
                cout << "Phone Number: " << stu.Phone_no << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No record found with name " << s << endl;
        break;
    }
    case '3':
    {
        system("cls"); // Clear screen
        string club;
        bool found = false;
        Member stu;
        club = selectClub(); // Select club by name
        system("cls");
        while (fin >> stu.ID >> stu.name >> stu.post >> stu.club >> stu.Phone_no)
        {
            if (stu.club == club)
            {
                cout << "The Member is available" << endl;
                cout << "ID: " << stu.ID << endl;
                cout << "Name: " << stu.name << endl;
                cout << "Post: " << stu.post << endl;
                cout << "club: " << stu.club << endl; // Display club ID
                cout << "Phone Number: " << stu.Phone_no << endl;
                cout << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No record found in club with ID " << club << endl;
        break;
    }
    case '4':
    {
        system("cls"); // Clear screen
        mainmenu();
        break;
    }
    default:
        system("cls"); // Clear screen
        cout << "\a";  // Beep sound for invalid choice
        cout << "Enter Valid Choice !";
        _sleep(500); // Wait for 0.5 sec.
        searchmember();
    }
    fin.close();
    cout << "Press ENTER to return to the search Member section...";
    getch();
    searchmember();
}

// Function to view all members
void viewmember()
{
    system("cls");                  // Clear screen
    ifstream fin("record_nxt.txt"); // Open file for reading
    Member stu;
    cout << "Members List" << endl;
    cout << "<MEM_ID>\t<MEMBER NAME>\t<Post>\t<club>\t<PHONE_NO>" << endl;
    while (fin >> stu.ID >> stu.name >> stu.post >> stu.club >> stu.Phone_no)
    {
        cout << "<" << stu.ID << ">\t<" << stu.name << ">\t<" << stu.post << ">\t<" << stu.club << ">\t<" << stu.Phone_no << ">" << endl;
    }
    fin.close();
    returnfunc();
}

// Function to edit member information
void editmember()
{
    system("cls");                  // Clear screen
    ifstream fin("record_nxt.txt"); // Open file for reading
    ofstream fout("temp.txt");      // Temporary file for writing
    if (!fin || !fout)
    {
        cerr << "Error: Unable to open files for editing." << endl;
        return;
    }
    int s;
    bool found = false;
    Member stu;
    cout << "Edit MEMBER info" << endl;
    cout << "Enter the Member ID to edit: ";
    cin >> s;
    while (fin >> stu.ID >> stu.name >> stu.post >> stu.club >> stu.Phone_no)
    {
        if (stu.ID == s)
        {
            cout << "The Member is available" << endl;
            cout << "Name: ";
            cin.ignore();
            cin.getline(stu.name, sizeof(stu.name));
            cout << "Post: ";
            cin.getline(stu.post, sizeof(stu.post));
            stu.club = selectClub(); // Select club by name
            cout << "Phone Number: ";
            cin >> stu.Phone_no;
            found = true;
        }
        fout << stu.ID << "\t" << stu.name << "\t" << stu.post << "\t" << stu.club << "\t" << stu.Phone_no << endl;
    }
    fin.close();
    fout.close();
    remove("record_nxt.txt");
    rename("temp.txt", "record_nxt.txt");
    if (!found)
    {
        cout << "No record found with ID " << s << endl;
    }
    else
    {
        cout << "Member information updated successfully" << endl;
    }
    returnfunc();
}

// Function to return to main menu
void returnfunc()
{
    cout << "Press ENTER to return to the main menu...";
    getch();
    mainmenu();
}

// Function to prompt for password
void password()
{
    system("cls");                              // Clear screen
    char pass[10], ch, password[10] = "123456"; // Define password
    int i = 0;
    cout << "* Please check readme.txt file before running code !" << endl;
    cout << endl;
    cout << "========= DAIICT CLUB MANAGEMENT SYSTEM =========" << endl;
    cout << "\nEnter the password to login: ";
    while (ch != 13) // Loop until Enter key is pressed
    {
        ch = getch();
        if (ch != 13 && ch != 8) // Display '*' for each character entered
        {
            cout << "*";
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password) == 0) // Check if password matches
    {
        cout << "\nPassword Matched!!" << endl;
        cout << "Loading ";
        for (i = 0; i <= 6; i++)
        {
            cout << ".";
            _sleep(200); // Wait for 0.2 seconds
        }
        system("cls");
        mainmenu(); // Go to main menu
    }
    else
    {
        cout << "\nPassword is incorrect!!!\a" << endl;
        cout << "\tENTER correct password" << endl;
        getch(); // Wait for user input
        main();  // Restart the program
    }
}

// Function to add club
void addclub()
{
    system("cls");
    ofstream fout("clubs.txt", ios::app);
    char clubName[20];
    cout << "Enter Club Name: ";
    cin.getline(clubName, 20);
    fout << clubName << endl;
    fout.close();
    cout << "Club added successfully!" << endl;
    cout << "Add any more (Y/N)? ";
    if (getch() == 'n' || getch() == 'N')
        mainmenu(); // Return to main menu
    else
        addclub(); // Add another club
}

// Function to select club by name
string selectClub()
{
    ifstream fin("clubs.txt");
    vector<string> clubs;
    string clubName;
    int club = 1;

    cout << "Select Club:" << endl;
    cout << "----------------" << endl;

    while (getline(fin, clubName))
    {
        clubs.push_back(clubName);
        cout << club << ". " << clubName << endl;
        club++;
    }

    fin.close();

    cout << "----------------" << endl;

    int choice;
    cout << "Enter Club ID: ";
    cin >> choice;

    if (choice < 1 || choice > clubs.size())
    {
        cout << "Invalid Club ID" << endl;
        _sleep(500);
        mainmenu();
    }

    return clubs[choice - 1];
}

// Function to View all the Clubs.
void viewclubs()
{
    system("cls");             // Clear screen
    ifstream fin("clubs.txt"); // Open file for reading
    string club;
    int i = 1;
    cout << "Members List" << endl;
    cout << "<CLUBS>" << endl;
    while (fin >> club)
    {
        cout << "<" << i << "." << club << ">" << endl;
        i++;
    }
    fin.close();
    returnfunc();
}

// Function to delete club
void deleteClub()
{
    system("cls");             // Clear Screen
    ifstream fin("clubs.txt"); // Open file for reading
    ofstream fout("temp.txt"); // Open file for writing

    vector<string> clubs;
    string clubName;
    int clubID = 1;
    cout << "Select Club to Delete:" << endl;
    cout << "----------------" << endl;
    while (getline(fin, clubName))
    {
        clubs.push_back(clubName);
        cout << clubID << ". " << clubName << endl;
        clubID++;
    }
    fin.close();

    cout << "----------------" << endl;
    int choice;
    cout << "Enter Club ID to Delete: ";
    cin >> choice;
    if (choice < 1 || choice > clubs.size())
    {
        cout << "Invalid Club ID!" << endl;
        _sleep(500);
        deleteClub();
    }
    cout << "Deleting club: " << clubs[choice - 1] << endl;
    clubs.erase(clubs.begin() + choice - 1);
    fout.close();

    ofstream fout2("clubs.txt");
    for (const string &club : clubs)
    {
        fout2 << club << endl;
    }
    fout2.close();
    cout << "Club deleted successfully!" << endl;
    returnfunc();
}
