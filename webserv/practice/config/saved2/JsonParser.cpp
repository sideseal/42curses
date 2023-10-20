#include "JsonParser.hpp"

static jsonType		_getPrimitiveType
(std::string const& str);
static std::string	_getStringData
(std::string const& text, std::string::iterator& it);
static std::string	_parseStringKey
(std::string const& text, std::string::iterator& it);
static std::string	_parseStringValue
(std::string const& text, std::string::iterator& it);
static std::string	_parsePrimitive
(std::string const& text, std::string::iterator& it, jsonType& type);
static bool	_checkLineEnd
(std::string const& text, std::string::iterator& it);
static bool	_checkElementEnd
(std::string const& text, std::string::iterator& it);

JsonParser::JsonParser(void) : _json(0) {}

JsonParser::~JsonParser(void) {}

JsonData*	JsonParser::getJson(void)
{
	return this->_json;
}

void	JsonParser::readFile
(std::string const& filepath, std::string& output)
{
	std::ifstream	file(filepath.c_str());
	std::string		line;

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

	assert(it != text.end());

	while (std::isspace(*it))
		it++;
	if (*it == '\"')
	{
		key = _parseStringKey(text, it);
	}
	else if (*it == '}')
	{
		return std::make_pair(key, data);
	}
	else
	{
		// throw error
		std::cerr << "Error: Object must have valid key" << std::endl;
		std::exit(1);
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
		data._str = _parseStringValue(text, it);
	}
	else if (*it == '[')
	{
		data._type = TYPE_ARRAY;
		data._arr = parseArray(text, it);
	}
	else if (std::isalnum(*it))
	{
		data._str = _parsePrimitive(text, it, data._type);
	}
	else
	{
		// throw error
		std::cerr << "Error: Object must have valid value" << std::endl;
		std::exit(1);
	}

	if (_checkLineEnd(text, it) == false)
	{
		// throw error
		std::cerr << "Error: Malformed line end" << std::endl;
		std::exit(1);
	}
	it++;
	//std::cout << "before it: " << *it << std::endl;
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
			data._str = _parseStringValue(text, it);
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
			data._str = _parsePrimitive(text, it, data._type);
		}
		else
		{
			// throw error
			std::cerr << "Error: Malformed Array 1" << std::endl;
			std::exit(1);
		}

		if (_checkElementEnd(text, it) == false)
		{
			// throw error
			std::cerr << "Error: Malformed line end" << std::endl;
			std::exit(1);
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

	assert(*it == '{');
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

JsonData	JsonParser::parseJson(std::string const& filepath)
{
	std::string				text;
	std::string::iterator	start;

	readFile(filepath, text);
	start = text.begin();
	return parseObject(text, start);
}

/* *************************************************************************** *
 * Helper Functions                                                            *
 * ****************************************************************************/

static bool	_checkElementEnd
(std::string const& text, std::string::iterator& it)
{
	std::string::iterator	cur;
	bool					comma = false;

	if (it == text.end())
	{
		// throw error
		std::cerr << "Error: Malformed Array format EOF" << std::endl;
		std::exit(1);
	}
	cur = it + 1;
//	std::cout << "ARR *it: " << *it << " ARR *cur: " << *cur << std::endl;
	while (*cur == ',' || std::isspace(*cur))
	{
		if (*cur == ',')
		{
			if (comma == false)
				comma = true;
			else
			{
				// throw error
				std::cerr << "Error: Duplicate comma" << std::endl;
				std::exit(1);
			}
		}
		cur++;
	}
//	std::cout << "ARR after iter cur: " << *cur << std::endl;
	if (*cur == '\"')
	{
		if (comma == true)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: No comma before key" << std::endl;
			std::exit(1);
		}
	}
	else if (*cur == '{')
	{
		if (comma == true)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: No comma before block" << std::endl;
			std::exit(1);
		}
	}
	else if (*cur == '[')
	{
		if (comma == true)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: No comma before array" << std::endl;
			std::exit(1);
		}
	}
	else if (std::isalnum(*cur))
	{
		if (comma == true)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: No comma before primitive" << std::endl;
			std::exit(1);
		}
	}
	else if (*cur == ']')
	{
		if (comma == false)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: Comma before end array" << std::endl;
			std::exit(1);
		}
	}
	return false;
}

static bool	_checkLineEnd
(std::string const& text, std::string::iterator& it)
{
	std::string::iterator	cur;
	bool					comma = false;

	if (it == text.end())
	{
		// throw error
		std::cerr << "Error: Malformed Json format EOF" << std::endl;
		std::exit(1);
	}
	cur = it + 1;
//	std::cout << "*it: " << *it << " *cur: " << *cur << std::endl;
	while (*cur == ',' || std::isspace(*cur))
	{
		if (*cur == ',')
		{
			if (comma == false)
				comma = true;
			else
			{
				// throw error
				std::cerr << "Error: Duplicate comma" << std::endl;
				std::exit(1);
			}
		}
		cur++;
	}
//	std::cout << "after iter cur: " << *cur << std::endl;
	if (*cur == '\"')
	{
		if (comma == true)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: No comma before key" << std::endl;
			std::exit(1);
		}
	}
	else if (*cur == '}')
	{
		if (comma == false)
			return true;
		else
		{
			// throw error
			std::cerr << "Error: Comma before end block" << std::endl;
			std::exit(1);
		}
	}
	return false;
}

static std::string	_parsePrimitive
(std::string const& text, std::string::iterator& it, jsonType& type)
{
	std::string	value;

	while (*it != ',' && *it != '}' && *it != ']' && !std::isspace(*it))
	{
		if (*it == '\"')
		{
			// throw error
			std::cerr << "Error: Malformed Primitive Format" << std::endl;
			std::exit(1);
		}
		value += *it;
		it++;
	}
	it--;
	type = _getPrimitiveType(value);
	if (type == TYPE_ERROR)
	{
		// throw error
		std::cerr << "Error: Malformed primitive format" << std::endl;
		std::exit(1);
	}
	return value;
}

static std::string	_parseStringKey
(std::string const& text, std::string::iterator& it)
{
	std::string	key;

	key = _getStringData(text, it);
	it++;
	while (std::isspace(*it))
		it++;
	if (*it != ':')
	{
		// throw error
		std::cerr << "Error: Colon not found after key" << std::endl;
		std::exit(1);
	}
	it++;
	return key;
}

static std::string	_parseStringValue
(std::string const& text, std::string::iterator& it)
{
	std::string				value;
	std::string::iterator	cur;

	value = _getStringData(text, it);
//	it++;
//	while (std::isspace(*it))
//		it++;
	return value;
}

static std::string	_getStringData
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
				// throw error
				std::cerr << "Error: Malformed String Data type" << std::endl;
				std::exit(1);
			}
			if (escape)
			{
				str += ch;
				escape = false;
			}
			else if (ch == '\\')
				escape = true;
			else if (ch == '\"')
			{
				insideQuote = false;
				break;
			}
			else
				str += ch;
		}
		else if (ch == '\"')
			insideQuote = true;
		else if (ch == '\\')
			escape = true;
		else
		{
			// throw error
			std::cerr << "Error: Malformed String Data type" << std::endl;
			std::exit(1);
		}
		it++;
	}
	if ((it == text.end()) || insideQuote)
	{
		// throw error
		std::cerr << "Error: Malformed Key value" << std::endl;
		std::exit(1);
	}
	return str;
}

static jsonType	_getPrimitiveType(std::string const& str)
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
