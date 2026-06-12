#ifndef GGB_TOOLBAR_H
#define GGB_TOOLBAR_H


#include "board.hpp"
#include <memory>

namespace app::toolbar {
class GeomTool : public board::Control {
public:
  std::string usage;

  virtual void reset() {
  }
};

void init(int x, int y, int w, int h);
void listen();
void draw();
void cleanup();

using ToolPtr = std::unique_ptr<GeomTool>;
ToolPtr tool_angle_bisector();
ToolPtr tool_circle();
ToolPtr tool_circumcircle();
ToolPtr tool_delete();
ToolPtr tool_intersection();
ToolPtr tool_line();
ToolPtr tool_midpoint();
ToolPtr tool_move();
ToolPtr tool_parallel();
ToolPtr tool_perpendicular();
ToolPtr tool_point();
ToolPtr tool_tangent();
}

#endif // GGB_TOOLBAR_H