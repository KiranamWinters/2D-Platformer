#ifndef MENUSCREEN_H_
#define MENUSCREEN_H_

//Libraries
#include <raylib.h>
#include <stdlib.h>

//GameStates
#define STARTED     0000
#define STARTSCREEN 0001
#define ENDSCREEN   0002
#define RUNNING     0003
#define PAUSE       0004
#define OPTION      0005

//button

#define BUTTONSCALE 1.2
#define BUTTONWIDTH  200
#define BUTTONHEIGHT 50
#define PRESSED     0001
#define SELECTED    0002
#define NEUTRAL     0000

#define NUMBEROFOPTION 3


typedef struct  {
    Texture2D texture;
    Rectangle buttonRect;
    Rectangle buttonBound;
    int buttonState;
}   TexturedButton ,*PTexturedButton;


TexturedButton* CreateButton(
    float x,
    float y,
    float width,
    float height, 
    Texture2D texture, 
    unsigned int scale
);

void UnSelectAllButtons(TexturedButton *button[], int size);
void CreateOutline(TexturedButton *button[], unsigned int index);
bool IsButtonSelected(TexturedButton *button[], int index);
unsigned int SearchSelectedButton(TexturedButton *button[], int size, bool *array);



#endif