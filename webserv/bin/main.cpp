#include "JsonParser.hpp"
#include <cstdlib>

void	leaks(void)
{
	system("leaks a.out");
}

void	printJson(JsonValue const& jsonValue, int depth = 0)
{
	for (
			std::map<std::string, JsonValue>::const_iterator it 
			= jsonValue.json->begin();
			it != jsonValue.json->end(); ++it
		)
	{
		for (int i = 0; i < depth; ++i)
			std::cout << " ";

		std::cout << it->first << ": ";

		if (it->second.json != NULL)
		{
			std::cout << "{" << std::endl;
			printJson(it->second, depth + 1);
			for (int i = 0; i < depth; ++i)
				std::cout << " ";
			std::cout << "}";
		}
		else
		{
			std::cout << it->second.str;
		}
		std::cout << std::endl;
	}
}

std::string static	json
= "{\n \"one\": 1,\n \"two\": {\n\"three\": 3, \n \"four\": { \n\"five\": 5 \n } \n }, \n \"six\": {\n\"seven\": 7\n } \n}";

int	main(int argc, char *argv[])
{
	JsonParser	jsonParser;
	JsonValue	parsed;

	atexit(leaks);
	if (argc == 2)
	{
		parsed = jsonParser.parseJson(argv[1]);
	}
	else
	{
		text_it	start = json.begin();
		parsed = jsonParser.parseJsonHelper(json, start);
	}
	printJson(parsed);
	jsonParser.freeJsonList(parsed);
	return 0;
}
