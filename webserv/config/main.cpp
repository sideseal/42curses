#include "JsonParser.hpp"
#include "Config.hpp"
#include "util.hpp"

int	main(int argc, char *argv[])
{
	JsonParser	jsonParser;
	Config		config;

//	atexit(check_leaks);
	if (argc == 2)
	{
		config.setJson(jsonParser.parseJson(argv[1]));
		std::cout << "====== result =====" << std::endl;
		printJson(jsonParser.getJson(), 0);
	}
	else
	{
		std::cerr << "Please test with file" << std::endl;
		return 1;
	}
	return 0;
}
