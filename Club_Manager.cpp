#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <conio.h>

using namespace std;

// Structure to hold member information
struct Member
{
    int ID;
    string name;
    string post;
    string club;
    long long int Phone_no;
};

// Function prototypes
void main_menu();
void add_new_member();
void delete_member();
void search_member();
void view_members();
void return_to_main_menu();
void Loading();
void add_new_club();
void view_clubs();
void delete_club();
int password();
bool is_member_exists(int memberID);
string select_club();

// Global constants
const string FILENAME = "record.csv";
const string CLUBS_FILE = "clubs.csv";

// Function to display main menu
void main_menu()
{
    system("cls");
    cout << "\n============== MAIN MENU ==============" << endl;
    cout << "==\t1. Add Member                ==" << endl;
    cout << "==\t2. Delete Member             ==" << endl;
    cout << "==\t3. Search Member             ==" << endl;
    cout << "==\t4. View Members              ==" << endl;
    cout << "==\t5. Add Club                  ==" << endl;
    cout << "==\t6. Delete Club               ==" << endl;
    cout << "==\t7. View Clubs                ==" << endl;
    cout << "==\t8. Close Application         ==" << endl;
    cout << "=======================================" << endl;
    cout << "Enter Your Choice: ";

    switch (getch())
    {
    case '1':
        add_new_member();
        break;
    case '2':
        delete_member();
        break;
    case '3':
        search_member();
        break;
    case '4':
        view_members();
        break;
    case '5':
        add_new_club();
        break;
    case '6':
        delete_club();
        break;
    case '7':
        view_clubs();
        break;
    case '8':
        system("cls");
        cout << "\n\n\n======================================================================\n\n\n";
        cout << "\n\n\tTHANK YOU FOR USING CLUB Management System\t\n\n";
        cout << "\n\n\n======================================================================\n\n\n";
        exit(0);
    default:
        system("cls");
        cout << "\a"; // Beep sound for invalid choice
        cout << "\nEnter Valid Choice !";
        _sleep(1000); // Wait for 0.5 sec.
        main_menu();
    }
}

