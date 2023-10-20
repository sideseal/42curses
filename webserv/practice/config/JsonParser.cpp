#include "JsonParser.hpp"

static void	_errorExit(std::string const& msg);

/* *************************************************************************** *
 * Constructor & Destructor                                                    *
 * ****************************************************************************/

JsonParser::JsonParser(void) {}

JsonParser::~JsonParser(void) {}

/* *************************************************************************** *
 * Public Member Functions                                                     *
 * ****************************************************************************/

JsonData const&	JsonParser::getJson(void) const
{
	return this->_json;
}

JsonData	JsonParser::parseJson(std::string const& filepath)
{
	std::string				text;
	std::string::iterator	start;

	readFile(filepath, text);
	start = text.begin();
	this->_json = parseObject(text, start);
	return this->_json;
}

/* *************************************************************************** *
 * Private Member Functions                                                    *
 * ****************************************************************************/

void	JsonParser::readFile
(std::string const& filepath, std::string& output)
{
	std::ifstream	file(filepath.c_str());
	std::string		line;

	if (!file.is_open())
	{
		_errorExit("Error: cannot open file " + filepath);
	}

	while (std::getline(file, line, '\0'))
	{
		output.append(line);
	}
}

std::pair<std::string, JsonData>	JsonParser::retriveKeyValuePair
(std::string const& text, std::string::iterator& it)
{
	std::string	key;
	JsonData	data;

	if (it == text.end())
	{
		_errorExit("Error: Incomplete object");
	}

	while (std::isspace(*it))
		it++;

	if (*it == '\"')
	{
		key = parseStringKey(text, it);
	}
	else if (*it == '}')
	{
		return std::make_pair(key, data);
	}
	else
	{
		_errorExit("Error: Invalid object key");
	}

	while (std::isspace(*it))
		it++;

	if (*it == '{')
	{
		data = parseObject(text, it);
	}
	else if (*it == '\"')
	{
		data._type = TYPE_STRING;
		data._str = parseStringValue(text, it);
	}
	else if (*it == '[')
	{
		data._type = TYPE_ARRAY;
		data._arr = parseArray(text, it);
	}
	else if (std::isalnum(*it))
	{
		data._str = parsePrimitive(it, data._type);
	}
	else
	{
		_errorExit("Error: Invalid object value");
	}

	if (checkKeyValueEnd(text, it) == false)
	{
		_errorExit("Error: Malformed object format");
	}

	it++;
	while (*it == ',' || std::isspace(*it))
		it++;

	return std::make_pair(key, data);
}

std::vector<JsonData>	JsonParser::parseArray
(std::string const& text, std::string::iterator& it)
{
	std::vector<JsonData>	arr;
	std::string::iterator	nxt;

	it++;
	while (it != text.end())
	{
		JsonData	data;

		while (std::isspace(*it))
			it++;
		if (*it == '{')
		{
			data = parseObject(text, it);
		}
		else if (*it == '\"')
		{
			data._type = TYPE_STRING;
			data._str = parseStringValue(text, it);
		}
		else if (*it == '[')
		{
			data._type = TYPE_ARRAY;
			data._arr = parseArray(text, it);
		}
		else if (*it == ']')
		{
			break;
		}
		else if (std::isalnum(*it))
		{
			data._str = parsePrimitive(it, data._type);
		}
		else
		{
			_errorExit("Error: Invalid array element");
		}

		if (checkElementEnd(text, it) == false)
		{
			_errorExit("Error: Malformed array format");
		}

		it++;
		while (*it == ',' || std::isspace(*it))
			it++;

		arr.push_back(data);
	}

	return arr;
}

JsonData	JsonParser::parseObject
(std::string const& text, std::string::iterator& it)
{
	JsonData										jsonData;
	std::vector<std::pair< std::string, JsonData> >	jsonObject;

	while (std::isspace(*it))
		++it;

	if (*it != '{')
	{
		_errorExit("Error: Object must start with open curly bracket");
	}
	it++;

	do {
		std::pair<std::string, JsonData> keyValuePair
			= retriveKeyValuePair(text, it);

		jsonObject.push_back(keyValuePair);

		while (std::isspace(*it))
			it++;

	} while (*it != '}');

	jsonData._type = TYPE_OBJECT;
	jsonData._obj = jsonObject;

	return jsonData;
}

