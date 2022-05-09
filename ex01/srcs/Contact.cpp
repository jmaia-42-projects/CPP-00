/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:30 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/09 13:59:49 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}
Contact::Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string phoneNumber,
		std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}
std::string	Contact::getFirstName()
{
	return (this->firstName);
}
std::string	Contact::getLastName()
{
	return (this->lastName);
}
std::string	Contact::getNickname()
{
	return (this->nickname);
}
std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}
std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}
