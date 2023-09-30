#ifndef __JSONDATA_HPP__
#define __JSONDATA_HPP__

#include <string>
#include <map>
#include <vector>

enum jsonType
{
	TYPE_NUMBER,
	TYPE_STRING,
	TYPE_BOOLEAN,
	TYPE_ARRAY,
	TYPE_OBJECT,
	TYPE_NULL
};

class JsonData
{
	public:
		jsonType								_type;
		std::string								_str;
		std::vector<std::string>				_arr;
		std::multimap<std::string, JsonData>*	_obj;

	public:
		JsonData(void);
		~JsonData(void);
};

#endif	/* __JSONDATA_HPP__ */
