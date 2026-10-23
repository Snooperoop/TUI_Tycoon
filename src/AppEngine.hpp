#include <string>
#include <ncurses.h>
#include <vector>
#include <memory>

namespace AppEngine {

	struct AppHandler
	{
		public:
			//FIELDS
			WINDOW *useWindow {nullptr};	

			std::shared_ptr<GameEngine::GameState> gameStateInUse_ptr {};
			std::string appName {};
			std::vector<std::shared_ptr<GameEngine::GameState>> gameStates {}; 

			//CONSTRUTORS
			AppHandler(std::string n);
	
			/**
			 * @brief :: Deconstructor for the AppHandler class and throws 
			 * out all resources dedicated to such: e.g. shared pointed
			 */
			~AppHandler(void);
	
			/** 
			 * @brief :: A Copy Constructor for 
			 * 	copying the same resources/ownership 
			 * 	from one object to another.
			 * @param :: copy :: An object of type  
			 * 	const &AppHandler in the 
			 * 	AppEngine namespace such that 
			 * 	we take their resources and 
			 * 	share them to the calling object.
			 */
			AppHandler(const AppHandler &copy);

			/** 
			 * @brief :: A Move Constructor for shifting 
			 * 	resources/ownership from one object to another.
			 * 
			 * @param :: movee :: An object of type &&AppHandler 
			 * 	in the AppEngine namespace such that 
			 * 	we take their resources and give them to the calling object.
			 */	
			AppHandler(AppHandler &&movee);

			
			//METHODS
			
			/** 
			 * @brief When the program ought to start, we run this 
			 * 	method first to initialize and start up any dependencies
			 */
			void StartApp(void);

			/**
			 * @brief This method will contain the necessary logic for 
			 * 	maintain and sustaining the program at runtime.
			 */
			bool RunApp(void);
				
			/**
			 * @brief Before the program ends/closes, 
			 * this method will clean up any resources 
			 * safely and ensuring all other executions are ceased.
			 */
			void EndApp(void);
	};
}



