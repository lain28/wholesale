#ifndef MEMBERSERVICE_H
#define MEMBERSERVICE_H

#include "../core/Member.h"
#include <vector>
#include <string>

class MemberService {
private:
    std::vector<Member> members;
    std::string DATA_FILE;  

    // Helper functions
    bool isDuplicateMembershipNumber(int membershipNumber);
    int generateMembershipNumber();
    std::string calculateExpirationDate();
    bool isValidMembershipType(const std::string& type);

public:
    // Constructor Declaration
    MemberService(const std::string& dataFilePath = "data/members.txt");

    // Load and Save Data
    void loadData();
    void saveData();

    // Add Member Function
    void addMember(const std::string& name, const std::string& membershipType);

    // Display Members
    void displayAllMembers() const;

    // Getter for Tests
    const std::vector<Member>& getMembers() const { return members; }
};

#endif // MEMBERSERVICE_H

