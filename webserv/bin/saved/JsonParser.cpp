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
		key = _parseStringKey(text, it);
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
	while (std::isspace(*it))
		it++;
//	std::cout << data._type << ", " << data._str << ", " << data._obj  << std::endl;
	if (_checkLineEnd(text, it) == false)
	{
		// throw error
		std::cerr << "Error: Malformed JSON format" << std::endl;
		std::exit(1);
	}
	// temp
	if (*it == ',')
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
		if (*it == '\"')
		{
			data._type = TYPE_STRING;
			data._str = _parseStringValue(text, it);
		}
		else if (*it == '[')
		{
			data._type = TYPE_ARRAY;
			data._arr = parseArray(text, it);
		}
		else if (*it == '{')
		{
			data = parseObject(text, it);
		}
		else
		{
			if (*it == ',')
			{
				// throw error
				std::cerr << "Error: Malformed Array" << std::endl;
				std::exit(1);
			}
			data._str = _parsePrimitive(text, it, data._type);
		}
		arr.push_back(data);

		while (std::isspace(*it))
			it++;
		if (*it != ',' && *it != ']')
		{
			// throw error
			std::cerr << "Error: Malformed Array" << std::endl;
			std::exit(1);
		}
		if (*it == ']')
		{
			it++;
			break;
		}
		it++;
	}
	// 여기에서 배얼의 끝 체크 요소가 들어가야 할까?
	if (it == text.end())
	{
		// throw error
		std::cerr << "Error: Malformed Array" << std::endl;
		std::exit(1);
	}
	while (std::isspace(*it))
		it++;
	nxt = it + 1;
	while (std::isspace(*nxt))
		nxt++;
	if (*nxt == ']' && !std::isspace(*it))
	{
		std::cerr << "Error: malformed Array" << std::endl;
		std::exit(1);
	}
	return arr;
}

#include <chrono>
#include <thread>

JsonData	JsonParser::parseObject
(std::string const& text, std::string::iterator& it)
{
	JsonData								jsonData;
	std::multimap<std::string, JsonData>*	jsonObject;

	while (std::isspace(*it))
		++it;

	assert(*it == '{');
	it++;

	jsonObject = new std::multimap<std::string, JsonData>;
	do {

//		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		std::pair<std::string, JsonData> const keyValuePair
			= retriveKeyValuePair(text, it);
		jsonObject->insert
			(std::make_pair(keyValuePair.first, keyValuePair.second));

		while (std::isspace(*it))
			it++;
	} while (*it != '}');

	it++;
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

static bool	_checkLineEnd
(std::string const& text, std::string::iterator& it)
{
	std::string::iterator	cur;

	if (it == text.end())
	{
		// throw error
		std::cerr << "Error: Malformed Json format" << std::endl;
		std::exit(1);
	}
	cur = it + 1;
	while (std::isspace(*cur))
		cur++;
//	std::cout << "*it: " << *it << " *cur: " << *cur << std::endl;
	if (*cur == '\"' && *it == ',')
	{
		return true;
	}
	else if (*cur == ',' && *it == '}')
	{
		return true;
	}
	else if (*cur == '}' && *it == '}')
	{
		return true;
	}
	else if (cur == text.end() && *it == '}')
	{
		return true;
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
	++it;
	return key;
}

static std::string	_parseStringValue
(std::string const& text, std::string::iterator& it)
{
	std::string				value;
	std::string::iterator	cur;

	value = _getStringData(text, it);
	it++;
	while (std::isspace(*it))
		it++;
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
