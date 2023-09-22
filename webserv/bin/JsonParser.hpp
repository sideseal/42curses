#ifndef __JSONPARSER_HPP__
#define __JSONPARSER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <map>

typedef std::string::iterator	text_it;

struct JsonValue
{
	std::string							str;
	std::map<std::string, JsonValue>*	json;
};

class JsonParser
{
	private:
		JsonValue*	_json;

	public:
		JsonParser(void);
		~JsonParser(void);

	public:
		JsonValue*	getJsonList(void);
		void		setJsonList(JsonValue* json);
		JsonValue	makeEmptyJson(void);
		void		freeJsonList(JsonValue& jsonValue);

	public:
		void								readFile(
												std::string const& filepath,
												std::string& output
											);
		JsonValue							parsePrimitive(
												std::string const& text,
												text_it start, text_it end
											);
		std::pair<std::string, JsonValue>	retriveKeyValuePair(
												std::string const& text,
												text_it& it
											);
		JsonValue							parseJsonHelper(
												std::string const& text,
												text_it& it
											);
		JsonValue							parseJson(
												std::string const& filepath
											);
};

#endif	/* __JSONPARSER_HPP__ */
