#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
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
void view_members();
void search_member();
void return_to_main_menu();
string select_category();
void add_new_club();
string select_club();
void Loading();
int password();
bool is_member_exists(int memberID);
void view_clubs();

// Function to display main menu
void main_menu()
{
    system("cls");
    cout << "\n============== MAIN MENU ==============" << endl;
    cout << "||\t  1. Add Member              ||" << endl;
    cout << "||\t  2. Delete Member           ||" << endl;
    cout << "||\t  3. Search Member           ||" << endl;
    cout << "||\t  4. View Members            ||" << endl;
    cout << "||\t  5. Add Club                ||" << endl;
    cout << "||\t  6. Delete Club             ||" << endl;
    cout << "||\t  7. View Clubs              ||" << endl;
    cout << "||\t  8. Close Application       ||" << endl;
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
        cout << "\n\n\n======================================================================" << endl;
        cout << "||                                                                  ||" << endl;
        cout << "||                                                                  ||" << endl;
        cout << "||          THANK YOU FOR USING CLUB MANAGEMENT SYSTEM :)           ||" << endl;
        cout << "||                                                                  ||" << endl;
        cout << "||                     Members (noCapCoderz) :                      ||" << endl;
        cout << "||                         RAMOLIYA SHIVAM                          ||" << endl;
        cout << "||                          PRANAV MANDANI                          ||" << endl;
        cout << "||                           VED MUNGRA                             ||" << endl;
        cout << "||                         PRATHAM LAKHANI                          ||" << endl;
        cout << "||                                                                  ||" << endl;
        cout << "======================================================================\n\n\n";
        exit(0);
    default:
        system("cls");
        cout << "\a"; // Beep sound for invalid choice
        cout << "\nEnter Valid Choice !";
        _sleep(1000); // Wait for 0.5 sec.
        main_menu();
    }
}
//Function to add a new member.

// Function for Loading page
void Loading()
{
    system("cls"); // Clears the Screen
    char ch;
    cout << endl;
    cout << "           WE HEARTLY WELCOMES YOU :)           " << endl;
    cout << "==============================================" << endl;
    cout << "||          CLUB MANAGEMENT SYSTEM          ||" << endl;
    cout << "||            By noCapCoderz :)             ||" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "||                Members :                 ||" << endl;
    cout << "||             RAMOLIYA SHIVAM              ||" << endl;
    cout << "||              PRANAV MANDANI              ||" << endl;
    cout << "||                VED MUNGRA                ||" << endl;
    cout << "||             PRATHAM LAKHANI              ||" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << " Press any KEY to enter our the System.....";
    getch();
    system("cls"); // Clears the Screen
    cout << endl;
    cout << "           WE HEARTLY WELCOMES YOU :)           " << endl;
    cout << "==============================================" << endl;
    cout << "||          CLUB MANAGEMENT SYSTEM          ||" << endl;
    cout << "||            By noCapCoderz :)             ||" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "||                Members :                 ||" << endl;
    cout << "||             RAMOLIYA SHIVAM              ||" << endl;
    cout << "||              PRANAV MANDANI              ||" << endl;
    cout << "||                VED MUNGRA                ||" << endl;
    cout << "||             PRATHAM LAKHANI              ||" << endl;
    cout << "==============================================" << endl;
    cout << endl;
    cout << "\n\t\tPlease Wait!!" << endl;
    cout << "\t\tLoading ";
    for (int i = 0; i < 7; i++)
    {
        cout << ".";
        _sleep(300); // Wait for 0.3 seconds
    }
    system("cls"); // Clears the Screen
    main_menu();
}

// Function to prompt for password
int password()
{
    system("cls");                              // Clears the Screen
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
        if (is_member_exists(member.ID))
        {
            cout << "Error: Member with ID " << member.ID << " already exists!" << endl;
            cout << "Press any key to continue...";
            getch();
            main_menu();
        }
        cin.ignore();
        cout << "Name: ";
        getline(cin, member.name);
        cout << "Post: ";
        getline(cin, member.post);
        member.club = select_club(); // Select club by name
        cout << "Phone_Number: ";
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
        cout << "\nWrong Password !";
        _sleep(1000);
        add_new_member();
    }
}

