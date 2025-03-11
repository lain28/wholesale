#include "MemberService.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>       
#include <cstdlib>     
using namespace std;

// ========================
// Helper Functions
// ========================
bool MemberService::isDuplicateMembershipNumber(int membershipNumber) {
    for (vector<Member>::iterator it = members.begin(); it != members.end(); ++it) {
        if (it->getMembershipNumber() == membershipNumber) {
            return true;
        }
    }
    return false;
}

int MemberService::generateMembershipNumber() {
    srand(time(0));
    int membershipNumber;
    do {
        membershipNumber = rand() % 90000 + 10000;
    } while (isDuplicateMembershipNumber(membershipNumber));
    return membershipNumber;
}

// Constructor initialization for DATA_FILE
MemberService::MemberService(const std::string& dataFilePath) : DATA_FILE("data/members.txt") {}

string MemberService::calculateExpirationDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1901;

    ostringstream expirationDate;
    expirationDate << setfill('0') << setw(2) << month
                   << "/" << year;

    return expirationDate.str();
}

bool MemberService::isValidMembershipType(const string& type) {
    return (type == "Basic" || type == "Preferred");
}

// ========================
// Load & Save Data (Persistence)
// ========================
void MemberService::loadData() {
    members.clear();  // Clear data to avoid duplication
    ifstream file(DATA_FILE.c_str());
    if (!file) {
        cerr << "No members added.\n";
        return;
    }

    string name, membershipType, expirationDate;
    int membershipNumber;
    double totalSpent, rebateAmount;

    while (file >> ws && getline(file, name)) {
        file >> membershipNumber >> membershipType >> expirationDate >> totalSpent >> rebateAmount;
        members.push_back(Member(name, membershipNumber, membershipType, expirationDate, totalSpent, rebateAmount));
    }

    file.close();
}

void MemberService::saveData() {
    ofstream file(DATA_FILE.c_str());
    if (!file) {
        cerr << "Error: Could not open " << DATA_FILE << " for writing.\n";
        return;
    }

    for (vector<Member>::iterator it = members.begin(); it != members.end(); ++it) {
        file << it->getName() << "\n"
             << it->getMembershipNumber() << " "
             << it->getMembershipType() << " "
             << it->getExpirationDate() << " "
             << fixed << setprecision(2)
             << it->getTotalAmountSpent() << " "
             << it->getRebateAmount() << "\n";
    }

    file.close();
}

// ========================
// Add New Member 
// ========================
void MemberService::addMember(const std::string& name, const std::string& membershipType) {
    loadData();  // ✅ Load existing members before adding a new one

    if (!isValidMembershipType(membershipType)) {
        cout << "❌ Error: Invalid membership type. Use 'Basic' or 'Preferred'.\n";
        return;
    }

    int membershipNumber = generateMembershipNumber();
    string expirationDate = calculateExpirationDate();
    double totalSpent = 0.0;
    double rebateAmount = (membershipType == "Preferred") ? 0.0 : 0.0;

    members.push_back(Member(name, membershipNumber, membershipType, expirationDate, totalSpent, rebateAmount));

    // Save Data to File
    saveData();

    cout << "✅ Member successfully added!\n";
    cout << "Name: " << name << "\nMembership Number: " << membershipNumber
         << "\nMembership Type: " << membershipType
         << "\nExpiration Date: " << expirationDate << "\n";
}

