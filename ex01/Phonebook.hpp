/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Phonebook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 14:59:07 by mforstho      #+#    #+#                 */
/*   Updated: 2023/02/07 13:44:32 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		bool	run_phonebook(std::string input);

	private:
		Contact contacts[8];
		void	_add_contact();
		void	_search_contact();
		int 	_i;
		int		_entry;
		int		_added;
};

#endif
