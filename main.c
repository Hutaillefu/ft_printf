/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <htaillef@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 16:12:50 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 14:07:32 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <limits.h>
#include <locale.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	setlocale(LC_ALL, "en_US.UTF-8");

	//unsigned char a = '3';

	/*int len = ft_printf("{%03c}\n", 0);
	printf("%d chars printed\n", len);
	int len1 = printf("{%03c}\n", 0);
	printf("%d chars printed\n", len1);*/

	int len2 = ft_printf("%-15c\n", 'a');
	printf("%d chars printed\n", len2);
	int len3 = printf("%-15c\n", 'a');
	printf("%d chars printed\n", len3);

  /*ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);*/


	/*ft_printf("%-15.5d\n", 123456789);
	printf("%-15.5d\n", 123456789);*/

	/*ft_printf("%0 5d\n", 42);
	printf("%0 5d\n", 42);*/

	// s c
	/*int chars = ft_printf("%c", '\0');
	printf("%d chars printed\n", chars);

	int chars1 = printf("%c", '\0');
	printf("%d chars printed\n", chars1);*/

	/*char *str = "Salut";
	int	i;
	// p
	int chars = ft_printf("%p %p\n", str, &i);
	printf("%d chars printed\n", chars);

	int chars1 = printf("%p %p\n", str, &i);
	printf("%d chars printed\n", chars1);*/

	// I
	/*int chars = ft_printf("%i %%, %li, %lli, %zi, %ji, %hi, %hhi\n", 23, 23l, 23ll, 23, 23l, (short)10, 'A');
	printf("%d chars printed\n", chars);

	int chars1 = printf("%i %%, %li, %lli, %zi, %ji, %hi, %hhi\n", 23, 23l, 23ll, 23, 23l, (short)10, 'A');
	printf("%d chars printed\n", chars1);*/

	// D
	/*int chars2 = ft_printf("%D %%, %lD, %llD, %zD, %jD, %hD, %hhD, %c\n", LONG_MAX, LONG_MIN, LLONG_MIN, 23, 23l, (short)236578, a, a);
	printf("%d chars printed\n", chars2);

	int chars3 = printf("%D %%, %lD, %llD, %zD, %jD, %hD, %hhD, %c\n", LONG_MAX, LONG_MIN, LLONG_MIN, 23, 23l, (short)236578, a, a);
	printf("%d chars printed\n", chars3);*/

	// u
	/*int chars4 = ft_printf("%u, %lu, %llu, %zu, %ju, %hu, %hhu\n", 23, 2323232323232l, 9223372036854775807ll, ULLONG_MAX, 2323232323232l, (short)236578, UCHAR_MAX + 42);
	printf("%d chars printed\n", chars4);

	int chars5 = printf("%u, %lu, %llu, %zu, %ju, %hu, %hhu\n", 23, 2323232323232l, 9223372036854775807ll, ULLONG_MAX, 2323232323232l, (short)236578, UCHAR_MAX + 42);
	printf("%d chars printed\n", chars5);*/

	//U
	/*int chars6 = ft_printf("%U, %lU, %llU, %zU, %jU, %hU, %hhU\n", 0, ULONG_MAX, ULONG_LONG_MAX, (size_t)0xffff, 2323232323232l, (short)23, USHRT_MAX);
	printf("%d chars printed\n", chars6);
	
	int chars7 = printf("%U, %lU, %llU, %zU, %jU, %hU, %hhU\n", 0, ULONG_MAX, ULONG_LONG_MAX, (size_t)0xffff, 2323232323232l, (short)23, USHRT_MAX);
	printf("%d chars printed\n", chars7);*/

	// o
	/*int chars8 = ft_printf("%o, %lo, %llo, %zo, %jo, %ho, %hho\n", 23, 2323232323232l, 9223372036854775807ll, (size_t)121212121212121212, 2323232323232l, (short)236578, UCHAR_MAX + 42);
	printf("%d chars printed\n", chars8);

	int chars9 = printf("%o, %lo, %llo, %zo, %jo, %ho, %hho\n", 23, 2323232323232l, 9223372036854775807ll, (size_t)121212121212121212, 2323232323232l, (short)236578, UCHAR_MAX + 42);
	printf("%d chars printed\n", chars9);*/

	// O
	/*int chars10 = ft_printf("%O, %lO, %llO, %zO, %jO, %hO, %hhO\n", 23, LONG_MAX, 9223372036854775807ll, (size_t)121212121212121212, 2323232323232l, (short)100000, 0);
	printf("%d chars printed\n", chars10);

	int chars11 = printf("%O, %lO, %llO, %zO, %jO, %hO, %hhO\n", 23, LONG_MAX, 9223372036854775807ll, (size_t)121212121212121212, 2323232323232l, (short)100000, 0);
	printf("%d chars printed\n", chars11);*/

	/*int chars12 = ft_printf("%x, %lx, %llx, %zx, %jx, %hx, %hhx\n", 23, 2323232323232l, 9223372036854775807ll, (size_t)121212121212121212, -4294967296, (short)100000, a);
	printf("%d chars printed\n", chars12);

	int chars13 = printf("%x, %lx, %llx, %zx, %jx, %hx, %hhx\n", 23, 2323232323232l, 9223372036854775807ll, (size_t)121212121212121212, -4294967296, (short)100000, a);
	printf("%d chars printed\n", chars13);*/

	// ft_printf("%%", 5, 6);

	// s
	//  printf("%%s : %s\n", "Simple string");

	//S
	/* wchar_t S[] = L"Simple &e éstring";
    printf("%%S : %S\n", S);

    // p
    printf("%%p : %p\n", (void *)180);

    // d
    printf("%%d : %d\n", 23);

    // D
    printf("%%D : %D\n", 23);

    // i
    printf("%%i : %i\n", 23);

    // o
    printf("%%o : %o\n", 102);

    // O
    printf("%%O : %O\n", 102);

    // u
    printf("%%u : %u\n", -23);

    // U
    printf("%%U : %U\n", 23);

    // x
    printf("%%x : %0x\n", 256);

    // X
    printf("%%X : %0X\n", 800);

    // c
    printf("%%c : %c\n", 102);

    // C
    printf("%%C : %C\n", L'é');*/

	//printf("%-5d\n", 5);
	/*printf("%05d\n", 5);
  printf("%+d\n", 5);
  printf("% d\n", 5);*/

	//printf("%zi\n", ']');

	/*ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	printf("ici %p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("ici : %jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);*/

	return (0);
}
