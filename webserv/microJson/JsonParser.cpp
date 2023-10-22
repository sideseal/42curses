#include "JsonParser.hpp"

static void	_errorExit(std::string const& msg);
static void	_skipWhiteSpaces(std::string const& txt, std::string::iterator& it);

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

JsonData&	JsonParser::parseJson(std::string const& filepath)
{
	std::string				text;
	std::string::iterator	start;

	readFile(filepath, text);
	start = text.begin();

	_skipWhiteSpaces(text, start);

	this->_json = parseValue(text, start);

	start++;
	_skipWhiteSpaces(text, start);

	if (start != text.end())
	{
		_errorExit("Error: Failed to parse JSON file");
	}

	return this->_json;
}

std::vector<JsonData>	JsonParser::findDataByKey
(JsonData const& jsonData, std::string const& key)
{
	std::vector<std::pair<std::string, JsonData> > const&
							jsonObject = jsonData._obj;
	std::vector<JsonData>	results;

	for (std::size_t i = 0; i < jsonObject.size(); ++i)
	{
		if (jsonObject[i].first == key)
		{
			results.push_back(jsonObject[i].second);
			continue;
		}

		if (jsonObject[i].second._type == TYPE_OBJECT
			&& !jsonObject[i].second._obj.empty())
		{
			std::vector<JsonData>	ret;

			ret = findDataByKey(jsonObject[i].second, key);
			results.insert(results.end(), ret.begin(), ret.end());
		}
		else if (jsonObject[i].second._type == TYPE_ARRAY
				&& !jsonObject[i].second._arr.empty())
		{
			for (std::size_t j = 0; j < jsonObject[i].second._arr.size(); ++j)
			{
				if (jsonObject[i].second._arr[j]._type == TYPE_OBJECT
					|| jsonObject[i].second._arr[j]._type == TYPE_ARRAY)
				{
					std::vector<JsonData>	ret;

					ret = findDataByKey(jsonObject[i].second._arr[j], key);
					results.insert(results.end(), ret.begin(), ret.end());
				}
			}
		}
	}

	return results;
}

/* *************************************************************************** *
 * Private Member Functions                                                    *
 * ****************************************************************************/

void	JsonParser::readFile
(std::string const& filepath, std::string& output)
{
	std::ifstream		file(filepath.c_str(), std::ios::in | std::ios::binary);
	std::ostringstream	ss;

	if (!file.is_open())
	{
		_errorExit("Error: Cannot open " + filepath);
	}

	ss << file.rdbuf();

	if (file.fail())
	{
		file.close();
		_errorExit("Error: Failed to read a file");
	}

	file.close();

	output = ss.str();
}

JsonData	JsonParser::parseValue
(std::string const& text, std::string::iterator& it)
{
	JsonData	value;

	if (*it == '{')
	{
		value = parseObject(text, it);
	}
	else if (*it == '\"')
	{
		value._type = TYPE_STRING;
		value._str = parseStringValue(text, it);
	}
	else if (*it == '[')
	{
		value._type = TYPE_ARRAY;
		value._arr = parseArray(text, it);
	}
	else if (std::isalnum(*it) || *it == '.' || *it == '-' || *it == '+')
	{
		value._str = parsePrimitive(text, it, value._type);
	}
	else
	{
		_errorExit("Error: Invalid object value");
	}

	return value;
}

/*
 * TODO
 * Array도 BNF 형식에 맞게 변경해보기
 * parseValue로 시작하는게 아니라 parseJson으로 시작하기?
 */

std::vector<JsonData>	JsonParser::parseArray
(std::string const& text, std::string::iterator& it)
{
	std::vector<JsonData>	arr;
	std::string::iterator	nxt;

	_skipWhiteSpaces(text, it);

	if (it == text.end())
	{
		_errorExit("Error: EOF encountered before reading array");
	}
	else if (*it != '[')
	{
		_errorExit("Error: Array must start with an open square bracket");
	}
	it++;

	while (it != text.end())
	{
		JsonData	data;

		_skipWhiteSpaces(text, it);

		if (it == text.end())
		{
			_errorExit("Error: EOF encountered while reading array");
		}
		else if (*it == ']')
		{
			return arr;
		}
		else if (*it == '{')
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
		else if (std::isalnum(*it) || *it == '.' || *it == '-' || *it == '+')
		{
			data._str = parsePrimitive(text, it, data._type);
		}
		else
		{
			_errorExit("Error: Invalid array element");
		}

		// void로 바꿀까?
		if (checkElementEnd(text, it) == false)
		{
			_errorExit("Error: Malformed array format");
		}

		_skipWhiteSpaces(text, it);

		if (it == text.end())
		{
			_errorExit("Error: EOF encountered while reading array");
		}
		else if (*it == ',')
		{
			it++;
		}

		arr.push_back(data);
	}

	return arr;
}

