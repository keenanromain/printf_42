/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 17:36:09 by kromain           #+#    #+#             */
/*   Updated: 2017/08/06 21:52:18 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	char *p = "Hello";

	//ft_printf("{%05s}\n", "abc");
	//ft_printf("{% C}\n", 0);
	//printf("{% C}\n", 0);
	//ft_printf("%s %s\n", p,"PANDA");	
	//ft_printf("%c, %c, %c\n", 64, 70, 85);
	//printf("Field for chars [%10c]\n", 89);
	//ft_printf("%%\tHey THere\n");
	//printf("%%\tHey TH3re\n");
	//printf("STD_C: Hello%%  \n");
	//ft_printf("MINE_: Hello%%  \n");
	//ft_printf("% +d", 0);
	//printf("% +d", 0);
	/* --------Characters-----------------------*/
	
	 ft_printf("MINE_: no flag char[A] = [%c]\n", 'A');	
	 printf("STD_C: no flag char[A] = [%c]\n", 'A');
	// ft_printf("MINE_: width=3 char[A] = [%3c]\n", 'A');
	// printf("STD_C: width=3 char[A] = [%3c]\n", 'A');
	// ft_printf("MINE_: smlwt=1 char[A] = [%1c]\n", 'A');
	// printf("STD_C: smlwt=1 char[A] = [%1c]\n", 'A');
	// ft_printf("MINE_: lrg=wtd char[A] = [%10c]\n", 'A');
	// printf("STD_C: lrg=wtd char[A] = [%10c]\n", 'A');
	// ft_printf("MINE_: left al char[A] = [%-c]\n", 'A');	
	// printf("STD_C: left al char[A] = [%-c]\n", 'A');
	// ft_printf("MINE_: wdt=10l char[A] = [%-10c]\n", 'A');	
	// printf("STD_C: wdt=10l char[A] = [%-10c]\n", 'A');	
	
		// --Wide Chars
	
	// ft_printf("MINE_: no flag char[A] = [%c]\n", 'A');	
	//setlocale(LC_CTYPE, "");
	//ft_printf("MINE_: no flag char[A] = [%C%C]\n", '4', '2');
	//ft_printf("MINE_: no flag char[A] = [%lc]\n", 49826);
	//ft_printf("MINE_: no flag char[A] = [%lc]\n", L'ˆ');
	//printf("STD_C: no flag char[A] = [%lc]\n", L'ˆ');
	//printf("STD_C: width=3 char[A] = [%lc]\n", L'∏');
	/* --------Strings-----------------------*/
	//ft_printf("Mine_{%C}", 0);
	//printf("%.5p", 0);
	//ft_printf("%");
	//printf("%");
	/*
	ft_printf("MINE_: no flag string[Hello] = [%s]\n", p);	
	printf("STD_C: no flag string[Hello] = [%s]\n", p);
	ft_printf("MINE_: pre flg string[Hello] = [%.s]\n", p);	
	printf("STD_C: pre flg string[Hello] = [%.s]\n", p);	
	ft_printf("MINE_: pre3flg string[hello] = [%.3s]\n", p);
	printf("STD_C: pre3flg string[hello] = [%.3s]\n", p);
	ft_printf("MINE_: fld wdt string[hello] = [%3s]\n", p);
	printf("STD_C: fld wdt string[hello] = [%3s]\n", p);
	ft_printf("MINE_: lrg=wtd string[hello] = [%10s]\n", p);
	printf("STD_C: lrg=wtd string[hello] = [%10s]\n", p);
	ft_printf("MINE_: w&pre f string[Hello] = [%10.3s]\n", p);	
	printf("STD_C: w&pre f string[Hello] = [%10.3s]\n", p);
	ft_printf("MINE_: w&pre-l string[Hello] = [%-10.4s]\n", p);	
	printf("STD_C: w&pre-l string[Hello] = [%-10.4s]\n", p);
	*/
	/* --------Numbers -----------------------*/
	//ft_printf("{%+03d}\n", 0);
	//printf("{%+03d}\n", 0);
	// signed char u = 'U';
	// short s1 = -32000;
	// long l1 = 90000000;
	// long long ll1 = -9223372036854775807;
	// intmax_t it =  2147483647;
	// size_t t1 = -99;
	// ft_printf("MINE_: Number[107] = [%hhi]\n", u);
	// printf("STD_C: Number[107] = [%hhi]\n", u);
	// ft_printf("MINE_: Number[107] = [%hi]\n", s1);
	// printf("STD_C: Number[107] = [%hi]\n", s1);
	// ft_printf("MINE_: Number[107] = [%ld]\n", l1);
	// printf("STD_C: Number[107] = [%ld]\n", l1);
	// ft_printf("MINE_: Number[107] = [%lli]\n", ll1);
	// printf("STD_C: Number[107] = [%lli]\n", ll1);
	// ft_printf("MINE_: Number[107] = [%zi]\n", t1);
	// printf("STD_C: Number[107] = [%zi]\n", t1);
	// ft_printf("MINE_: Number[107] = [%ji]\n", it);
	// printf("STD_C: Number[107] = [%ji]\n", it);
	// ft_printf("MINE_: Number[107] = [%10.5i]\n", 107);
	// printf("STD_C: Number[107] = [%10.5i]\n", 107);
	// ft_printf("MINE_: Number[107] = [%+10i]\n", -107);
	// printf("STD_C: Number[107] = [%+10i]\n", -107);
	// ft_printf("MINE_: Number[107] = [%+-10i]\n", 107);
	// printf("STD_C: Number[107] = [%+-10i]\n", 107);
	// ft_printf("MINE_: Number[107] = [%+010i]\n", 107);
	// printf("STD_C: Number[107] = [%+010i]\n", 107);
	// ft_printf("MINE_: Number[107] = [% .0i]\n", 107);	
	// printf("STD_C: Number[107] = [% .0i]\n", 107);	
	// ft_printf("MINE_: Number[.0] = [% .0i]\n", 0);	
	// printf("STD_C: Number[.0] = [% .0i]\n", 0);	
	
	/* --------Unsigned Numbers ------------------ */
		// U flag
	
	// unsigned char uc = 'A';
	// unsigned short int usi = 65000;
	// unsigned int usint = 4294967295;
	// unsigned long int uli = 4294967295;
	// unsigned long long ulli = 18446744073709551614U;
	// uintmax_t uit1 = 4294967295;
	// size_t  st2 = 4294967295;
	// ft_printf("MINE_: Number[107] = [%hhu]\n", uc);
	// printf("STD_C: Number[107] = [%hhu]\n", uc);
	// ft_printf("MINE_: Number[107] = [%hu]\n", usi);
	// printf("STD_C: Number[107] = [%hu]\n", usi);
	// ft_printf("MINE_: Number[107] = [%lu]\n", uli);
	// printf("STD_C: Number[107] = [%lu]\n", uli);
	// ft_printf("MINE_: Number[107] = [%ju]\n", uit1);
	// printf("STD_C: Number[107] = [%ju]\n", uit1);
	// ft_printf("MINE_: Number[107] = [%zu]\n", st2);
	// printf("STD_C: Number[107] = [%zu]\n", st2);		
	// ft_printf("MINE_: Number[107] = [%llu]\n", ulli);
	// printf("STD_C: Number[107] = [%llu]\n", ulli);
	// ft_printf("MINE_: Number[107] = [%#llx]\n", ulli);
	// printf("STD_C: Number[107] = [%#llx]\n", ulli);
	// ft_printf("MINE_: Number[107] = [%#x]\n", 42);
	// printf("STD_C: Number[107] = [%#x]\n", 42);	
	// ft_printf("MINE_: Number[107] = [%#X]\n", usint);
	// printf("STD_C: Number[107] = [%#X]\n", usint);
	// ft_printf("MINE_: Number[107] = [%O]\n", 42);
	// printf("STD_C: Number[107] = [%O]\n", 42);	
	// ft_printf("MINE_: Number[107] = [%#O]\n", 42);
	// printf("STD_C: Number[107] = [%#O]\n", 42);
	// ft_printf("MINE_: Number[107] = [%u]\n", 107);
	// printf("STD_C: Number[107] = [%u]\n", 107);
	// ft_printf("MINE_: Number[107] = [%10u]\n", 107);
	// printf("STD_C: Number[107] = [%10u]\n", 107);
	// ft_printf("MINE_: Number[107] = [%10u]\n", -20);
	// printf("STD_C: Number[107] = [%10u]\n", -20);
	// ft_printf("MINE_: Number[107] = [%-10u]\n", 107);
	// printf("STD_C: Number[107] = [%-10u]\n", 107);
	// ft_printf("MINE_: Number[107] = [%010u]\n", 107);
	// printf("STD_C: Number[107] = [%010u]\n", 107);
	// ft_printf("MINE_: Number[107] = [%.0u]\n", 107);	
	// printf("STD_C: Number[107] = [%.0u]\n", 107);	
	// ft_printf("MINE_: Number[.0] = [%.0u]\n", 0);	
	// printf("STD_C: Number[.0] = [%.0u]\n", 0);
		
		// O flag
	/*
	ft_printf("MINE_: Number[107] = [%o]\n", 107);
	printf("STD_C: Number[107] = [%o]\n", 107);
	ft_printf("MINE_: Number[107] = [%10o]\n", 107);
	printf("STD_C: Number[107] = [%10o]\n", 107);
	ft_printf("MINE_: Number[107] = [%#10o]\n", 107);
	printf("STD_C: Number[107] = [%#10o]\n", 107);
	ft_printf("MINE_: Number[107] = [%10o]\n", -1);
	printf("STD_C: Number[107] = [%10o]\n", -1);
	ft_printf("MINE_: Number[107] = [%-10o]\n", 107);
	printf("STD_C: Number[107] = [%-10o]\n", 107);
	ft_printf("MINE_: Number[107] = [%010o]\n", 107);
	printf("STD_C: Number[107] = [%010o]\n", 107);
	ft_printf("MINE_: Number[107] = [%#0.0o]\n", 107);	
	printf("STD_C: Number[107] = [%#0.0o]\n", 107);	
	ft_printf("MINE_: Number[.0] = [%.0o]\n", 0);	
	printf("STD_C: Number[.0] = [%.0o]\n", 0);	
	ft_printf("MINE_: Number[.0] = [%#.0o]\n", 0);	
	printf("STD_C: Number[.0] = [%#.0o]\n", 0);	
	*/
		// X flag
	/*
	ft_printf("MINE_: Number[107] = [%x]\n", 107);
	printf("STD_C: Number[107] = [%x]\n", 107);
	ft_printf("MINE_: Number[107] = [%10x]\n", 107);
	printf("STD_C: Number[107] = [%10x]\n", 107);
	ft_printf("MINE_: Number[107] = [%#10x]\n", 107);
	printf("STD_C: Number[107] = [%#10x]\n", 107);
	ft_printf("MINE_: Number[107] = [%10x]\n", -20);
	printf("STD_C: Number[107] = [%10x]\n", -20);
	ft_printf("MINE_: Number[107] = [%-10x]\n", 107);
	printf("STD_C: Number[107] = [%-10x]\n", 107);
	ft_printf("MINE_: Number[107] = [%#010x]\n", 107);
	printf("STD_C: Number[107] = [%#010x]\n", 107);
	ft_printf("MINE_: Number[107] = [%#0.0x]\n", 107);	
	printf("STD_C: Number[107] = [%#0.0x]\n", 107);	
	ft_printf("MINE_: Number[.0] = [%.0x]\n", 0);	
	printf("STD_C: Number[.0] = [%.0x]\n", 0);	
	ft_printf("MINE_: Number[.0] = [%#.0x]\n", 0);	
	printf("STD_C: Number[.0] = [%#.0x]\n", 0);	
	*/
	/* ---------Pointers -----------------------------*/
	//ft_printf("M_P %p\n", 0);
	//printf("C's %p\n", 0);
	/*
	ft_printf("MINE_: Number[107] = [%p]\n", &p);
	printf("STD_C: Number[107] = [%p]\n", &p);
	ft_printf("MINE_: Number[107] = [%10p]\n", &p);
	printf("STD_C: Number[107] = [%10p]\n", &p);
	ft_printf("MINE_: Number[107] = [%-10p]\n", &p);
	printf("STD_C: Number[107] = [%-10p]\n", &p);
	ft_printf("MINE_: Number[107] = [%20p]\n", &p);
	printf("STD_C: Number[107] = [%20p]\n", &p);
	ft_printf("MINE_: Number[107] = [%-20p]\n", &p);
	printf("STD_C: Number[107] = [%-20p]\n", &p);
		*/
	/* ----------Extra Flags -------------------------*/
	/*
	short snum = -50;
	ft_printf("MINE_: Number[107] = [%hi]\n", snum);
	printf("STD_C: Number[107] = [%hi]\n", snum);
	//ft_printf("MINE_: Number[107] = [%10li]\n", 10079999999);
	printf("STD_C: Number[107] = [%10li]\n", 10079999999);
	//ft_printf("MINE_: Number[107] = [%-10li]\n", 10079999999);
	printf("STD_C: Number[107] = [%-10li]\n", 10079999999);
	//ft_printf("MINE_: Number[107] = [%20li]\n", 10079999999);
	printf("STD_C: Number[107] = [%20li]\n", 10079999999);
	//ft_printf("MINE_: Number[107] = [%-20li]\n", 10079999999);
	printf("STD_C: Number[107] = [%-20li]\n", 10079999999);
	*/
	return (0);
}
