#include "board.hpp"
#include "toolbar.hpp"
#include "command.hpp"

namespace app::toolbar {
GeomId find_or_push_point(const GeomId hovered, const Vec2 pos) {
  GeomId pt;
  const auto [x, y] = board::xform_to_world(pos);

  if (hovered == -1) {
    pt = geom_new_point(x, y, -1);
  } else {
    if (geom_get_type(hovered) == POINT) return hovered;
    pt = geom_new_point(x, y, hovered);
  }

  command::push(std::make_unique<command::Add>(1, &pt));
  return pt;
}

class Point final : public GeomTool {
public:
  Point() {
    usage = "point: select position";
  }

  void click(const Vec2 pos) override {
    const GeomId id = board::get_hovered_object();
    find_or_push_point(id, pos);
  }
};

ToolPtr point() {
  return std::make_unique<Point>();
}
}