#include <raylib.h>
#include <raymath.h>
#include <sound.h>
#include <menuScreen.h>

//Screen Resolution
#define WINDOW_NAME "2d Platformer"
#define SCREENWIDTH  1900
#define SCREENHEIGHT 1200

int GameState = STARTED;

int main(void){ 

    InitWindow(SCREENWIDTH,SCREENHEIGHT, WINDOW_NAME);
    SetTargetFPS(90);
    ToggleFullscreen();
    int index = 0;

    Texture2D StartButton = LoadTexture("../assets/start.png");
    //Texture2D OptionButton = "";
    //Texture2D ExitButton = "";

    TexturedButton* Start = CreateButton(
        SCREENWIDTH/2 - 100,
        800,
        BUTTONWIDTH,
        BUTTONHEIGHT,
        StartButton,
        BUTTONSCALE);
    TexturedButton* Option =  CreateButton(
        SCREENWIDTH/2 - 100,
        900,
        BUTTONWIDTH,
        BUTTONHEIGHT,
        StartButton,
        BUTTONSCALE);

    TexturedButton* Exit =  CreateButton(
        SCREENWIDTH/2 - 100,
        1000,
        BUTTONWIDTH,
        BUTTONHEIGHT,
        StartButton,
        BUTTONSCALE);

    TexturedButton* ButtonList[NUMBEROFOPTION] = {
            Start,
            Option,
            Exit};

    while(!WindowShouldClose()){
        if (IsKeyDown(KEY_BACKSLASH)){
            CloseWindow();
        }
    
        switch (GameState){
            case (STARTED):{
                ClearBackground(BLACK);
                BeginDrawing();
                DrawText("Press F to Start,",800,900,100,WHITE);
                EndDrawing();               
                if(IsKeyDown(KEY_F)){
                    GameState = STARTSCREEN;
                    Start->buttonState = SELECTED;
                }
            }   break;
        
            case (STARTSCREEN):{
                
                //KeyInput
                if(IsKeyPressed(KEY_DOWN)){
                    UnSelectAllButtons(ButtonList,NUMBEROFOPTION);
                    index++;
                    //Bound Checking
                    if (index > NUMBEROFOPTION - 1){
                        index = NUMBEROFOPTION - 1;
                    }
                    ButtonList[index]->buttonState = SELECTED;
                }

                if(IsKeyPressed(KEY_UP)){
                    UnSelectAllButtons(ButtonList,NUMBEROFOPTION);
                    index--;
                //Bound Checking
                    if(index < 0){
                        index = 0;
                    }
                    ButtonList[index]->buttonState = SELECTED;   
                }

                //When the buttons are pressed
                if(Start->buttonState == SELECTED && IsKeyPressed(KEY_ENTER)){
                    GameState = RUNNING;
                }

                if(Option->buttonState == SELECTED && IsKeyPressed(KEY_ENTER)){
                    //GameState = OPTION;
                }
                
                if(Exit->buttonState == SELECTED && IsKeyPressed(KEY_ENTER)){
                    CloseWindow();
                }


                //Drawing Buttons
                BeginDrawing();
                ClearBackground(BLACK);
                CreateOutline(ButtonList,index);

                DrawTextureRec(
                    StartButton,
                    Start->buttonRect,
                    (Vector2){Start->buttonRect.x, Start->buttonRect.y},
                    WHITE); 
                DrawTextureRec(
                    StartButton,
                    Option->buttonRect,
                    (Vector2){Option->buttonRect.x, Option->buttonRect.y},
                    WHITE);
                DrawTextureRec(
                    StartButton,
                    Exit->buttonRect,
                    (Vector2){Exit->buttonRect.x, Exit->buttonRect.y},
                    WHITE);  
                EndDrawing();
            }   break;

            case(RUNNING):{
                BeginDrawing();
                    ClearBackground(BLACK);
                    DrawRectangle(SCREENWIDTH/2,SCREENHEIGHT/2,500,500,WHITE);
                EndDrawing();
            } break;

            case(OPTION):{

            } break;
        
            default:
                break;
        }


    }
    CloseWindow();
}