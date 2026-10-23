#include <stdio.h>
#include <ncurses.h>
#include "AppEngine.hpp"

int main()
{
	AppEngine::AppHandler app {"Test-App"};
	app.StartApp();
	app.RunApp();
	app.EndApp();
	return 0;
}
