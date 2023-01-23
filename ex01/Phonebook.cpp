/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 14:59:31 by mforstho      #+#    #+#                 */
/*   Updated: 2023/01/23 15:22:09 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_i = 0;
	this->_entry = -1;
	this->_added = 0;
}

std::string	truncate(std::string str, size_t width)
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
			std::cout << "|" << std::right << std::setw(10) << truncate(this->contacts[j].get_first_name(), 10);
			std::cout << "|" << std::right << std::setw(10) << truncate(this->contacts[j].get_last_name(), 10);
			std::cout << "|" << std::right << std::setw(10) << truncate(this->contacts[j].get_nickname(), 10);
			std::cout << "|" << std::endl;
		}
		std::cout << " ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ ‾‾‾‾‾‾‾‾‾‾ " << std::endl;
		this->_entry = -1;
		std::cout << "Enter index of entry: ";
		std::getline(std::cin, input);
		
		std::stringstream ss(input);
		ss >> this->_entry;
		if (ss.eof() == true && this->_entry >= 0 && this->_entry < 8
			&& (this->contacts[this->_entry].get_first_name() != "" && check_empty(this->contacts[this->_entry].get_first_name()) != EXIT_SUCCESS)) {
			std::cout << "First name    : " << this->contacts[this->_entry].get_first_name() << std::endl;
			std::cout << "Last name     : " << this->contacts[this->_entry].get_last_name() << std::endl;
			std::cout << "Nickname      : " << this->contacts[this->_entry].get_nickname() << std::endl;
			std::cout << "Phone number  : " << this->contacts[this->_entry].get_phone_nbr() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[this->_entry].get_secret() << std::endl;
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

int	main(void)
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
