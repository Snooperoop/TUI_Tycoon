

/*
 * - In TUI Tycoon there are two types of purchases that the player can make, Upgrades and Additions.
 */


/**
 * @brief Upgrades namespace will contain classes and variables 
 * dedicated to features that inherently make the player better.
 *
 * @Examples: +5% Income, +5% rebirth charge, +10% free upgrade charge 
 */
namespace Upgrades { };

/***/
namespace Additions { };



struct Player 
{ 
	//Fields
	private:
		std::

	public: 
		//Constructors, Deconstructors, and Overloads
		Player();
		~Player();
		Player(const Player &original);
		Player& operator=(const Player &original);
		Player(Player &&previousOwner);
		Player&& operator=(Player &&previousOwner);
	
		// Methods
};
