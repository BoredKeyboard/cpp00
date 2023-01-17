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
	// ~Contact();
};

// class PhoneBook
// {
// 	private:
// 		/* data */
// 	public:
// 		PhoneBook(/* args */);
// 	~PhoneBook();
// };

// PhoneBook::PhoneBook(/* args */)
// {
// }

// PhoneBook::~PhoneBook()
// {
// }

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

std::string	truncate(std::string str, int width)
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

int	main(int argc, char ** argv)
{
	int 		i = 0;
	std::string	input;
	std::string	info;
	Contact		contacts[8];
	int			added = 0;
	bool		is_empty = true;
	int			entry;

	while (i < 8)
	{
		input = "zero";
		std::cout << "Choose an option for the phonebook: ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (input == "ADD") {
			get_info("Enter first name	: ", contacts[i].first_name);
			get_info("Enter last name		: ", contacts[i].last_name);
			get_info("Enter nickname		: ", contacts[i].nickname);
			get_info("Enter phone number	: ", contacts[i].phone_nbr);
			get_info("Tell your darkest secret: ", contacts[i].secret);
			i++;
			if (added != 8)
				added++;
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH") {
			if (added == 0)
				std::cout << "Phonebook empty. Please add contacts" << std::endl;
			else {
				std::cout << " __________ __________ __________ __________ " << std::endl;
				for (int j = 0; j < added; j++) {
					std::cout << "|" << std::right << std::setw(10) << truncate(std::to_string(j), 10);
					std::cout << "|" << std::right << std::setw(10) << truncate(contacts[j].first_name, 10);
					std::cout << "|" << std::right << std::setw(10) << truncate(contacts[j].last_name, 10);
					std::cout << "|" << std::right << std::setw(10) << truncate(contacts[j].nickname, 10);
					std::cout << "|" << std::endl;
				}
				std::cout << " ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ " << std::endl;
				std::cout << "Enter index of entry: ";
				std::getline(std::cin, input);
				entry = std::stoi(input);
				if (entry >= 0 && entry < 8) {
					std::cout << "First name	: " << contacts[entry].first_name << std::endl;
					std::cout << "Last name	: " << contacts[entry].last_name << std::endl;
					std::cout << "Nickname	: " << contacts[entry].nickname << std::endl;
					std::cout << "Phone number	: " << contacts[entry].phone_nbr << std::endl;
					std::cout << "Darkest secret	: " << contacts[entry].secret << std::endl;
				}
			}
		}
		else if (input == "EXIT")
			exit(EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
