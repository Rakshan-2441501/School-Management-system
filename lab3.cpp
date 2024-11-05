#include<iostream>
using namespace std;
class details
{
public:
	void studentdeat(int s_id,string stud_nm,int fees,int totfees=90000)
	{
	cout << "Student Details:" << endl;
	cout << "Name: " << stud_nm << endl;
	cout << "ID: " << s_id << endl;
	cout << "Fees Paid: " << fees << endl;
	cout << "Fees total: " << totfees << endl;
	int bal= totfees-fees;
	if(bal==0)
	cout << "Full fees is paid" << endl;
	else
	cout << "Balance to be paid: " << bal << endl;
	}
};
int main()
{
details o;
cout << "Enter the student name" << endl;
string nm;
cin >> nm;
cout << "Enter the student id" << endl;
int id;
cin >> id;
if(id <=0)
{
cout << "Invalid Input -> id cant be 0 or <0" <<endl;
exit(0);
}
int tot=90000,paid;
cout << "Enter the fees paid: " << endl;
cin >> paid;
if(paid <0 || paid >tot)
{
cout << "Invalid Input -> fees paid cant be less than 0 and greater than total fees to be paid" << endl;
exit(0);
}
o.studentdeat(id,nm,paid);
}
