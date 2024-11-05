#include<iostream>
using namespace std;
class totmark
{
public :
   double total,per;
   int c;
   public:
void mark()
{
int n;
cout << "Enter the number of subjects =>";
cin >> n;
if(n<=0)
{
cout <<"Invalid Input --> No.Of Subjects can't be negative or 0" << endl;
exit(0);
}
total=mark(n);
per=total/n;
if(per<40 || c==1)
cout << per <<"%  Fail\n";
else if(per>40 && per<=55)
cout << per <<"%  Pass\n";
else if(per>55 && per<=75)
cout << per <<"%  Excellent\n";
else if(per>75 && per<=85)
cout << per <<"%  Outstanding\n";
else 
cout << per <<"%  Extraordinary\n";
}
double mark(double a)
{
double att;
cout << "Enter the attendance percentage =>";
cin >> att;
if(att>85 && att<=90)
a+=5;
else if(att>90 && att<=100)
a+=10;
else 
a+=0;
return a;
}
double mark(int n)
{
double lab[n],marks[n],totsub[n],tot;
string sub[n];
cout << "Enter the marks out of 80 and internals out of 10 :" <<endl;
 for(int i=0;i<n;i++)
{
cout <<"Enter the subject " <<(i+1)<< endl;
cin >> sub[i];
cout <<"Enter the marks for " << sub[i] << endl;
cin >> marks[i];
if(marks[i]<0 || marks[i]>80)
{
cout <<"Invalid Input -> Enter the marks between 0-80" <<endl;
exit(0);
}
cout <<"Enter the internal marks for " << sub[i] << endl;
cin >> lab[i];
if(lab[i]<0 || lab[i]>10)
{
cout <<"Invalid Input -> Enter the internals between 0-10" <<endl;
exit(0);
}
lab[i]=mark(lab[i]);
totsub[i]=marks[i]+lab[i];
if(totsub[i] < 40)
c=1;
}
cout << "Student Report:" <<endl;
for(int i=0;i<n;i++)
{
cout << sub[i] << ":  " << marks[i] << " + " << lab[i] << "-->" << totsub[i] <<endl;
total+=totsub[i];
}
return total;
}
};
int main()
{
totmark o;
o.mark();
}
