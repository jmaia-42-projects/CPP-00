/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:38:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/09 14:11:29 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->currentContact = 0;
}

void	PhoneBook::add(Contact &contact)
{
	this->contacts[this->currentContact++] = contact;
}
