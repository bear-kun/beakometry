#ifndef GGB_BOARD_H
#define GGB_BOARD_H

#include "geometry.hpp"

namespace app::board {
class Control {
public:
  virtual ~Control();
  virtual void down(Vec2) = 0;
  virtual void up(Vec2) = 0;
  virtual void click(Vec2) = 0;
  virtual void move(Vec2) = 0;
  virtual void drag(Vec2) = 0;
};

void init(int x, int y, int w, int h);
void listen();
void draw();
void cleanup();

bool object_exist(GeomId id);
void add_object(GeomId id);
void remove_object(GeomId id);
void set_control(Control &ctrl);
void select_object(GeomId id);
void deselect_object(GeomId id);
void update_objects();

Vec2 xform_to_world(Vec2 pos);
GeomId get_hovered_object();
}

#endif // GGB_BOARD_H