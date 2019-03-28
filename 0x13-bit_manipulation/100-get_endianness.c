/**
 * get_endianness - get endianness of this machine
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned char byte;
	unsigned short mark = 0xFEFF;

	byte = *(unsigned char *)&mark;
	if (byte == 0xFE)
		return (0);
	else if (byte == 0xFF)
		return (1);
	return (-1);
}
