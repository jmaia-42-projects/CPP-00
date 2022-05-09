/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:38:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/09 19:24:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	this->currentContact = 0;
	this->nContacts = 0;
}

void	PhoneBook::add(Contact &contact)
{
	this->contacts[this->currentContact] = contact;
	this->currentContact++;
	this->currentContact %= 8;
	if (this->nContacts < 8)
		this->nContacts++;
}

bool	PhoneBook::isEmpty(void)
{
	return (this->nContacts == 0);
}

void	PhoneBook::print(void)
{
	std::cout << "     Index|First name| Last name|  Nickname" << std::endl;
	for (int i = 0; i < this->nContacts; i++)
		printContactLine(i, this->contacts[i]);
}

void	PhoneBook::printContactLine(int index, Contact &contact)
{
	printSpaces(9);
	std::cout << index;
	std::cout << "|";
	printTruncatedField(contact.getFirstName());
	std::cout << "|";
	printTruncatedField(contact.getLastName());
	std::cout << "|";
	printTruncatedField(contact.getNickname());
	std::cout << std::endl;
}

void	PhoneBook::printTruncatedField(std::string field)
{
	size_t	len;

	len = field.length();
	if (len > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << field[i];
		std::cout << ".";
	}
	else
	{
		printSpaces(10 - len);
		std::cout << field;
	}
}

void	PhoneBook::printSpaces(int nSpaces)
{
	for (int i = 0; i < nSpaces; i++)
		std::cout << " ";
}

void	PhoneBook::printContact(int i)
{
	Contact	contact;

	contact = contacts[i];
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

int		PhoneBook::getNContacts(void)
{
	return (this->nContacts);
}
