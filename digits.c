char	*find_line(char number1, int index, char number2)
{
	char	key[65];

	if (index == 0)
			return(fill(number1, '\0', -1, key));
	else if (index == 1)
		return(fill(number2, number1, 0, key));
	else if (index == 2)
		return(fill(number1, number2, 0, key));
	else
	{
		return(fill(number1, '0', (index / 3), key));
	}
}

char	*fill(char number1, char number2, int index, char *key)
{
	int	i;

	i = 2;
	while (index > 0)
	{
		key[i] = '0';
		index--;
		i++;
	}
	key[0] = number1;
	key[1] = number2;
	key[i] = '\0';

	return (extract(key));
}

void	print(char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		write(1, &word[i], 1);
		i++;
	}
}

void	doubles(char number2, char number3)
{
	if (number2 == '0')
		if(number3 != '0')
			print(find_line(number3, 0, 0));
	else if (number2 == '1')
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
