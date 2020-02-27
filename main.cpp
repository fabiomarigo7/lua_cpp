#include <LUA/lua.hpp>
#include <LuaBridge/LuaBridge.h>
#include <iostream>
#include "LuaScript.h"

using namespace luabridge;

void printMessage(const std::string& s) {
	std::cout << s << std::endl;
}

void readAndExecuteScript() {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	getGlobalNamespace(L).addFunction("Print", printMessage);
	luaL_dofile(L, "settings.lua");
	lua_pcall(L, 0, 0, 0);
}

void getDataFromLua() {
	LuaScript script("settings.lua");

	float windowWidth = script.get<float>("window_width");
	std::cout << windowWidth << std::endl;

	std::vector<int> v = script.getIntVector("array");
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;

	/*float posX = script.get<float>("player.position.x");
	float posY = script.get<float>("player.position.y");
	std::string filename = script.get<std::string>("player.filename");
	int hp = script.get<int>("player.HP");*/

	/*std::cout << "Position X = " << posX << ", Y = " << posY << std::endl;
	std::cout << "Filename:" << filename << std::endl;
	std::cout << "HP:" << hp << std::endl;*/
}

int main() {

	getDataFromLua();
	
	system("pause");


}