#define XPAINT
#include "xpaint.h"

void draw_circle(float x, float y, double raio){
    if(raio < 2)
        return;
    x_color_set(255,20,147);
    x_draw_circle(x,y,raio);


    for(int i = 0; i < 5; i++){
        draw_circle(x + raio * x_math_cos(i * (360 / 5)),
        y - raio * x_math_sin(i * (360 / 5)),
        raio * 0.35);
    }
}

int main(){

    x_open(1280, 768, "circulos");
    //espessura
    x_pen_set_thick(3);
    //recursao
    draw_circle(600, 380, 200);
    x_save();
    x_close();
}