#include <menuScreen.h>


TexturedButton* CreateButton(
    float x,
    float y,
    float width,
    float height, 
    Texture2D texture, 
    unsigned int scale)
{
    TexturedButton *button = (TexturedButton*)malloc(sizeof(TexturedButton));
    button->texture = texture;

    button->buttonRect.x = x;
    button->buttonRect.y = y;
    button->buttonRect.width = width;
    button->buttonRect.height = height;

    button->buttonBound.x =  x - 5.0f * scale;
    button->buttonBound.y =  y - 5.0f * scale;
    button->buttonBound.width =  width + 2.0f*(5.0f*scale);
    button->buttonBound.height =  height + 2.0f*(5.0f*scale);

    button->buttonState = NEUTRAL;

    return button;
}

void CreateOutline(TexturedButton *button[], unsigned int index){
    DrawRectangleLines(
        button[index]->buttonBound.x,
        button[index]->buttonBound.y,
        button[index]->buttonBound.width,
        button[index]->buttonBound.height,
        WHITE);

}

unsigned int SearchSelectedButton(TexturedButton *button[], int size, bool *array){

    int count;
    for(int i = 0; i < size;i++){
        if (button[i]->buttonState == SELECTED){
            array[i] = true;
            count++;
        }
        else{
            array[i] = false;
        }
    }
    return count;
}

bool IsButtonSelected(TexturedButton *button[], int index){
    if (button[index]->buttonState == SELECTED){
        return true;
    }
    return false;
}

void UnSelectAllButtons(TexturedButton *button[], int size){
     for(int i = 0; i < size;i++){
        button[i]->buttonState = NEUTRAL;
    }
}

