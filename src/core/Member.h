// Member.h (storing member info)
#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;

class Member {
private:
    string name;
    int membershipNumber;
    string membershipType; // "Basic" or "Preferred"
    string expirationDate; // Format: MM/YYYY
    double totalAmountSpent;
    double rebateAmount;   // Preferred members only

public:
    // Constructor
    Member(const string& name, int number, const string& type,
           const string& expiration, double totalSpent = 0.0, double rebate = 0.0);

    // Getters
    string getName() const;
    int getMembershipNumber() const;
    string getMembershipType() const;
    string getExpirationDate() const;
    double getTotalAmountSpent() const;
    double getRebateAmount() const;

    // Setters
    void setTotalAmountSpent(double amount);
    void setRebateAmount(double rebate);

    // Display member info (for debugging or display purposes)
    void displayMemberInfo() const;
};

#endif // MEMBER_H

