#include <vector>
#include <string>

class GameList
{

public:
	GameList();
	GameList(std::vector<std::string> vList, std::string sConsole);
	~GameList();
private:
	std::vector<std::string> _vList;
	std::string _sConsole;

};