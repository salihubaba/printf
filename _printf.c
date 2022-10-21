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
	int char_count = 0;
	size_t format_len = strlen(format);
	size_t i, j;
	char *arg_string;
	char arg_char;
	int arg_int;
	int int_len = 0;
	char *int_str;
	int arg_int_len;
	int k, l;
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
			else if (format[i + 1] == '%')
			{
				i++;
				_putchar(format[i]);
				char_count++;
	 		}
			else if (format[i + 1] == 'd')
			{
				i++;
				arg_int = va_arg(pointer, int);
				arg_int_len = arg_int;

				do
				{
					arg_int_len = arg_int_len / 10;
					++int_len;
				}
				while (arg_int_len != 0);
				int_str = malloc(sizeof(int_str) * int_len);
				if (int_str == NULL)
				{
					return (1);
				}
				sprintf(int_str, "%d", arg_int);
				if (int_str[0] == '-')
				{
					int_len++;
				}
				for (k = 0; k < int_len; k++)
				{
					_putchar(int_str[k]);
					char_count++;
				}
			}
			else if (format[i + 1] == 'i')
			{
				i++;
				arg_int = va_arg(pointer, int);
				arg_int_len = arg_int;
				do
				{
					arg_int_len = arg_int_len / 10;
					++int_len;
				} while (arg_int_len != 0);
				int_str = malloc(sizeof(int_str) * int_len);
				if (int_str == NULL)
				{
					return (1);
				}
				sprintf(int_str, "%i", arg_int);
				if (int_str[0] == '-')
				{
					int_len++;
				}
				for (l = 0; l < int_len; l++)
				{
					_putchar(int_str[l]);
					char_count++;
				}
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
