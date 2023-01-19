#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact
{
	private:
		/* data */
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nbr;
		std::string	secret;
		void	init_info();
};

int	check_empty(std::string str)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (isspace(str[i]) == 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	get_info(std::string msg, std::string& field)
{
	std::string	info;

	while (true) {
		std::cout << msg;
		std::getline(std::cin, info);
		if (info != "" && check_empty(info) != 0) {
			field = info;
			return ;
		}
	}
}

void Contact::init_info(void)
{
	get_info("Enter first name        : ", this->first_name);
	get_info("Enter last name         : ", this->last_name);
	get_info("Enter nickname          : ", this->nickname);
	get_info("Enter phone number      : ", this->phone_nbr);
	get_info("Tell your darkest secret: ", this->secret);
}

class Phonebook
{
	public:
		Phonebook();
		Contact contacts[8];
		bool	run_phonebook(std::string input);

	private:
		void	_add_contact();
		void	_search_contact();
		int 	_i;
		int		_entry;
		int		_added;
};

Phonebook::Phonebook(void)
{
	this->_i = 0;
	this->_entry = -1;
	this->_added = 0;
}

std::string	truncate(std::string str, int width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void Phonebook::_add_contact(void)
{
	this->contacts[this->_i].init_info();
	this->_i++;
	if (this->_added != 8)
		this->_added++;
	if (this->_i == 8)
		this->_i = 0;
}

void Phonebook::_search_contact(void)
{
	std::string	input;

	if (this->_added == 0)
		std::cout << "Phonebook empty. Please add contacts" << std::endl;
	else {
		std::cout << " __________ __________ __________ __________ " << std::endl;
		std::cout << "|     index|first name| last name| nick name|" << std::endl;
		for (int j = 0; j < this->_added; j++) {
			std::cout << "|" << std::right << std::setw(10) << truncate(std::to_string(j), 10);
			std::cout << "|" << std::right << std::setw(10) << truncate(this->contacts[j].first_name, 10);
			std::cout << "|" << std::right << std::setw(10) << truncate(this->contacts[j].last_name, 10);
			std::cout << "|" << std::right << std::setw(10) << truncate(this->contacts[j].nickname, 10);
			std::cout << "|" << std::endl;
		}
		std::cout << " ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ " << std::endl;
		std::cout << "Enter index of entry: ";
		std::getline(std::cin, input);
		
		std::stringstream ss(input);
		ss >> this->_entry;
		if (ss.eof() == true && this->_entry >= 0 && this->_entry < 8
			&& (this->contacts[this->_entry].first_name != "" && check_empty(this->contacts[this->_entry].first_name) != EXIT_SUCCESS)) {
			std::cout << "First name    : " << this->contacts[this->_entry].first_name << std::endl;
			std::cout << "Last name     : " << this->contacts[this->_entry].last_name << std::endl;
			std::cout << "Nickname      : " << this->contacts[this->_entry].nickname << std::endl;
			std::cout << "Phone number  : " << this->contacts[this->_entry].phone_nbr << std::endl;
			std::cout << "Darkest secret: " << this->contacts[this->_entry].secret << std::endl;
		}
		else if (ss.eof() == false)
			std::cout << "Invalid argument" << std::endl;
		else
			std::cout << "Index out of range of phonebook" << std::endl;
	}
}

bool Phonebook::run_phonebook(std::string input)
{
	if (input == "ADD")
		this->_add_contact();
	else if (input == "SEARCH")
		this->_search_contact();
	else if (input == "EXIT")
		return (true);
	return (false);
}

int	main(int argc, char ** argv)
{
	Phonebook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "Choose an option for the phonebook: ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (phonebook.run_phonebook(input) == true)
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
