/* Game Class */

#include <string>

class Game {
public:
	Game();
	Game(std::string sID, std::string sName, int iID, std::string sFilePath, std::string sURL);
	~Game();
};