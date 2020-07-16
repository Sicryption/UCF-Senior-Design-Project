#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../gameObjects/mazePlayer.hpp"
#include "../scenes/scene.hpp"
#include "../scenes/MainMenuScene.hpp"

class TicTacToeScene : public Minigame 
{
    private: 
        SpriteMenuItem *wallpaper, *popup;
        m3d::Color *colorRec, *colorText;
        TextMenuItem *prompt, *winPrompt;

        enum TTTState 
        {
            TutorialMessage,
            Requesting,
            Execute,
            EnemyTurn,
            Win,
            Lose
        };

        TTTState currentState;

        enum BoardState
        {
            VACANT,
            PLAYER,
            ENEMY
        };

        BoardState currentBoardState[3][3];
    public:
        TicTacToeScene();
        ~TicTacToeScene();

        void initialize();

        void draw();

        void load();

        void unload();
        
        void SubmitTTTCode(std::vector<CommandObject*> luaCode);

        void onEnter();
		void onExit();
		bool checkWinCond();
		void loadScene();
		void loadWinScr();
		void loadLoseScr();
		void requestUI();
		void closeGame();

};