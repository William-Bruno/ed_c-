#define XPAINT
#include "xpaint.h"

void draw_tree(double size){
    if(size < 1)
        return;
    int angle = x_math_rand(30,50);
    double fator = x_math_rand(60, 70)/100.0;
    auto rgb = [](){return x_math_rand(0,255);};
    x_color_set(rgb(), rgb(), rgb());
    x_pen_set_thick((int) size/40 + 1);
    x_pen_walk(size);
    x_pen_rotate(-angle);
    draw_tree(size * fator);
    x_pen_rotate(2 * angle);
    draw_tree(size * fator);
    x_pen_rotate(-angle);
    x_pen_walk(-size);
}


int main(){

    x_open(1280, 768, "arvore");
    //espessura
    x_pen_set_thick(3);
    //angulo do inicio do desenho
    x_pen_set_angle(90);
    //posicao do desenho
    x_pen_set_pos(600, 700);
    //recursao
    draw_tree(200);
    x_save();
    x_close();
}