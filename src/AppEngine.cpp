#include "AppEngine.hpp"
#include <memory>
#include <string>
#include <ncurses.h>


/*
StartState *  ::----------------::----------------::----------------::----------------::----------------::----------------::----------------:----------------::
 *				AppHandler Implementations
 */

/** 
 * @brief :: A constructor dedicated towards the construction of AppHandler managerial class.
 * @param :: n :: A c++ string that will be some identifying arbitrary identifying name for the program. 
 */
AppEngine::AppHandler::AppHandler(std::string n) : appName(n) 
{
	// We create, load, and store all potential GameStates.
	this->gameStates.push_back(std::make_shared<GameEngine::StartState>()) ;
	this->gameStates.push_back(std::make_shared<GameEngine::PauseState>());
	this->gameStates.push_back(std::make_shared<GameEngine::PlayState>());
	// We set the default in-use state to be the StartState
	this->gameStateInUse_ptr = this->gameStates[0];
	return;	
}

/** 
 * @brief :: A Copy Constructor for copying the same resources/ownership from one object to another.
 * @param :: copy :: An object of type  const &AppHandler in the AppEngine namespace such that 
 * 	we take their resources and share them to the calling object.
 */
AppEngine::AppHandler::AppHandler(const AppHandler &copy) 
{
	// We clear the calling object's gameStates to then copy theirs to the caller 
	this->gameStates.clear();
	for (std::shared_ptr<GameEngine::GameState> gs: copy.gameStates) 
	{
		this->gameStates.push_back(gs->clone());
	}
	this->gameStateInUse_ptr = gameStates[0];

	return;
}

/** 
 * @brief :: A Move Constructor for shifting resources/ownership from one object to another. 
 * @param :: movee :: An object of type &&AppHandler in the AppEngine namespace such that 
 * 	we take their resources and give them to the calling object.
 */
AppEngine::AppHandler::AppHandler(AppHandler &&movee) 
{
	return;
}

/**
 * @brief :: Deconstructor for the AppHandler class and throws 
 * out all resources dedicated to such: e.g. shared pointed
 */
AppEngine::AppHandler::~AppHandler() 
{
	return;
}

/** 
 * @brief When the program ought to start, we run this 
 * 	method first to initialize and start up any dependencies
 */
void AppEngine::AppHandler::StartApp() 
{
	this->useWindow = initscr();
	cbreak();
	noecho();
	keypad(this->useWindow, TRUE);
	curs_set(0);
	return;
}

/**
 * @brief This method will contain the necessary logic for 
 * 	maintain and sustaining the program at runtime.
 */
bool AppEngine::AppHandler::RunApp() 
{
	//TODO

	/*
	 * When a runtime application runs we want there to be 3 phases.
	 *	- Check/Have listeners to take any buffered or currently entered inputs. 
	 *	- Processing the infomration/logic dedicated to client input
	 *	- Update the screen such that the app reflects the new output.
	 * We can deligate the following to functions because of the polymorphism 
	 * our super class allows us to enact with. 
	 */
	this->gameStateInUse_ptr->UpdateScreen();
	while (!this->gameStateInUse_ptr->hasQuit)
	{
		this->gameStateInUse_ptr->GetEvents();
		this->gameStateInUse_ptr->ComputeInfo();
		this->gameStateInUse_ptr->UpdateScreen();
	}
	return true;
}

/**
 * @brief Before the program ends/closes, 
 * this method will clean up any resources 
 * safely and ensuring all other executions are ceased.
 */
void AppEngine::AppHandler::EndApp() 
{
	// Clear all existing  resources from the calling object's member fields
	this->gameStates.clear();
	this->gameStateInUse_ptr = nullptr;
	endwin();
	this->useWindow = nullptr;
	return;
}




