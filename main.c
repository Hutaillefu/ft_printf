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

  int chars = ft_printf("sdfghj%d%hi %%%s %x %o\n", 5, 6, "Hello", 15154, 500);
  printf("%d chars printed\n", chars);
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

  return (0);
}
