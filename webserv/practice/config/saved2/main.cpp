#include "JsonParser.hpp"

void	printJsonArray(std::vector<JsonData> const& jsonArray, int depth);
void	printJson(JsonData const& jsonData, int depth);

void	check_leaks(void)
{
	system("leaks a.out");
}

std::string	convertType(jsonType type)
{
	switch (type)
	{
		case TYPE_INTEGER:
			return "TYPE_INTEGER";
		case TYPE_FLOAT:
			return "TYPE_FLOAT";
		case TYPE_STRING:
			return "TYPE_STRING";
		case TYPE_BOOLEAN:
			return "TYPE_BOOLEAN";
		case TYPE_ARRAY:
			return "TYPE_ARRAY";
		case TYPE_OBJECT:
			return "TYPE_OBJECT";
		case TYPE_NULL:
			return "TYPE_NULL";
		default:
			return "TYPE_ERROR";
	}
}

void	printJsonArray(std::vector<JsonData> const& jsonArray, int depth)
{
	std::cout << "[" << std::endl;

	for (int i = 0; i < jsonArray.size(); ++i)
	{
		for (int j = 0; j < depth + 1; ++j)
			std::cout << "\t";

		if (!jsonArray[i]._obj.empty())
		{
			std::cout << "{" << std::endl;
			printJson(jsonArray[i], depth + 1);
			for (int j = 0; j < depth + 1; ++j)
				std::cout << "\t";
			std::cout << "}" << " (" << convertType(jsonArray[i]._type) << ")";
		}
		else if (!jsonArray[i]._arr.empty())
		{
			printJsonArray(jsonArray[i]._arr, depth + 1);
			std::cout << " (" << convertType(jsonArray[i]._type) << ")";
		}
		else
		{
			std::cout << jsonArray[i]._str << " (" << convertType(jsonArray[i]._type) << ")";
		}

		if (i < jsonArray.size() - 1)
			std::cout << ",";
		std::cout << std::endl;
	}

	for (int i = 0; i < depth; ++i)
		std::cout << "\t";

	std::cout << "]";
}

void	printJson(JsonData const& jsonData, int depth = 0)
{
	std::vector< std::pair<std::string, JsonData> > const& jsonObject
		= jsonData._obj;

	for (size_t i = 0; i < jsonObject.size(); ++i)
	{
		for (int j = 0; j < depth; ++j)
			std::cout << "\t";

		std::cout << jsonObject[i].first << ": ";

		if (!jsonObject[i].second._obj.empty())
		{
			std::cout << "{" << std::endl;
			printJson(jsonObject[i].second, depth + 1);
			for (int j = 0; j < depth; ++j)
				std::cout << "\t";
			std::cout << "}" << " (" << convertType(jsonObject[i].second._type) << ")";
		}
		else if (!jsonObject[i].second._arr.empty())
		{
			printJsonArray(jsonObject[i].second._arr, depth);
			std::cout << " (" << convertType(jsonObject[i].second._type) << ")";
		}
		else
		{
			std::cout << jsonObject[i].second._str << " (" << convertType(jsonObject[i].second._type) << ")";
		}
		std::cout << std::endl;
	}
}

int	main(int argc, char *argv[])
{
	JsonParser	jsonParser;
	JsonData	json;
	std::string	text;

//	atexit(check_leaks);
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
	std::cout << "====== result =====" << std::endl;
	printJson(json);
	return 0;
}
