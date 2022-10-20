#include "main.h"
#include <stdarg.h>

/**
  * _printf - prints a buffer
  * @format: the character string
  * @...: the variadic parameters
  * Return: the length of the character string
  */

int _printf(const char *format, ...)
{
	int char_count;
	size_t format_len = strlen(format);
	size_t i;
	size_t j;
	char *arg_string;
	char arg_char;
	va_list pointer;

	va_start(pointer, format);
	for (i = 0; i < format_len; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')
			{
				i++;
				arg_string = va_arg(pointer, char *);
				for (j = 0; j < strlen(arg_string); j++)
				{
					_putchar(arg_string[j]);
					char_count++;
				}
			}
			else if (format[i + 1] == 'c')
			{
				i++;
				arg_char = va_arg(pointer, int);
				_putchar(arg_char);
				char_count++;
			}
		}
		else
		{
			_putchar(format[i]);
			char_count++;
		}
	}
	va_end(pointer);
	return (char_count);
}

/**
  * _putchar - prints a character
  * @c: the character
  * Return: an int
  */
int _putchar(char c)
{
		return (write(1, &c, 1));
}
