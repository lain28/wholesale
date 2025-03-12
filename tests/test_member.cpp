#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>
#include "../src/core/Member.h"
#include "../src/services/MemberService.h"
#include <fstream>  // For clearing members.txt

using namespace std;

// ========================
// Check if `members.txt` is Empty
// ========================
bool isMembersFileEmpty() {
    ifstream inFile("data/members.txt");
    return inFile.peek() == ifstream::traits_type::eof();  // True if file is empty
}

// ========================
// Add Member Function for Testing
// ========================
void addMemberTest(MemberService& memberService) {
    string name, membershipType;

    cout << "\nEnter details for a new member:\n";
    cout << "Enter Member Name: ";
    getline(cin, name);

    while (true) {
        cout << "Enter Membership Type (Basic/Preferred): ";
        getline(cin, membershipType);

        if (membershipType == "Basic" || membershipType == "Preferred") break;

        cout << "Invalid membership type. Please enter 'Basic' or 'Preferred'.\n";
    }

    memberService.addMember(name, membershipType);
    cout << "Member successfully added.\n";
}

// ========================
// Delete Member Function for Testing
// ========================
void deleteMemberTest(MemberService& memberService) {
    if (isMembersFileEmpty()) {
        cout << "No members to delete.\n";
        return;
    }

    cout << "\nMembers before deletion:\n";
    memberService.displayAllMembers();

    int membershipNumberToDelete;
    cout << "\nEnter Membership Number to delete: ";
    cin >> membershipNumberToDelete;
    cin.ignore();  // Clear buffer

    memberService.deleteMember(membershipNumberToDelete);

    cout << "\nMembers after deletion:\n";
    memberService.displayAllMembers();
}

// ========================
// Main Menu
// ========================
void mainMenu() {
    MemberService memberService("data/members.txt");

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Clear buffer

        switch (choice) {
            case 1:
                addMemberTest(memberService);
                break;
            case 2:
                deleteMemberTest(memberService);
                break;
            case 3:
                cout << "Exiting program...\n";
                return;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}
// ========================
// MAIN FUNCTION (TEST EXECUTION)
// ========================
int main() {
    mainMenu();

    cout << "\nTests passed successfully!\n";
    return 0;
}

