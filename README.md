# wholesale

Wholesale Project: https://docs.google.com/document/d/1G_YL3aAfIM7msWIukWqAWoNdTwhM84Who2U8uV4J-NY/edit?usp=sharing

Shared folder: https://drive.google.com/drive/folders/1Q83Wr3cFGj_SOFTqx6ThFYFHCiwnqyAp?usp=sharing

Wholesale Club Project Requirements:

Initial Setup:
* Draft UML class, use case, state diagrams
* Define data structures and class interfaces for members and sales
* Design UI layout
* Write Agile stories and define project workflow

** SYSTEM FUNCTIONALITY **

Member Management:
* Store member information
	- Name
	- Membership Number
	- Type
	- Expiration Date
	- Total Amount Spent
	- Rebate Amount (preferred members only)
* Add new members
	- Input: Name, Membership Type, Membership Number, Expiration Date
	- Validate input before adding
	- Store changes persistently
* Delete members
	- Remove a member from the system based on the Membership Number
	- Prevent deletion of non-existent members
	- Update stored data
* Modify existing member info
	- Update membership type, expiration date, etc
	- Changes must be saved
* Check membership expiration
	- Enter a month to get list of members who will expire that month
	- Include dues amount
* Determine if a basic member should upgrade to preferred status 
	- If total spending exceeds $1200 per year, suggest
* Determine if a preferred member should downgrade to basic
	- If rebate < $15 per year, suggest
* Calculate membership dues
	- Basic: $60 per year
	- Preferred $75 per year
	- Report dues per member sorted by membership type and name

Sales Processing:
* Read and parse five sales files including
	- Member number
	- Items purchased
	- Pirces (max 100 items per trip)
	- Update member's total spending
* Associate sales data with the correct member
* Calculate rebates (5% for preferred members)
	- Store rebates in membership records
* Account for sales tax (8.75%)

Report Generation:
* Daily sales report 
	- Items sold
	- Total revenue of the day
	- Members who shopped
	- Count Basic vs Preferred members ship shopped
* Yearly sales report
	- Best/worst performing items
	- Total revenue for the year
	- All items sold in the year

* Retrieve Total Purchases by Member
	- Input: Membership Number or Name.
	- Show total purchases for that member.
* Generate Total Purchases Report (Sorted by Membership Number)
	- Show grand total for all purchases.
* Generate Rebate Report for Preferred Members
	- Sorted by Membership Number.
	- Show calculated rebate per member.
* Generate Membership Dues Report
	- Show amount paid per year by each member.
	- Sort by membership type and name.

* Retrieve Item Sales Report (Search by Item Name)
	- Enter Item Name.
	- Display total quantity sold.
	- Show total sales revenue.
* Generate Report of Items Sold (Sorted by Item Name)
	- List quantity of each item sold.
	- Sort alphabetically.

* Filter reports by membership type
	- View basic members only, preferred members only, or all

Data Persistence:
* Save all updates between executions (members, sales, rebates)
* Validate file integrity and format before processing
	- No duplicate transactions
* Handle invalid member types (basic or preferred)
* Handle invalid item names (error if item does not exist in sales data)

Graphical User Interface (GUI):
* Display member and sales data
* Allow filtering reports dynamically
* Search for a member by name or ID
* Retrieve purchase history, rebate, membership details
* User-friendly navigation
* Handle input errors