// Check if Member ia already Exist or not
bool is_member_exists(int memberID)
{
    ifstream fin(FILENAME);
    if (!fin)
    {
        cerr << "Error opening file for reading!" << endl;
        exit(1);
    }

    Member member;
    while (fin >> member.ID >> member.name >> member.post >> member.club >> member.Phone_no)
    {
        if (member.ID == memberID)
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

// Function to add a new member
void add_new_member()
{
    system("cls");
    int x = password();
    if (x)
    {
        cout << "\nPassword Matched !";
        _sleep(1000);
        system("cls");
        Member member;
        ofstream fout(FILENAME, ios::app);
        cout << "\nAdd MEMBER INFO" << endl;
        cout << "Member ID: ";
        cin >> member.ID;
        if (!is_member_exists(member.ID))
        {
            cout << "Error: Member with ID " << member.ID << " already exists!" << endl;
            cout << "Press any key to continue...";
            getch();
            main_menu();
            return;
        }
        cin.ignore();
        cout << "Name: ";
        getline(cin, member.name);
        cout << "Post: ";
        getline(cin, member.post);
        member.club = select_club(); // Select club by name
        cout << "Phone Number: ";
        cin >> member.Phone_no;
        fout << member.ID << "," << member.name << "," << member.post << "," << member.club << "," << member.Phone_no << endl;
        fout.close();
        cout << "The record is successfully added" << endl;
    flag:
        cout << "Add any more (Y/N)? ";
        switch (getch())
        {
        case 'Y':
        case 'y':
        {
            add_new_member(); // Add another member
            break;
        }
        case 'N':
        case 'n':
        {
            main_menu(); // Add another member
            break;
        }
        default:
        {
            system("cls"); // Clear screen
            cout << "\a\nEnter Valid Option !" << endl;
            _sleep(1000);
            goto flag;
        }
        }
    }
    else
    {
        system("cls");
        cout << "\nWrong Password !" << endl;
        _sleep(1000);
        add_new_member();
    }
}

// Function to delete a member
void delete_member()
{
    system("cls");
    int x = password();
    if (x)
    {
        cout << "\nPassword Matched !" << endl;
        _sleep(1000);
        system("cls");
        ifstream fin(FILENAME);
        ofstream fout("temp.csv");
        int del;
        bool found = false;
        Member member;
        cout << "\nEnter the Member ID to delete: ";
        cin >> del;
        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            member.ID = stoi(token);
            if (member.ID != del)
                fout << line << endl;
            else
                found = true;
        }
        fin.close();
        fout.close();
        remove(FILENAME.c_str());
        rename("temp.csv", FILENAME.c_str());
        if (found)
            cout << "The record is successfully deleted" << endl;
        else
            cout << "No record found with ID " << del << endl;
        return_to_main_menu();
    }
    else
    {
        system("cls");
        cout << "\nWrong Password !" << endl;
        _sleep(1000);
        delete_member();
    }
}

// Function to search for a member
void search_member()
{
    system("cls");
    ifstream fin(FILENAME);
    unordered_map<int, Member> memberMap;
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        Member member;
        string token;
        getline(ss, token, ',');
        member.ID = stoi(token);
        getline(ss, member.name, ',');
        getline(ss, member.post, ',');
        getline(ss, member.club, ',');
        getline(ss, token, ',');
        member.Phone_no = stoll(token);
        memberMap[member.ID] = member;
    }
    fin.close();
    int choice;
    cout << "\n=====================================" << endl;
    cout << "==\tSearch by:                 ==" << endl;
    cout << "==\t1. Member ID               ==" << endl;
    cout << "==\t2. Member Name             ==" << endl;
    cout << "==\t3. Club Name               ==" << endl;
    cout << "==\t4. Return to MainMenu      ==" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice: ";
    char ch = _getch();
    switch (ch)
    {

    case '1':
    {
        system("cls");
        int s;
        bool found = false;
        cout << "\nEnter the Member ID to search: ";
        cin >> s;
        if (memberMap.find(s) != memberMap.end())
        {
            Member member = memberMap[s];
            cout << "The Member is available" << endl;
            cout << "ID: " << member.ID << endl;
            cout << "Name: " << member.name << endl;
            cout << "Post: " << member.post << endl;
            cout << "Club: " << member.club << endl;
            cout << "Phone Number: " << member.Phone_no << endl;
            found = true;
        }
        if (!found)
        {
            cout << "No record found with ID " << s << endl;
        }
        cout << "Press ENTER to return to the search Member section...";
        _getch();
        search_member();
    }

    case '2':
    {
        system("cls");
        string s;
        bool found = false;
        cout << "\nEnter the Member Name to search: ";
        getline(cin, s);
        for (const auto &entry : memberMap)
        {
            Member member = entry.second;
            if (member.name == s)
            {
                cout << "The Member is available" << endl;
                cout << "ID: " << member.ID << endl;
                cout << "Name: " << member.name << endl;
                cout << "Post: " << member.post << endl;
                cout << "Club: " << member.club << endl;
                cout << "Phone Number: " << member.Phone_no << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No record found with name " << s << endl;
        }
        cout << "Press ENTER to return to the search Member section...";
        _getch();
        search_member();
    }

    case '3':
    {
        system("cls");
        string club;
        bool found = false;
        cout << "\Select the Club Name to search: ";
        club = select_club();
        system("cls");
        cout << "The Members of " << club << " Club is as Listed Below." << endl;
        for (const auto &entry : memberMap)
        {
            Member member = entry.second;
            if (member.club == club)
            {
                cout << "\nThe Member is available" << endl;
                cout << "ID: " << member.ID << endl;
                cout << "Name: " << member.name << endl;
                cout << "Post: " << member.post << endl;
                cout << "Club: " << member.club << endl;
                cout << "Phone Number: " << member.Phone_no << endl;
                cout << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "No record found in club with name " << club << endl;
        }
        cout << "Press ENTER to return to the search Member section...";
        _getch();
        search_member();
    }

    case '4':
    {
        cout << "\nReturning to Main Menu..." << endl;
        _sleep(1000);
        main_menu();
    }

    default:
    {
        system("cls");
        cout << "\a";
        cout << "\nEnter Valid Choice !" << endl;
        _sleep(1000);
        search_member();
    }
    }
}

// Comparison function to sort members based on club names
bool sort_clubs(const Member &a, const Member &b)
{
    return a.club < b.club;
}

// Function to view all members
void view_members()
{
    system("cls");
    ifstream fin(FILENAME);
    vector<Member> members;
    Member member;
    while (fin >> member.ID)
    {
        fin.ignore();
        getline(fin, member.name, ',');
        getline(fin, member.post, ',');
        getline(fin, member.club, ',');
        fin >> member.Phone_no;
        members.push_back(member);
    }
    fin.close();

    // Sort members by club name
    sort(members.begin(), members.end(), sort_clubs);

    // Displaying Member Sorted Clubwise.
    cout << "\n======================================== MEMBER LIST SORT CLUBWISE ========================================" << endl;
    cout << endl;
    cout << "<MEM_ID>\t\t<MEMBER NAME>\t\t<Post>\t\t<club>\t\t<PHONE_NO>" << endl;
    for (const auto &member : members)
        cout << "<" << member.ID << ">\t\t<" << member.name << ">\t\t<" << member.post << ">\t\t<" << member.club << ">\t\t<" << member.Phone_no << ">" << endl;
    return_to_main_menu();
}

// Function to return to main menu
void return_to_main_menu()
{
    cout << "\nPress ENTER to return to the main menu...";
    getch();
    main_menu();
}

// Function to add club
void add_new_club()
{
    system("cls");
    int x = password();
    if (x)
    {
        cout << "\nPassword Matched !" << endl;
        _sleep(1000);
        system("cls");
        ofstream fout(CLUBS_FILE, ios::app);
        string clubName;
        cout << "\nEnter Club Name: ";
        getline(cin, clubName);
        fout << clubName << endl;
        fout.close();
        cout << "Club added successfully!" << endl;
        return_to_main_menu();
    }
    else
    {
        system("cls");
        cout << "\nWrong Password !" << endl;
        _sleep(1000);
        add_new_club();
    }
}

// Function to select club by name
string select_club()
{
    ifstream fin(CLUBS_FILE);
    vector<string> clubs;
    string clubName;
    int club = 1;
    cout << "\nSelect Club:" << endl;
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
        _sleep(1000);
        main_menu();
    }
    return clubs[choice - 1];
}

// Function to View all the Clubs.
void view_clubs()
{
    system("cls");
    ifstream fin(CLUBS_FILE);
    string club;
    int i = 1;
    cout << "\nClubs List" << endl;
    cout << "<CLUBS>" << endl;
    while (getline(fin, club))
    {
        cout << "<" << i << "." << club << ">" << endl;
        i++;
    }
    fin.close();
    return_to_main_menu();
}

// Function to delete club
void delete_club()
{
    system("cls");
    int x = password();
    if (x)
    {
        cout << "\nPassword Matched !" << endl;
        _sleep(1000);
        system("cls");
        ifstream fin(CLUBS_FILE);
        if (!fin)
        {
            cerr << "Error: Unable to open clubs file for reading." << endl;
            return_to_main_menu();
        }
        vector<string> clubs;
        string clubName;
        int clubID = 1;
        cout << "\nSelect Club to Delete:" << endl;
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
            _sleep(1000);
            delete_club();
        }
        cout << "Deleting club: " << clubs[choice - 1] << endl;
        clubs.erase(clubs.begin() + choice - 1);
        ofstream fout("temp.csv");
        for (const string &club : clubs)
        {
            fout << club << endl;
        }
        fout.close();
        remove(CLUBS_FILE.c_str());
        rename("temp.csv", CLUBS_FILE.c_str());
        cout << "Club deleted successfully!" << endl;
        return_to_main_menu();
    }
    else
    {
        system("cls");
        cout << "\nWrong Password !" << endl;
        _sleep(1000);
        delete_club();
    }
}

// Function for Loading page
void Loading()
{
    system("cls");
    char ch;
    cout << endl;
    cout << "========= CLUB MANAGEMENT SYSTEM =========" << endl;
    cout << endl;
    cout << "Press ENTER to use the System.....";
    getch();
    system("cls");
    cout << endl;
    cout << "========= CLUB MANAGEMENT SYSTEM =========" << endl;
    cout << endl;
    cout << "\n\t\tPlease Wait!!" << endl;
    cout << "\t\tLoading ";
    for (int i = 0; i < 7; i++)
    {
        cout << ".";
        _sleep(300); // Wait for 0.3 seconds
    }
    system("cls");
    main_menu();
}

// Function to prompt for password
int password()
{
    system("cls");                              // Clear screen
    char pass[10], ch, password[10] = "123456"; // Define password
    int i = 0;
    cout << "* Please check Secret.txt file before running code !" << endl;
    cout << endl;
    cout << "\nEnter the password to Enter: ";
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
        return 1;
    }
    else
    {
        return 0;
    }
}

// Main function
int main()
{
    Loading();
    return 0;
}
