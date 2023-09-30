#ifndef __JSONPARSER_HPP__
#define __JSONPARSER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "JsonData.hpp"

class JsonParser
{
	private:
		JsonData*	_json;

	public:
		JsonParser(void);
		~JsonParser(void);

	public:
		JsonData*	getJson(void);

	public:
		void								readFile(
												std::string const& filepath,
												std::string& output
											);
		std::pair<std::string, JsonData>	retriveKeyValuePair(
												std::string const& text,
												std::string::iterator& it
											);
		JsonData							parseObject(
												std::string const& text,
												std::string::iterator& it
											);
		JsonData							parseJson(
												std::string const& filepath
											);
};

#endif	/* __JSONPARSER_HPP__ */
