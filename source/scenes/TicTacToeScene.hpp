#pragma once
#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../scenes/scene.hpp"
#include "../scenes/MainMenuScene.hpp"

class TicTacToeScene : public Minigame 
{
    private: 
        SpriteMenuItem *wallpaper, *popup;
        m3d::Color *colorRec, *colorText;
        TextMenuItem *prompt, *winPrompt;
        RectangleMenuItem *topLeftTest, *topMidTest, *topRightTest;
        RectangleMenuItem *midLeftTest, *midMidTest, *midRightTest;
        RectangleMenuItem *botLeftTest, *botMidTest, *botRightTest;
        // m3d::BoundingBox topLeftBB, topMidBB, topRightBB;
        // m3d::BoundingBox midLeftBB, midMidBB, midRightBB;
        // m3d::BoundingBox botLeftBB, botMidBB, botRightBB; 
        

        m3d::Circle *cTL, *cTM, *cTR;
        m3d::Circle *cML, *cMM, *cMR;
        m3d::Circle *cBL, *cBM, *cBR;

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
        
        void update();

        void SubmitTTTCode(std::vector<CommandObject*> luaCode);

        void onEnter();
		void onExit();
		bool checkWinCond();
		void loadScene();
		void loadWinScr();
		void loadLoseScr();
		void requestUI();
		void closeGame();
        void runEnemyAI();

};