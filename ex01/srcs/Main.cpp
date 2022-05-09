/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:13:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/09 19:42:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <stdlib.h>

void		addContact(PhoneBook &phoneBook);
void		askForPhoneNumber(std::string &field);
bool		getField(std::string prompt, std::string &field);
static bool	isNumber(std::string str);
bool		isValidPhoneNumber(std::string &str);
void		pbExit(void);
void		safeGetLine(std::string &line);
void		searchContact(PhoneBook &phoneBook);
void		searchContactWhenNotEmpty(PhoneBook &phoneBook);

int	main(void)
{
	PhoneBook	phoneBook;
	bool		isEnd;
	std::string	line;

	isEnd = false;
	while (!isEnd)
	{
		std::cout << "What do you want to do ? ";
		safeGetLine(line);
		if (line == "EXIT")
			pbExit();
		else if (line == "ADD")
			addContact(phoneBook);
		else if (line == "SEARCH")
			searchContact(phoneBook);
	}
}

void	safeGetLine(std::string &line)
{
	getline(std::cin, line);
	if (std::cin.eof())
		pbExit();
	if (std::cin.fail())
	{
		std::cerr << "An error occured while reading input, exiting..." << std::endl;
		exit(1);
	}
}

void	pbExit(void)
{
	std::cout << std::endl << "Good bye !" << std::endl;
	exit(0);
}

void		addContact(PhoneBook &phoneBook)
{
	Contact		contact;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	getField("First name", firstName);
	getField("Last name", lastName);
	getField("Nickname", nickname);
	askForPhoneNumber(phoneNumber);
	getField("Darkest secret", darkestSecret);
	contact = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phoneBook.add(contact);
	std::cout << "Contact added !" << std::endl;
}

bool	getField(std::string prompt, std::string &field)
{
	field = "";
	while (std::cin.good() && field == "")
	{
		std::cout << prompt << ": ";
		safeGetLine(field);
		if (field == "")
			std::cerr << "Field cannot be null !" << std::endl;
	}
	return (std::cin.good());
}

void	askForPhoneNumber(std::string &field)
{
	field = "";
	while (field == "" || !isValidPhoneNumber(field))
	{
		if (field != "")
			std::cerr << "Input must be a valid phone number !" << std::endl;
		getField("Phone number", field);
	}
}

bool	isValidPhoneNumber(std::string &str)
{
	bool	numberFound;

	numberFound = false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str[i]))
			numberFound = true;
		else if (i != 0 || str[i] != '+')
			return (false);
	}
	return (numberFound);
}

void	searchContact(PhoneBook &phoneBook)
{
	if (phoneBook.isEmpty())
		std::cout << "The phonebook is empty !" << std::endl;
	else
		searchContactWhenNotEmpty(phoneBook);
}

void	searchContactWhenNotEmpty(PhoneBook &phoneBook)
{
	int			index;
	std::string	line;

	phoneBook.print();
	std::cout << "Which contact do you want to see ? ";
	safeGetLine(line);
	if (!isNumber(line))
		std::cerr << "Input is not a valid number !" << std::endl;
	else
	{
		index = std::atoi(line.c_str());
		if (index < 0 || index >= phoneBook.getNContacts())
			std::cerr << "Index out of range !" << std::endl;
		else
			phoneBook.printContact(index);
	}
}

static bool	isNumber(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}
