/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 13:53:33 by mforstho      #+#    #+#                 */
/*   Updated: 2023/01/23 15:16:51 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nbr;
		std::string	secret;
	public:
		std::string	const &get_first_name();
		std::string const &get_last_name();
		std::string const &get_nickname();
		std::string const &get_phone_nbr();
		std::string const &get_secret();
		void	init_info();
};

int		check_empty(std::string str);
void	get_info(std::string msg, std::string& field);

#endif
