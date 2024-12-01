/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadachi <kadachi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:45:14 by kadachi           #+#    #+#             */
/*   Updated: 2024/09/07 22:21:55 by kadachi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	capitalize(char *character, int *is_initial)
{
	if (*is_initial == 1)
	{
		*is_initial = 0;
		if (*character >= 'a' && *character <= 'z')
			*character -= 32;
	}
	else
	{
		if (*character >= 'A' && *character <= 'Z')
			*character += 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*p;
	int		is_initial;

	p = str;
	is_initial = 1;
	while (*p != '\0')
	{
		if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')
			|| (*p >= '0' && *p <= '9'))
		{
			capitalize(p, &is_initial);
		}
		else
			is_initial = 1;
		p++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	char s1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char s2[] = "saLut, commenT tu vAs ? 42mOts quarAnte-deux; cinqUante+et+un";
	printf("%s\n", s1);
	ft_strcapitalize(s1);
	printf("%s\n", s1);
	printf("\n");
	printf("%s\n", s2);
	ft_strcapitalize(s2);
	printf("%s\n", s2);
	return (0);
}
//*/
