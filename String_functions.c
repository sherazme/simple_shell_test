#include <stdio.h>
#include "shell.h"

/**
 * _strcpy - Check characters
 * @src: A n input character
 * @dest: destenation
 * Description: function uses _putchar function to print
 * Return: length
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcat - Check characters
 * @dest: An input character
 * @src: source
 * Description: function swap words
 * Return: destination
 */
char *_strcat(char *dest, char *src)
{
	char *str = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
	return (str);
}

/**
 * _strlen - Calculate the lenght of a string.
 *
 * @str: String.
 *
 * Return: Lenght of str.
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;

	return (len);
}