// Check if Member ia already Exist or not
bool is_member_exists(int memberID)
{
    ifstream fin(FILENAME); // Open File to Read
    if (!fin.is_open())
    {
        cerr << "Error opening file for reading!" << endl;
        exit(1);
    }

    Member member;
    string line;
    while (getline(fin, line))
    {
        // Creat stringstream object ss and initialize it a Line.
        // This stringstream will allow us to treat the string 'line' as a stream, facilitating parsing.
        stringstream ss(line);

        string get_line; // Declare a string variable named 'get_line' to store each extracted token.

        getline(ss, get_line, ',');
        // Read data from the stringstream 'ss' until a comma (',') is encountered.
        // Store the extracted data in the 'get_line' variable.

        member.ID = stoi(get_line); // Convert String to Integer of get_line

        if (member.ID == memberID)
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

// Function to delete a member
void delete_member()
{
    system("cls");
    int x = password();
    if (x)
    {
        cout << "\nPassword Matched !";
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
        cout << "\nWrong Password !";
        _sleep(1000);
        delete_member();
    }
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
    cout << "\n======================================= MEMBER LIST SORT CLUBWISE =======================================" << endl;
    cout << "||                                                                                                     ||" << endl;
    cout << "||  <MEM_ID>" << setw(13) << left << "\t<MEMBER NAME>" << setw(13) << left << "\t\t<Post>" << setw(13) << left << "\t\t<club>" << setw(13) << left << "\t\t<PHONE_NO>     ||" << endl;
    for (const auto &member : members)
    {
        cout << "||  " << member.ID << "\t\t" << setw(15) << left << member.name << "\t\t" << setw(15) << left << member.post << "\t\t" << setw(15) << left << member.club << "\t\t" << setw(15) << left << member.Phone_no << "||" << endl;
    }
    cout << "=========================================================================================================";
    return_to_main_menu();
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
            cout << "ID    : " << member.ID << endl;
            cout << "Name  : " << member.name << endl;
            cout << "Post  : " << member.post << endl;
            cout << "Club  : " << member.club << endl;
            cout << "Ph_No.: " << member.Phone_no << endl;
            cout << endl;
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
                cout << "ID    : " << member.ID << endl;
                cout << "Name  : " << member.name << endl;
                cout << "Post  : " << member.post << endl;
                cout << "Club  : " << member.club << endl;
                cout << "Ph_No.: " << member.Phone_no << endl;
                cout << endl;
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
                cout << "ID    : " << member.ID << endl;
                cout << "Name  : " << member.name << endl;
                cout << "Post  : " << member.post << endl;
                cout << "Club  : " << member.club << endl;
                cout << "Ph_No.: " << member.Phone_no << endl;
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
        cout << "\nReturning to Main Menu...";
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

// Function to return to main menu
void return_to_main_menu()
{
    cout << "\nPress ENTER to return to the main menu...";
    getch();
    main_menu();
}

// Function to select club category
string select_category()
{
    string s[5];
    s[0] = "Skill Development";
    s[1] = "Art";
    s[2] = "Technical";
    s[3] = "Social";
    s[4] = "Commerce";

    cout << "\n=========== SELECT CLUB CATEGORY ===========" << endl;
    cout << "||           1. Skill Development         ||" << endl;
    cout << "||           2. Art                       ||" << endl;
    cout << "||           3. Technical                 ||" << endl;
    cout << "||           4. Social                    ||" << endl;
    cout << "||           5. Commerce                  ||" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    cout << "Enter choice : ";
    int p;
    cin >> p;
    cin.ignore();
    if (p < 1 || p > 5)
    {
        cout << "Invalid Choice" << endl;
        _sleep(1000);
        return_to_main_menu();
    }
    else
        return s[p - 1];
}

// Function to add club
void add_new_club()
{
    system("cls");
    int x = password();
    if (x)
    {
        cout << "\nPassword Matched !";
        _sleep(1000);
        system("cls");
        ofstream fout(CLUBS_FILE, ios::app);
        string clubName;
        string clubCategory;
        clubCategory = select_category();
        cout << "\nEnter Club Name: ";
        getline(cin, clubName);
        fout << clubName << "," << clubCategory << endl;
        fout.close();
        cout << "Club added successfully!" << endl;
        return_to_main_menu();
    }
    else
    {
        system("cls");
        cout << "\nWrong Password !";
        _sleep(1000);
        add_new_club();
    }
}

// Function to select club by name
string select_club()
{
    ifstream fin(CLUBS_FILE);
    if (!fin.is_open())
    {
        cout << "Error opening file: " << CLUBS_FILE << endl;
        return "";
    }

    vector<string> clubs;
    string line;
    int club = 1;

    cout << "\nSelect Club:" << endl;
    cout << "==================" << endl;

    while (getline(fin, line))
    {
        // srtringstream as mentioned above
        stringstream ss(line);
        string clubName;
        getline(ss, clubName, ','); // Read only the first get_line (club name)
        clubs.push_back(clubName);
        cout << club << ". " << clubName << endl;
        club++;
    }

    fin.close();

    cout << "==================" << endl;
    int choice;
    cout << "Enter Club ID: ";
    cin >> choice;

    if (choice < 1 || choice > clubs.size())
    {
        cout << "Invalid Club ID" << endl;
        return_to_main_menu();
    }

    return clubs[choice - 1];
}

// Function to View all the Clubs.
void view_clubs()
{
    system("cls");            // Clears the Screen
    ifstream fin(CLUBS_FILE); //  File Open in read Mode
    if (!fin.is_open())
    {
        cout << BLACK <<  "Error opening file: " << CLUBS_FILE << endl << RESET;
        return;
    }

    string line;
    int i = 1;
    cout << RED <<  "\nClubs List" << endl << RESET;
    cout << MAGENTA <<  setw(30) << left << "<CLUBS>" << setw(25) << left << "<CLUB_CATEGORY>" << endl << RESET;

    while (getline(fin, line))
    {
        // stringstream as mentioned above
        stringstream ss(line);
        vector<string> tokens;
        string token;

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() >= 2)
        {
            if(i<10){
            cout << BLUE << "0" << i << ". " << setw(30) << left << tokens[0] << setw(25) << left << tokens[1] << endl << RESET;
            i++;
            }
            else{
            cout <<BLUE << i << ". " << setw(30) << left << tokens[0] << setw(25) << left << tokens[1] << endl << RESET;
            i++;
            }
        }
    }
    return_to_main_menu();
    fin.close();
}
