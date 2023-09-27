#include "JsonParser.hpp"

static bool			_isPrimitive(std::string const& str);
static std::string	_getStringByDelimeter
(std::string const& text, std::string::iterator& start,
 std::string::iterator &end, char delim);

JsonParser::JsonParser(void) : _json(0) {}

JsonParser::~JsonParser(void) {}

Json*	JsonParser::getJson(void)
{
	return this->_json;
}

Json	JsonParser::getEmptyJson(void)
{
	Json	json;

	json.str = "";
	json.ptr = 0;
	return json;
}

void	JsonParser::freeJson(Json& json)
{
	(void)json;
	// need to implement
}

void	JsonParser::readFile
(std::string const& filepath, std::string& output)
{
	std::ifstream	file(filepath.c_str());
	std::string		line;

	while (std::getline(file, line))
	{
		output.append(line);
	}
}

Json	JsonParser::parseValue
(std::string const& text, std::string::iterator& start,
 std::string::iterator& end)
{
	Json		json = getEmptyJson();
	std::string	value;

	if (start == end)
	{
		// throw error
		std::cerr << "Error: Empty Value" << std::endl;
		std::exit(1);
	}
	if (*start == '"')
	{
		value = _getStringBydelimeter(text, start, end, '"');
		json.str = value;
	}
	else if (*start == '[')
	{
		// 1. ,로 스플릿
		// 2. 좌우 트림
		// 3. 요소 검사 (원시값, 문자열, 에러)
		value = _getStringByDelimeter(text, start, end, ']');
	}
	else
	{
		value = text.substr(start - text.begin(), end - start);
		if (_isPrimitive(value))
			json.str = value;
		else
		{
			// throw error
			std::cerr << "Error: Wrong Value" << std::endl;
			std::exit(1);
		}
	}
	return json;
};

static std::string	_getStringByDelimeter
(std::string const& text, std::string::iterator& start,
 std::string::iterator &end, char delim)
{
	std::string	retstr;

	++start;
	while (start != end - 1)
	{
		retstr += *start;
		++start;
	}
	if (*start != delim)
	{
		//throw error
		std::cerr << "Error: Mismatched Value Delimeter" << std::endl;
		std::exit(1);
	}
	++start;
	return retstr;
}

static bool	_isPrimitive(std::string const& str)
{
	char*	endptr;

	static_cast<void>(strtol(str.c_str(), &endptr, 10));
	if (endptr == NULL)
		return true;
	static_cast<void>(strtod(str.c_str(), &endptr));
	if (endptr == NULL)
		return true;
	if (str == "true" || str == "false")
		return true;
	return false;
}
