#include "JsonParser.hpp"

int	main(int argc, char *argv[])
{
	JsonParser	jsonParser;
	JsonData	json;
	std::string	text;

	if (argc == 2)
	{
		std::string	output;
		jsonParser.readFile(argv[1], text);
	}
	else
	{
		std::cerr << "Please test with file" << std::endl;
		return 1;
	}
	std::cout << text << std::endl;
	std::string::iterator start = text.begin();

	json = jsonParser.parseObject(text, start);
	return 0;
}
