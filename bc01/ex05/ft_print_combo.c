/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:45:31 by abuzdin           #+#    #+#             */
/*   Updated: 2021/09/08 11:45:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
void    ft_putchar(char a, char b, char c)
{
    write(1, &a, 1);
    write(1, &b, 1);
    write(1, &c, 1);
    write(1, ", ", 2);

}

void ft_print_comb(void)
{
    char    a, b, c;

    a = '0';
    while(a <= '7')
    {
        b = a + 1;
        while(b <= '8')
        {
            c = b + 1;
            while(c <= '9')
            {
                if(a != '7')
                {
                	ft_putchar(a, b, c);
                }
                else
                {
                	write(1, &a, 1);
                	write(1, &b, 1);
                  	write(1, &c, 1);
                }
                c++;
            }
            b++;
        }
        a++;
    }
}
int     main()
{
    ft_print_comb();
    return 0;
}