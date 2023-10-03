#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <string>
#include <vector>

#include "JsonData.hpp"

struct	status_page
{
	int			_status;
	std::string	_page;

	status_page(void): _status(-1) {}
};

struct	location
{
	std::string					m_path; // must be unique
	std::string					_root;
	std::string					_client_max_body_size;
	std::string					_cgi;
	bool						_autoindex;
	std::vector<std::string>	_limit_except;
	std::vector<std::string>	_index;
	std::vector<status_page>	_error_page;
	status_page					_return;

	location(void): _autoindex(false) {}
};

struct	host
{
	int							m_listen; // must be unique
	std::string					m_server_name; // must be unique
	std::string					_root;
	std::vector<std::string>	_index;
	std::vector<location>		_locations;

	host(void): m_listen(-1) {}
};

class	Config
{
	private:
		JsonData			_json;
		std::vector<host>	_hosts;

	public:
		Config(void);
		~Config(void);

	public:
		std::vector<host> const&	getHosts(void) const;
		void						setJson(JsonData& json);
};

#endif	/* __CONFIG_HPP__ */
