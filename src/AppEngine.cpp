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


/*
 *  ::----------------::----------------::----------------::----------------::----------------::----------------::----------------:----------------::
 *				StartState Implementations
 */
GameEngine::StartState::StartState()
{
	this->hasQuit = false;
}


GameEngine::StartState::~StartState()
{
	//TODO
	return;
}

GameEngine::StartState::StartState(const StartState &copy)
{
	return;
}

GameEngine::StartState::StartState(StartState &&movee)
{
	return;
}

void GameEngine::StartState::ComputeInfo()
{
	switch (this->lastInput) {
		case KEY_UP:
		case KEY_DOWN:
			this->selectedOption = 1 - this->selectedOption;
			break;
		case '\n':
		case '\r':
		case KEY_ENTER:
			if (this->selectedOption == 0) {
				this->showCredits = true;
			} else {
				this->hasQuit = true;
			}
			break;
	}
	this->lastInput = ERR;
	return;
}

void GameEngine::StartState::GetEvents()
{
	this->lastInput = getch();
	return;
}

void GameEngine::StartState::UpdateScreen()
{
	erase();
	const char *options[] = {"Credits", "Quit"};
	for (int i = 0; i < 2; ++i) {
		if (i == this->selectedOption) {
			attron(A_REVERSE);
		}
		mvaddnstr(i, 0, options[i], COLS);
		attroff(A_REVERSE);
	}
	if (this->showCredits) {
		mvaddnstr(LINES - 1, 0, "Tommy Two Shoes", COLS);
	}
	refresh();
	return;
}


std::shared_ptr<GameEngine::GameState> GameEngine::StartState::clone() 
{
	return NULL;
}




/*
 *  ::----------------::----------------::----------------::----------------::----------------::----------------::----------------:----------------::
 *				PauseState Implementations
 */
GameEngine::PauseState::PauseState()
{
	this->hasQuit = false;
}

GameEngine::PauseState::~PauseState()
{
	//TODO
	return;
}

GameEngine::PauseState::PauseState(const PauseState &copy)
{
	return;
}

GameEngine::PauseState::PauseState(PauseState &&movee)
{
	return;
}

void GameEngine::PauseState::ComputeInfo()
{
	//TODO
	return;
}

void GameEngine::PauseState::GetEvents()
{
	//TODO
	return;
}

void GameEngine::PauseState::UpdateScreen()
{
	//TODO
	return;
}


std::shared_ptr<GameEngine::GameState> GameEngine::PauseState::clone() 
{
	return NULL;
}


/*
 *  ::----------------::----------------::----------------::----------------::----------------::----------------::----------------:----------------::
 *				PlayState Implementations
 */
GameEngine::PlayState::PlayState()
{
	this->hasQuit = false;
}

GameEngine::PlayState::~PlayState()
{
	//TODO
	
	return;
}

GameEngine::PlayState::PlayState(const PlayState &copy)
{
	return;
}

GameEngine::PlayState::PlayState(PlayState &&movee)
{
	return;
}


void GameEngine::PlayState::ComputeInfo()
{
	//TODO
	return;
}

void GameEngine::PlayState::GetEvents()
{
	//TODO
	return;
}

void GameEngine::PlayState::UpdateScreen()
{
	//TODO
	return;
}

std::shared_ptr<GameEngine::GameState> GameEngine::PlayState::clone() 
{
	return NULL;
}





