#include <iostream>
#include <cassert>     // For assertions
#include "../src/core/Member.h" // Correct relative path for the class file

using namespace std;

void testMemberCreation() {
    Member member1("John Doe", 1001, "Basic", "12/2025", 350.00);
    Member member2("Jane Smith", 1002, "Preferred", "06/2024", 1200.00, 60.00);

    // Testing data storage and retrieval
    assert(member1.getName() == "John Doe");
    assert(member1.getMembershipNumber() == 1001);
    assert(member1.getMembershipType() == "Basic");
    assert(member1.getExpirationDate() == "12/2025");
    assert(member1.getTotalAmountSpent() == 350.00);
    assert(member1.getRebateAmount() == 0.00);

    assert(member2.getName() == "Jane Smith");
    assert(member2.getMembershipNumber() == 1002);
    assert(member2.getMembershipType() == "Preferred");
    assert(member2.getExpirationDate() == "06/2024");
    assert(member2.getTotalAmountSpent() == 1200.00);
    assert(member2.getRebateAmount() == 60.00);

    cout << "[PASS] Member creation tests passed successfully" << endl;
}

void testMemberModification() {
    Member member("Alice Johnson", 1003, "Basic", "03/2026", 500.00);

    // Modify total spent and rebate
    member.setTotalAmountSpent(700.00);
    member.setRebateAmount(35.00);

    assert(member.getTotalAmountSpent() == 700.00);
    assert(member.getRebateAmount() == 35.00);

    cout << "[PASS] Member modification tests passed successfully" << endl;
}

int main() {
    testMemberCreation();
    testMemberModification();

    return 0;
}

