#include "menu_bar.hpp"
#include <iostream>

namespace app::menu_bar {
class Load final : public MenuItem {
public:
  Load() {
    title = "Load";
  }

  void execute() override {
    std::cout << title << std::endl;
  }
};

MenuItemPtr item_load() {
  return std::make_unique<Load>();
}
}