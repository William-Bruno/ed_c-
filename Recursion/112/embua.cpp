#define XPAINT
#include "xpaint.h"

void draw_line(int size){
    if(size < 10)
        return;
    // cores aleatorias
    auto rgb = [](){return x_math_rand(0,255);};
    x_color_set(rgb(), rgb(), rgb());
    x_pen_walk(size);
    x_pen_rotate(-90);
    draw_line(size-10);
}

int main(){
    x_open(1280, 768, "embua");
    //espessura
    x_pen_set_thick(3);
    //angulo do inicio do desendo
    x_pen_set_angle(90);
    //posicao do desenho
    x_pen_set_pos(250, 750);
    //recursao
    draw_line(700);
    x_save();
    x_close();
}

