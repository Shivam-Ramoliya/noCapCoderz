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
