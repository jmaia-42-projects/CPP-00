/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/09 19:20:14 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		currentContact;
		int		nContacts;
		void	printContactLine(int index, Contact &contact);
		void	printTruncatedField(std::string field);
		void	printSpaces(int nSpaces);
	public:
		PhoneBook();
		void	add(Contact &contact);
		bool	isEmpty(void);
		void	print(void);
		void	printContact(int i);
		int		getNContacts(void);
};

#endif
