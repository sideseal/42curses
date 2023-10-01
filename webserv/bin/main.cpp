#include "JsonParser.hpp"

void	printJsonArray(std::vector<JsonData>& jsonArray, int depth);
void	printJson(JsonData const& jsonData, int depth);

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

void	printJsonArray(std::vector<JsonData>& jsonArray, int depth)
{
	std::cout << "[" << std::endl;

	for (int i = 0; i < jsonArray.size(); ++i)
	{
		for (int j = 0; j < depth + 1; ++j)
			std::cout << "\t";

		if (jsonArray[i]._obj != NULL)
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
	std::multimap<std::string, JsonData>::iterator it = jsonData._obj->begin();

	for (; it != jsonData._obj->end(); ++it)
	{
		for (int i = 0; i < depth; ++i)
			std::cout << "\t";

		std::cout << it->first << ": ";

		if (it->second._obj != NULL)
		{
			std::cout << "{" << std::endl;
			printJson(it->second, depth + 1);
			for (int i = 0; i < depth; ++i)
				std::cout << "\t";
			std::cout << "}" << " (" << convertType(it->second._type) << ")";
		}
		else if (!it->second._arr.empty())
		{
			printJsonArray(it->second._arr, depth);
			std::cout << " (" << convertType(it->second._type) << ")";
		}
		else
		{
			std::cout << it->second._str << " (" << convertType(it->second._type) << ")";
		}
		std::cout << std::endl;
	}
}

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
	std::cout << "====== result =====" << std::endl;
	printJson(json);
	return 0;
}
