#include "board.hpp"
#include "toolbar.hpp"
#include "menu_bar.hpp"

using namespace app;

constexpr int WINDOW_WIDTH = 1600;
constexpr int WINDOW_HEIGHT = 1000;

int main() {
  rl::init_window(WINDOW_WIDTH, WINDOW_HEIGHT, "ggb");
  rl::set_target_fps(60);
  rl::set_exit_key(0);

  menu_bar::init(0, 0, WINDOW_WIDTH, 30);
  toolbar::init(0, 30, WINDOW_WIDTH, 80);
  board::init(0, 110, WINDOW_WIDTH, WINDOW_HEIGHT - 110);

  while (!rl::window_should_close()) {
    menu_bar::listen();
    toolbar::listen();
    board::listen();


    rl::begin_drawing();
    rl::clear_background(rl::WHITE);
    board::draw();
    toolbar::draw();
    menu_bar::draw();
    rl::end_drawing();
  }

  menu_bar::cleanup();
  toolbar::cleanup();
  board::cleanup();
  rl::close_window();
  return 0;
}