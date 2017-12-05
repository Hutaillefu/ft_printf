/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 16:12:50 by htaillef     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 16:12:53 by htaillef    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <wchar.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    // s
    printf("%%s : %s\n", "Simple string");

    // S
    wchar_t S[] = L"Simple string";
    printf("%%S : %S\n", S);

    // p
    printf("%%p : %p\n", (void *)2);

    // d
    printf("%%d : %d\n", 23);

    // D
    printf("%%D : %D\n", 23);

    // i
    printf("%%i : %i\n", 23);

    // o
    printf("%%o : %o\n", 23);

    // O
    printf("%%O : %O\n", 23);

    // u
    printf("%%u : %u\n", 23);

    // U
    printf("%%U : %U\n", 23);

    // x
    printf("%%x : %x\n", 23);

    // X
    printf("%%X : %X\n", 23);

    // c
    printf("%%c : %c\n", 67);

    // C
    printf("%%C : %C\n", 67);
    return (0);
}
