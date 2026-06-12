#ifndef GGB_MENU_BAR_HPP
#define GGB_MENU_BAR_HPP

#include <string>
#include <memory>

namespace app::menu_bar {
class MenuItem {
public:
  std::string title;

  virtual ~MenuItem() = default;
  virtual void execute() = 0;
};

void init(int x, int y, int w, int h);
void cleanup();
void listen();
void draw();

using MenuItemPtr = std::unique_ptr<MenuItem>;
MenuItemPtr item_save();
MenuItemPtr item_load();

}

#endif //GGB_MENU_BAR_HPP