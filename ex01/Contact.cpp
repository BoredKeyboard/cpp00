/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 14:50:59 by mforstho      #+#    #+#                 */
/*   Updated: 2023/01/23 15:16:48 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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

std::string const &Contact::get_first_name(void) {
	return (this->first_name);
}

std::string const &Contact::get_last_name(void) {
	return (this->last_name);
}
std::string const &Contact::get_nickname(void) {
	return (this->nickname);
}
std::string const &Contact::get_phone_nbr(void) {
	return (this->phone_nbr);
}
std::string const &Contact::get_secret(void) {
	return (this->secret);
}
