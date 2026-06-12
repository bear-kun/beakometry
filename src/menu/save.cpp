#include "menu_bar.hpp"
#include <iostream>

namespace app::menu_bar {
class Save final : public MenuItem {
public:
  Save() {
    title = "Save";
  }

  void execute() override {
    std::cout << title << std::endl;
  }
};

MenuItemPtr item_save() {
  return std::make_unique<Save>();
}
}