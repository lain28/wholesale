#include "Member.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor Definition
Member::Member(const string& name, int number, const string& type,
               const string& expiration, double totalSpent, double rebate)
    : name(name), membershipNumber(number), membershipType(type),
      expirationDate(expiration), totalAmountSpent(totalSpent), rebateAmount(rebate) {}

// Getter Implementations
string Member::getName() const { return name; }
int Member::getMembershipNumber() const { return membershipNumber; }
string Member::getMembershipType() const { return membershipType; }
string Member::getExpirationDate() const { return expirationDate; }
double Member::getTotalAmountSpent() const { return totalAmountSpent; }
double Member::getRebateAmount() const { return rebateAmount; }

// Setter Implementations
void Member::setTotalAmountSpent(double amount) {
    totalAmountSpent = amount;
}

void Member::setRebateAmount(double rebate) {
    rebateAmount = rebate;
}

// Display Member Information
void Member::displayMemberInfo() const {
    cout << "Name: " << name << "\n"
         << "Membership Number: " << membershipNumber << "\n"
         << "Type: " << membershipType << "\n"
         << "Expiration Date: " << expirationDate << "\n"
         << fixed << setprecision(2)
         << "Total Amount Spent: $" << totalAmountSpent << "\n"
         << "Rebate Amount: $" << rebateAmount << "\n"
         << "---------------------------------\n";
}

