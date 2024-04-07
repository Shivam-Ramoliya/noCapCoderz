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
