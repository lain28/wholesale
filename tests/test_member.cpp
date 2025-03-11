#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>
#include "../src/core/Member.h"
#include "../src/services/MemberService.h"
#include <fstream>  // For clearing members.txt

using namespace std;

// ========================
// Utility Function for Expiration Date Calculation
// ========================
std::string calculateExpectedExpirationDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1901;

    std::ostringstream expirationDate;
    expirationDate << std::setfill('0') << std::setw(2) << month
                   << "/" << year;

    return expirationDate.str();
}

// ========================
// Clear `members.txt` for Clean Testing
// ========================
void clearMembersFile() {
    std::ofstream file("data/members.txt", std::ofstream::trunc);  // Clear the file
    file.close();
}

// ========================
// TEST CASES FOR `MemberService` CLASS
// ========================

void testAddMemberWithInput() {
    MemberService memberService("data/members.txt"); // Uses the real data file

    cout << "\n💬 Enter details for a new member:\n";
    string name, membershipType;

    cout << "Enter Member Name: ";
    getline(cin, name);

    while (true) {
        cout << "Enter Membership Type (Basic/Preferred): ";
        getline(cin, membershipType);

        if (membershipType == "Basic" || membershipType == "Preferred") break;

        cout << "Invalid membership type. Please enter 'Basic' or 'Preferred'.\n";
    }

    memberService.addMember(name, membershipType);

    // Reload data to confirm persistence
    memberService.loadData();
    const vector<Member>& members = memberService.getMembers();

    assert(!members.empty());
    assert(members[members.size() - 1].getName() == name);
    assert(members[members.size() - 1].getMembershipType() == membershipType);

    cout << "[PASS] Member successfully added via user input.\n";
}

void testMembershipNumberFormat() {
    MemberService memberService("data/members.txt");

    memberService.loadData();
    const vector<Member>& members = memberService.getMembers();

    assert(members.back().getMembershipNumber() >= 10000 &&
           members.back().getMembershipNumber() <= 99999);

    cout << "[PASS] Membership number correctly generated as a 5-digit number.\n";
}

void testExpirationDateFromInput() {
    MemberService memberService("data/members.txt");

    memberService.loadData();
    const vector<Member>& members = memberService.getMembers();

    assert(members.back().getExpirationDate() == calculateExpectedExpirationDate());

    cout << "[PASS] Expiration date correctly set to one year from today.\n";
}

void testInitialAmountsFromInput() {
    MemberService memberService("data/members.txt");

    memberService.loadData();
    const vector<Member>& members = memberService.getMembers();

    assert(members.back().getTotalAmountSpent() == 0.0);
    assert(members.back().getRebateAmount() == 0.0);

    cout << "[PASS] Initial amounts set to $0.00 successfully.\n";
}

// ========================
// MAIN FUNCTION (TEST EXECUTION)
// ========================
int main() {
    clearMembersFile();  // Clean `members.txt` before running tests

    testAddMemberWithInput();
    testMembershipNumberFormat();
    testExpirationDateFromInput();
    testInitialAmountsFromInput();

    cout << "\nAll tests passed successfully!\n";
    return 0;
}

