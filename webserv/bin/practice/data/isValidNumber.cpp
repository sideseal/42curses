#include <iostream>

bool	isValidPrimitive(std::string str)
{
	std::size_t	i = 0;
	std::size_t	j = str.length() - 1;
	bool		flagSign = false;
	bool		flagFloat = false;

	while (i < str.length() && str[i] == ' ')
		i++;
	while (j >= 0 && str[j] == ' ')
		j--;
	
	if (i > j)
		return false;

	if (i == j && !std::isdigit(str[i]))
		return false;

	if (str[i] != '.' && str[i] != '+'
		&& str[i] != '-' && !std::isdigit(str[i]))
		return false;

	for ( ; i <= j; i++)
	{
		if (str[i] != 'e' && str[i] != 'E'
			&& str[i] != '+' && str[i] != '-'
			&& str[i] != '.' && !std::isdigit(str[i]))
		{
		    std::cout << "First" << std::endl;
			return false;
		}

		if (str[i] == '-' || str[i] == '+')
		{
			if (flagSign == true)
			{
			    std::cout << "Second" << std::endl;
				return false;
			}

			flagSign = true;

			if (i + 1 > str.length())
			{
			    std::cout << "Third" << std::endl;
				return false;
			}

			if (flagFloat == false)
			{
				if (i > 0 && std::isdigit(str[i - 1]))
				{
				    std::cout << "Forth" << std::endl;
					return false;
			    }
			}
			else
			{
				if (!std::isdigit(str[i + 1]))
				{
				    std::cout << "Fifth" << std::endl;
					return false;
				}
			}
		}
		else if (str[i] == '.')
		{
			if (flagFloat == true)
			{
			    std::cout << "Sixth" << std::endl;
				return false;
			}

			if (i + 1 > str.length())
			{
			    std::cout << "Seventh" << std::endl;
				return false;
			}

			if (!std::isdigit(str[i + 1]))
			{
			    std::cout << "Eighth" << std::endl;
				return false;
			}
		}
		else if (str[i] == 'e' || str[i] == 'E')
		{
			flagFloat = true;

			if (!std::isdigit(str[i - 1]))
			{
			    std::cout << "Nineth" << std::endl;
				return false;
			}

			if (i + 1 > str.length())
			{
			    std::cout << "Tenth" << std::endl;
				return false;
			}

			if (str[i + 1] != '+' && str[i + 1] != '-'
				&& !std::isdigit(str[i + 1]))
			{
			    std::cout << "Eleventh" << std::endl;
				return false;
			}
		}
	}

	return true;
}

int main()
{
    std::string a1 = "1e4";
    std::string a2 = "2.5e12";
    std::string a3 = "3.4e+4";
    std::string a4 = "4.56e-8";
    std::string a5 = "5.67E+10";
    std::string a6 = "6.78E-5";
    std::string a[] = {a1, a2, a3, a4, a5, a6};

    for (int i = 0; i < 6; i++)
        std::cout << isValidPrimitive(a[i]) << std::endl;
        
    std::string b1 = "14e";
    std::string b2 = "2.5ee12";
    std::string b3 = "34e+.4";
    std::string b4 = "456.e-8";
    std::string b5 = "5.67+E10";
    std::string b6 = "-1e";
    std::string b[] = {b1, b2, b3, b4, b5, b6};
    
    for (int i = 0; i < 6; i++)
        std::cout << isValidPrimitive(b[i]) << std::endl;
    return 0;
}
