char	*find_line(char number3, int index, char number2)
{
	if (index == 0)
		//find single number string
	if (index == 1)
		//find from 10 to 19 strings
	if (index == 2)
		//find from 20 to 90 strings
	else
		//find other strings
}

void	print(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(1, string[i], 1);
		i++;
	}
}

void	doubles(char number2, char number3)
{
	if (number2 == '0')
		if(number3 != '0')
			print(find_line(number3, 0, 0));
	if (number2 == '1')
		print(find_line(number3, 1, number2));
	else 
	{
		print(find_line(number2, 2, '0'));
		print(find_line(number3, 0, 0));
	}
}

void	hundreds(char number1, char number2, char number3, int index)
{
	if (number1 == '0')
		doubles(number2, number3);
	else
	{
		print(find_line(number1, 0, 0));
		print(find_line(number1, index + 1, 0));
		doubles(number2, number3);
	}
}