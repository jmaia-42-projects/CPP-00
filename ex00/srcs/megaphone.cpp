/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:17:47 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/09 12:31:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

static void	printUpperCasedMessage(int ac, char **av);
static void	printUpperCasedStr(char *str);
void		toUpper(char *str);

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		printUpperCasedMessage(ac, av);
}

void	printUpperCasedMessage(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		printUpperCasedStr(av[i]);
	std::cout << std::endl;
}

void	printUpperCasedStr(char *str)
{
	toUpper(str);
	std::cout << str;
}

void	toUpper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
}
