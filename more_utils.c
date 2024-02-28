#include "shell.h"

/**
 * _puts - prints a string followed by a new line to stdout
 * @s: The string to print
 */
void _puts(const char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	_putchar('\n');
}

/**
 * _strlen - returns the length of a string
 * @s: The string to measure
 *
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Difference between the two strings.
 */
int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 && (*s1 == *s2); ++s1, ++s2)
		;

	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/**
 * _strncmp - Compares at most the first n bytes of two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes to compare.
 *
 * Return: Difference between the two strings up to n bytes.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (; n && *s1 && (*s1 == *s2); ++s1, ++s2, --n)
		;

	return (n ? (unsigned char)(*s1) - (unsigned char)(*s2) : 0);
}
