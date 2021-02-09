#include <iostream>
#include <string>

using namespace std;

extern "C"
{
    #include "Lua542/include/lua.h"
    #include "Lua542/include/lauxlib.h"
    #include "Lua542/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Lua542/liblua54.a")
#endif

int main(){
    string cmd = "a = 1000000000000000000000 + 1";

    lua_State *L = luaL_newstate();

    int r = luaL_dostring(L, cmd.c_str());

    if(r == LUA_OK){
        lua_getglobal(L, "a");
        if (lua_isnumber(L, -1)){
            float a = (float)lua_tonumber(L, -1);
            cout << "var a in c++ = " << a <<endl;
        }
    }
    else{
        string errormsg = lua_tostring(L, -1);
        cout << errormsg << endl;
    }

    system("pause");
    lua_close(L);
    return 0;
}