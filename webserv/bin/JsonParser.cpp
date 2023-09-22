#include "JsonParser.hpp"

JsonParser::JsonParser(void) : _json(0) {}

JsonParser::~JsonParser(void)
{
	// ☃︎
	// need to delete all json list
}

JsonValue*	JsonParser::getJsonList(void)
{
	return this->_json;
}

void	JsonParser::setJsonList(JsonValue* json)
{
	this->_json = json;
}

JsonValue	JsonParser::makeEmptyJson(void)
{
	JsonValue	json;

	json.str = "";
	json.json = 0;
	return json;
}

void	JsonParser::freeJsonList(JsonValue& jsonValue)
{
	if (jsonValue.json)
	{
		for (std::map<std::string, JsonValue>::iterator it
			= jsonValue.json->begin();
			it != jsonValue.json->end(); ++it)
			freeJsonList(it->second);
		delete jsonValue.json;
		jsonValue.json = 0;
	}
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

JsonValue	JsonParser::parsePrimitive
(std::string const& text, text_it start, text_it end)
{
	JsonValue	result;
	std::string	substr;

	result = makeEmptyJson();
	substr = text.substr(start - text.begin(), end - start);
	result.str = substr;
	return result;
}

std::pair<std::string, JsonValue>	JsonParser::retriveKeyValuePair
(std::string const& text, text_it& it)
{
	assert(it != text.end());

	text_it		cur;
	std::string	key;
	JsonValue	value;

	// key 앞에 있는 공백 문자 제거
	while (*it == ' ' || *it == '\n' || *it == '\t')
		it++;

	if (*it == '\"')
	{
		cur = ++it;
		while (*it != '\"')
			it++;

		key = text.substr(cur - text.begin(), it - cur);
		assert(*(++it) == ':');
		it++;
	}

	// value 앞에 있는 공백 문자 제거
	while (*it == ' ' || *it == '\n' || *it == '\t')
		it++;

	if (*it == '{')
	{
		//std::cout << "pointer" << std::endl;
		// value : another json format
		value = parseJsonHelper(text, it);
	}
	else
	{
		cur = it;
		while (*it != ',' && *it != '}' && *it != '\n')
			it++;
		// value : string
		value = parsePrimitive(text, cur, it);
	}

	if (*it == ',')
		it++;

	//std::cout << key << ": [" << value.str << "], " << value.json << std::endl;
	return std::make_pair(key, value);
}

JsonValue	JsonParser::parseJsonHelper
(std::string const& text, text_it& it)
{
	assert(*it == '{');
	it++;

	JsonValue							result;
	std::map<std::string, JsonValue>*	jsonMap
		= new std::map<std::string, JsonValue>;

	// 중괄호 내의 모든 동일한 레벨의 요소들을 jsonMap에 모두 추가
	do {
		std::pair<std::string, JsonValue> const	keyValuePair
			= retriveKeyValuePair(text, it);
		(*jsonMap)[keyValuePair.first] = keyValuePair.second;

		while (*it == ' ' || *it == '\n' || *it == '\t')
			it++;
	} while (*it != '}');

	it++;
	result = makeEmptyJson();
	result.json = jsonMap;

	return result;
}

JsonValue	JsonParser::parseJson(std::string const& filepath)
{
	std::string	text;
	text_it		start;

	readFile(filepath, text);
	start = text.begin();
	return parseJsonHelper(text, start);
}
