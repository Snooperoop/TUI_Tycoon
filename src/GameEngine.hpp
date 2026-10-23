#include <string>
#include <ncurses.h>
#include <vector>
#include <memory>



/** 
 * The GameEngine namespace will be dedicated towards handling 
 *
 */
namespace GameEngine {

	/** 
	 * - We have a super class that will 
	 *   	dictate the functionality of all sub-states defined below...
	 * - Each implementation will follow 
	 *   	their own category, however this allows the overall system 
	 * 	to worry only for its runing of the super-system.
	 */
	struct GameState {
		//FIELDS
		bool hasQuit {false};
		

		// ABSTRACT METHODS
		virtual void GetEvents() = 0;
		virtual void ComputeInfo() = 0;
		virtual void UpdateScreen() = 0;
		virtual std::shared_ptr<GameState> clone() = 0;
	};
	
	struct StartState : GameState {
		int selectedOption {0};
		int lastInput {ERR};
		bool showCredits {false};

		//CONSTRUTORS
		StartState();
		~StartState();
		StartState(const StartState &copy);
		StartState(StartState &&movee);


		virtual void GetEvents() override;
		virtual void ComputeInfo() override;
		virtual void UpdateScreen() override;
		virtual std::shared_ptr<GameState> clone() override;
	};
	struct PauseState : GameState {
		//CONSTRUTORS
		PauseState();
		~PauseState();
		PauseState(const PauseState &copy);
		PauseState(PauseState &&movee);
		// METHODS	
		virtual void GetEvents() override;
		virtual void ComputeInfo() override;
		virtual void UpdateScreen() override;	
		virtual std::shared_ptr<GameState> clone() override;
	};
	struct PlayState : GameState { 
		//CONSTRUTORS
		PlayState();
		~PlayState();
		PlayState(const PlayState &copy);
		PlayState(PlayState &&movee);
		//METHODS
		virtual void GetEvents() override;
		virtual void ComputeInfo() override;
		virtual void UpdateScreen() override;
		virtual std::shared_ptr<GameState> clone() override;
	};
}


