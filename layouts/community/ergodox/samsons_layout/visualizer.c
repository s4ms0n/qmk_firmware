/*
Note: this is a modified copy of ../default/visualizer.c, originally licensed GPL.
*/

#include "simple_visualizer.h"

static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    // LCD_COLOR(  0,   0, 255); // White  <> RGB(255,255,255)                   
    // LCD_COLOR( 85, 255, 255); // Green  <> RGB(  0,255,255)                   
    // LCD_COLOR(  0, 255, 255); // Red    <> RGB(255,  0,255)                   
    // LCD_COLOR(170, 255, 255); // Blue   <> RGB(  0,  0,255)                   
    // LCD_COLOR(213, 255, 255); // Purple <> RGB(255,  0,255)                   
    // LCD_COLOR( 42, 255, 255); // Yellow <> RGB(255,  0,255)                   
    // LCD_COLOR(128, 255, 255); // Aqua   <> RGB(  0,255,255)   

    if (state->status.layer & 0x10) {
        state->target_lcd_color = LCD_COLOR(85, 255, 255);
        state->layer_text = "GAME";
    } else if (state->status.layer & 0x8) {
        state->target_lcd_color = LCD_COLOR(213, 255, 255);
        state->layer_text = "COMMANDS";
    } else if (state->status.layer & 0x4) {
        state->target_lcd_color = LCD_COLOR(42, 255, 255);
        state->layer_text = "MOUSE";
    } else if (state->status.layer & 0x2) {
        state->target_lcd_color = LCD_COLOR(128, 255, 255);
        state->layer_text = "SYMBOLS";
    } else {
        state->target_lcd_color = LCD_COLOR(84, 60, 0xFF);
        state->layer_text = "DEFAULT";
    }
}
