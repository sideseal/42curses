#include "Config.hpp"

/* *************************************************************************** *
 * Constructor & Destructor                                                    *
 * ****************************************************************************/

Config::Config(void) {}

Config::~Config(void) {}

/* *************************************************************************** *
 * Public Member Functions                                                     *
 * ****************************************************************************/

std::vector<host> const&	Config::getHosts(void) const
{
	return this->_hosts;
}

void	Config::setJson(JsonData& json)
{
	this->_json = json;
}