JsonData	JsonParser::parseObject
(std::string const& text, std::string::iterator& it)
{
	JsonData										jsonData;
	std::vector<std::pair< std::string, JsonData> >	jsonObject;

	if (it == text.end())
	{
		_errorExit("Error: EOF encountered before reading object");
	}
	else if (*it != '{')
	{
		_errorExit("Error: Object must start with an open curly bracket");
	}
	else
	{
		it++;
	}

	_skipWhiteSpaces(text, it);

	if (it == text.end())
	{
		_errorExit("Error: EOF encountered while reading object");
	}
	else if (*it == '}')
	{
		jsonData._type = TYPE_OBJECT;
		return jsonData;
	}
	else
	{
		// proceed (object has key-value)
	}

	while (it != text.end() && *it != '}')
	{
		std::string	key;
		JsonData	value;

		_skipWhiteSpaces(text, it);

		if (it == text.end())
		{
			_errorExit("Error: EOF encountered before reading object key");
		}
		else if (*it == '\"')
		{
			key = parseStringKey(text, it);
		}
		else
		{
			_errorExit("Error: Object key must starts with double quote");
		}

		_skipWhiteSpaces(text, it);

		if (it == text.end())
		{
			_errorExit("Error: EOF encountered while reading object key");
		}
		else if (*it != ':')
		{
			_errorExit("Error: Missing colon after key");
		}
		else
		{
			it++;
		}

		_skipWhiteSpaces(text, it);

		value = parseValue(text, it);

		jsonObject.push_back(std::make_pair(key, value));

		if (it == text.end())
		{
			_errorExit("Error: EOF encountered while reading object value");
		}
		else if (checkKeyValueEnd(text, it) == false)
		{
			_errorExit("Error: Malformed object format");
		}
		else 
		{
			// proceed (value has valid object end part)
		}

		if (*it == ',')
		{
			it++;
		}
		else
		{
			// nothing to do
		}

		_skipWhiteSpaces(text, it);
	}

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
		_errorExit("Error: EOF encountered before checking array end");
	}

	cur = it + 1;
	while (cur != text.end() && (*cur == ',' || std::isspace(*cur)))
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

	if (cur == text.end())
	{
		_errorExit("Error: EOF encountered while checking array end");
	}
	else if (*cur == '\"')
	{
		if (comma == true)
		{
			it++;
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
			it++;
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
			it++;
			return true;
		}
		else
		{
			_errorExit("Error: Missing comma before element");
		}
	}
	else if (std::isalnum(*cur) || *it == '.' || *it == '-' || *it == '+')
	{
		if (comma == true)
		{
			it++;
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
			it++;
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

	cur = it + 1;
	while (cur != text.end() && (*cur == ',' || std::isspace(*cur)))
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
		else
		{
			// skipped
		}
		cur++;
	}

	if (cur == text.end())
	{
		_errorExit("Error: EOF encountered while checking object end part");
	}
	else if (*cur == '\"')
	{
		if (comma == true)
		{
			it++;
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
			it++;
			return true;
		}
		else
		{
			_errorExit("Error: Found comma before end of object");
		}
	}
	else
	{
		_errorExit("Error: Object key must starts with double quote");
	}

	return false; // unreachable
}

std::string	JsonParser::parsePrimitive
(std::string const& text, std::string::iterator& it, jsonType& type)
{
	std::string	value;

	while (it != text.end()
			&& (std::isalnum(*it) || *it == '.' || *it == '-' || *it == '+'))
	{
		value += *it;
		it++;
	}
	it--;

	if (it + 1 == text.end())
	{
		_errorExit("Error: EOF encountered while reading primitive");
	}

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

	return key;
}

std::string	JsonParser::parseStringValue
(std::string const& text, std::string::iterator& it)
{
	std::string value;

	value = getStringData(text, it);

	if (it == text.end())
	{
		_errorExit("Error: EOF encountered while reading value");
	}

	return value;
}

std::string	JsonParser::getStringData
(std::string const& text, std::string::iterator& it)
{
	std::string	str;
	bool		escape = false;
	char		ch;

	it++;
	while (it != text.end())
	{
		ch = *it;
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
			str += ch;
			escape = true;
		}
		else if (ch == '\"')
		{
			break;
		}
		else
		{
			str += ch;
		}
		it++;
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

static void	_skipWhiteSpaces
(std::string const& text, std::string::iterator& it)
{
	while (it != text.end() && std::isspace(*it))
		it++;
}