bool	JsonParser::checkElementEnd
(std::string const& text, std::string::iterator& it)
{
	std::string::iterator	cur;
	bool					comma = false;

	if (it == text.end())
	{
		_errorExit("Error: Incomplete array");
	}

	cur = it + 1;
	while (*cur == ',' || std::isspace(*cur))
	{
		if (*cur == ',')
		{
			if (comma == false)
			{
				comma = true;
			}
			else
			{
				_errorExit("Error: Duplicate comma");
			}
		}
		cur++;
	}

	if (*cur == '\"')
	{
		if (comma == true)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Missing comma before element");
		}
	}
	else if (*cur == '{')
	{
		if (comma == true)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Missing comma before element");
		}
	}
	else if (*cur == '[')
	{
		if (comma == true)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Missing comma before element");
		}
	}
	else if (std::isalnum(*cur))
	{
		if (comma == true)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Missing comma before element");
		}
	}
	else if (*cur == ']')
	{
		if (comma == false)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Found comma before end of array");
		}
	}

	return false;
}

bool	JsonParser::checkKeyValueEnd
(std::string const& text, std::string::iterator& it)
{
	std::string::iterator	cur;
	bool					comma = false;

	if (it == text.end())
	{
		_errorExit("Error: Incomplete object");
	}

	cur = it + 1;
	while (*cur == ',' || std::isspace(*cur))
	{
		if (*cur == ',')
		{
			if (comma == false)
			{
				comma = true;
			}
			else
			{
				_errorExit("Error: Duplicate comma");
			}
		}
		cur++;
	}

	if (*cur == '\"')
	{
		if (comma == true)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Missing comma before key");
		}
	}
	else if (*cur == '}')
	{
		if (comma == false)
		{
			return true;
		}
		else
		{
			_errorExit("Error: Found comma before end of object");
		}
	}

	return false;
}

std::string	JsonParser::parsePrimitive
(std::string::iterator& it, jsonType& type)
{
	std::string	value;

	while (*it != ',' && *it != '}' && *it != ']' && !std::isspace(*it))
	{
		if (*it == '\"')
		{
			_errorExit("Error: Malformed primitive format");
		}
		value += *it;
		it++;
	}
	it--;

	type = getPrimitiveType(value);
	if (type == TYPE_ERROR)
	{
		_errorExit("Error: Invalid primitive");
	}

	return value;
}

std::string	JsonParser::parseStringKey
(std::string const& text, std::string::iterator& it)
{
	std::string	key;

	key = getStringData(text, it);

	it++;
	while (std::isspace(*it))
		it++;

	if (*it != ':')
	{
		_errorExit("Error: Missing colon after key");
	}
	it++;

	return key;
}

std::string	JsonParser::parseStringValue
(std::string const& text, std::string::iterator& it)
{
	return getStringData(text, it);
}

std::string	JsonParser::getStringData
(std::string const& text, std::string::iterator& it)
{
	std::string	str;
	bool		insideQuote = false;
	bool		escape = false;
	char		ch;

	while (it != text.end())
	{
		ch = *it;
		if (insideQuote)
		{
			if (ch == '\n')
			{
				_errorExit("Error: Malformed String Data type");
			}
			if (escape)
			{
				str += ch;
				escape = false;
			}
			else if (ch == '\\')
			{
				escape = true;
			}
			else if (ch == '\"')
			{
				insideQuote = false;
				break;
			}
			else
			{
				str += ch;
			}
		}
		else if (ch == '\"')
		{
			insideQuote = true;
		}
		else if (ch == '\\')
		{
			escape = true;
		}
		else
		{
			_errorExit("Error: Malformed String Data type");
		}
		it++;
	}

	if ((it == text.end()) || insideQuote)
	{
		_errorExit("Error: Malformed String Data type");
	}

	return str;
}

jsonType	JsonParser::getPrimitiveType(std::string const& str)
{
	char*	endptr;

	static_cast<void>(strtol(str.c_str(), &endptr, 10));
	if (*endptr == '\0')
		return TYPE_INTEGER;
	static_cast<void>(strtod(str.c_str(), &endptr));
	if (*endptr == '\0')
		return TYPE_FLOAT;
	if (str == "true" || str == "false")
		return TYPE_BOOLEAN;
	if (str == "null")
		return TYPE_NULL;
	return TYPE_ERROR;
}

/* *************************************************************************** *
 * Helper Functions                                                            *
 * ****************************************************************************/

static void	_errorExit(std::string const& msg)
{
	std::cerr << msg << std::endl;
	std::exit(1);
}
