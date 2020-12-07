#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
template <typename T>
class Time 
{
private:
	T hour;
	T min;
	T sec;
public: Time(T hour, T min, T sec) 
{// конструктор
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}
	  bool beforeORafterMidday() 
	  {
		  if (hour < 13)
			  return true;
		  else 
			  return false;
	  }
	  void PrintInfo() 
	  {
		  if (beforeORafterMidday() == true)
			  cout << "Its the first part of the day.\n";
		  else 
			  cout << "Its the second part of the day.\n";
	  }
	  template <typename T1>
	  friend istream& operator >>  (istream& in, Time <T1>& time);
	  template <typename T1>
	  friend ostream& operator <<  (ostream& out, Time <T1>& time);
	  template <typename T1>
	  friend Time<T1>& operator +=(Time<T1>& a, Time<T1>& b);
};
template <typename T1>
istream& operator >> (istream& in, Time <T1>& time) 
{
	cout << "\nhours: ";
	in >> time.hour;
	cout << "munutes: ";
	in >> time.min;
	cout << "seconds: ";
	in >> time.sec;
	return in;
}
template <typename T1>
ostream& operator << (ostream& out, Time <T1>& time) 
{
	out << time.hour << ":" << time.min << ":" << time.sec << "\n";
	return out;
}
template <typename T1>
Time<T1>& operator +=(Time<T1>& a, Time<T1>& b) 
{
	a.sec += b.sec;
	return a;
}

int main() 
{
	Time<int> time1(1, 10, 25);
	int choice;
	Time<int>timeAdd(0, 0, 10);
	bool flag = true;
	while (flag == true) 
	{
		cout << "1-Part of the day.\n2-Change the data\n3-Add seconds\n4-Exit";
		cout << endl;
		cin >> choice;
		switch (choice) 
		{
		case 1: cout << time1 << " "; time1.PrintInfo(); break;
		case 2:cout << "Enter new time: ";
			cin >> time1;
			cout << time1;
			break;
		case 3:time1 += timeAdd; cout << time1; break;
		case 4: flag = false;
		}
	}
	system("pause");
	return 0;
}
