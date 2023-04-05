 #include "main.h"

 /**
  * print_chr - print a char
  * @args: A list of variadic arguments
  * @buffer: the buffer to write the number to.
  * @buffer_index: A pointer to an index in the buffer to write to.
  * @Return: the length of the charcter
  */

 int print_chr(va_list args, char *buffer, int *buffer_index)
{
	_write(va_arg(args, int), buffer, buffer_index);
	return (1);
}

 int print_str(va_list args, char *buffer, int *buffer_index)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_write(arg[i], buffer, buffer_index);
			i++;
		}

		return (i);
	}

	_write('(', buffer, buffer_index);
	_write('n', buffer, buffer_index);
	_write('u', buffer, buffer_index);
	_write('l', buffer, buffer_index);
	_write('l', buffer, buffer_index);
	_write(')', buffer, buffer_index);
	return (6);
}

 int print_int(va_list args, char *buffer, int *buffer_index)
{
	int i = 0;
	int num = va_arg(args, int);
	unsigned int ans, divisor = 1;

	if (num < 0)
	{
		_write('-', buffer, buffer_index);
		ans = -num;
		i = 1;
	}
	else
		ans = num;

	while (ans / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		_write('0' + ans / divisor, buffer, buffer_index);
		ans %= divisor;
		divisor /= 10;
		i++;
	}

	return (i);

}


