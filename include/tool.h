#ifndef GGB_TOOL_H
#define GGB_TOOL_H

#include "geometry.h"
#include "board.hpp"
#include "command.h"

typedef struct {
  const char *usage;
  void (*reset)(void);
  BoardControl ctrl;
} GeomTool;


void tool_move(GeomTool *);
void tool_point(GeomTool *);
void tool_line(GeomTool *);
void tool_circle(GeomTool *);
void tool_midpoint(GeomTool *);
void tool_perp(GeomTool *);
void tool_parallel(GeomTool *);
void tool_bisector(GeomTool *);
void tool_tangent(GeomTool *);
void tool_circum(GeomTool *);
void tool_isect(GeomTool *);
void tool_delete(GeomTool *);

#endif // GGB_TOOL_H