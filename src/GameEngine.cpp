#include "GameEngine.hpp"


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





