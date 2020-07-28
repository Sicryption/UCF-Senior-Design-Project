#pragma once
#include <random>
#include "../gameObjects/objects.h"
#include "../gameManager.hpp"
#include "../sceneManager.hpp"
#include "../resources.h"
#include "../scenes/scene.hpp"
#include "../scenes/MainMenuScene.hpp"
#include "../scenes/TTT_config.h"

#define TTT_NUM_ROWS 3
#define TTT_NUM_COLS TTT_NUM_ROWS
#define TTT_NUM_CELLS (TTT_NUM_ROWS * 3)
#define TTT_CELL_SIZE 60
#define TTT_DETECTOR_SIZE 40
#define TTT_X 220
#define TTT_Y 40

#define TTT_TUTORIAL_PAGES 4

class TicTacToeScene : public Minigame 
{
    public:
    enum BoardState
    {
        VACANT,
        PLAYER,
        ENEMY
    };

    private: 
        SpriteMenuItem *wallpaper, *field, *popup, *wPopup, *lPopup;
        m3d::Color *colorRec, *colorText;
        RectangleMenuItem *topLeftTest, *topMidTest, *topRightTest;
        RectangleMenuItem *midLeftTest, *midMidTest, *midRightTest;
        RectangleMenuItem *botLeftTest, *botMidTest, *botRightTest;

        SpriteMenuItem *tutorial[TTT_TUTORIAL_PAGES];
        int tutCount;

        m3d::BoundingBox *m_detectors[TTT_NUM_CELLS];

        bool m_isPlayerTurn;

        enum TTTState 
        {
            TutorialMessage,
            Requesting,
            Execute,
            PlayerTurn,
            EnemyTurn,
            Win,
            Lose
        };

        TTTState currentState;
    protected:
        

        BoardState m_board[TTT_NUM_CELLS];
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
        bool checkWinCond(TicTacToeScene::BoardState id);
		void loadScene();
		void loadWinScr();
		void loadLoseScr();
		void requestUI();
		void closeGame();

        void runEnemyAI();
        void updateBoard();
        bool isTied();
        void onExecutionEnd();

};