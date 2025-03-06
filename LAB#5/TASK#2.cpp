#include<iostream>
#include<string>
using namespace std;

class Battery 
{
	private:
		int capacity;
		
		public:
		Battery(int c): capacity(c) {}
		
		int getter_cap() const
		{
			return capacity;
		}
};
class Smartphone
{
	private:
	string name;
	Battery& battery;
	
	public:
	Smartphone(string n, Battery& b): name(n), battery(b) {} 
	
	void const show()
	{
		cout << "Name : " << name << " \nBattery : " << battery.getter_cap() << " mAH" << endl;
	}
};
int main()
{
	Battery phone_b(15000);
	Smartphone phone("Redmi Note 11 pro" ,phone_b);
	phone.show();
	
	return 0;
}
