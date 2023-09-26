#ifndef __JSONPARSER_HPP__
#define __JSONPARSER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <map>

struct Json
{
	std::string							str;
	std::multimap<std::string, Json>*	ptr;
};

class JsonParser
{
	private:
		Json*	_json;

	public:
		JsonParser(void);
		~JsonParser(void);

	public:
		Json*	getJson(void);
		Json	getEmptyJson(void);
		void	freeJson(Json& json);

	public:
		void				readFile(
								std::string const& filepath,
								std::string& output
							);
		Json				parseValue(
								std::string const& text,
								std::string::iterator& start,
								std::string::iterator& end
							);

};



#endif	/* __JSONPARSER_HPP__ */
