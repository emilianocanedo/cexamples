#include <iostream>
#include <lua.hpp>

extern "C" {
  static int l_cppfunction(lua_State *L) {
    double arg = luaL_checknumber(L,1);
    lua_pushnumber(L, arg * 0.5);
    return 1;
  }
}

using namespace std;
int main()
{
  cout << "** Test Lua embedding" << endl;
  cout << "** Init Lua" << endl;
  lua_State *L;
  L = luaL_newstate();
  cout << "** Load the (optional) standard libraries, to have the print function" << endl;
  luaL_openlibs(L);
  cout << "** Load chunk. without executing it" << endl;
  if (luaL_loadfile(L, "luascript.lua")) {
    cerr << "Something went wrong loading the chunk (syntax error?)" << endl;
    cerr << lua_tostring(L, -1) << endl;
    lua_pop(L,1);
  }

  cout << "** Make a insert a global var into Lua from C++" << endl;
  lua_pushnumber(L, 1.1);
  lua_setglobal(L, "cppvar");

  cout << "** Execute the Lua chunk" << endl;
  if (lua_pcall(L,0, LUA_MULTRET, 0)) {
    cerr << "Something went wrong during execution" << endl;
    cerr << lua_tostring(L, -1) << endl;
    lua_pop(L,1);
  }

  cout << "** Read a global var from Lua into C++" << endl;
  lua_getglobal(L, "luavar");
  double luavar = lua_tonumber(L,-1);
  lua_pop(L,1);
  cout << "C++ can read the value set from Lua luavar = " << luavar << endl;

  cout << "** Execute a Lua function from C++" << endl;
  lua_getglobal(L, "myluafunction");
  lua_pushnumber(L, 5);
  lua_pcall(L, 1, 1, 0);
  cout << "The return value of the function was " << lua_tostring(L, -1) << endl;
  lua_pop(L,1);

  cout << "** Execute a C++ function from Lua" << endl;
  cout << "**** First register the function in Lua" << endl;
  lua_pushcfunction(L,l_cppfunction);
  lua_setglobal(L, "cppfunction");

  cout << "**** Call a Lua function that uses the C++ function" << endl;
  lua_getglobal(L, "myfunction");
  lua_pushnumber(L, 5);
  lua_pcall(L, 1, 1, 0);
  cout << "The return value of the function was " << lua_tonumber(L, -1) << endl;
  lua_pop(L,1);

  cout << "** Release the Lua enviroment" << endl;
  lua_close(L);
}
