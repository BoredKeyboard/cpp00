#include <iostream>
using namespace std;

class Contact
{
	private:
		/* data */
	public:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_nbr;
		string	secret;
	~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}
