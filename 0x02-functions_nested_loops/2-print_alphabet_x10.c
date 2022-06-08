#include "main.h"

/**
 * print_alphabet_x10 - function
 *
 * Description: Long
 *
 * Return: Always return 0
 */

void print_alphabet_x10(void)
{
	int count = 1;
	char c;

	while (count <= 10)
	{
		for (c = "a", c <= "z", c++)
		{
			_putchar(c);
		}
		count++;
		_putchar("\n");
	}
	return (0);
}
