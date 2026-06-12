#ifndef GGB_GEOMETRY_HPP
#define GGB_GEOMETRY_HPP

#include "types.h"
#include "raylib.hpp"

#include <array>
#include <string>
#include <vector>

namespace geom {
using Vec2 = rl::Vector2;

static Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

static Vec2 operator+(const Vec2 &lhs, const float rhs) {
  return {lhs.x + rhs, lhs.y + rhs};
}

static Vec2 operator-(const Vec2 &lhs, const Vec2 &rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

static Vec2 operator-(const Vec2 &lhs, const float rhs) {
  return {lhs.x - rhs, lhs.y - rhs};
}

static Vec2 operator*(const Vec2 &lhs, const float rhs) {
  return {lhs.x * rhs, lhs.y * rhs};
}

static Vec2 operator/(const Vec2 &lhs, const float rhs) {
  return {lhs.x / rhs, lhs.y / rhs};
}

class Transform {
public:
  Vec2 forth(const Vec2 &v) const;
  float forth(const float v) const { return v * scale; }
  Vec2 inv(const Vec2 &v) const;

  Vec2 operator()(const Vec2 &v) const { return forth(v); }
  float operator()(const float v) const { return forth(v); }

private:
  float scale = 1.f;
  float rotate[2][2] = {{1.f, 0.f}, {0.f, 1.f}};
  Vec2 translate = {0.f, 0.f};
};

class Geometry {
public:
  struct Data {
    GeomId define;
    GeomId soln_id;
    std::array<GeomId, 5> args;
  };

  bool active = false;
  bool valid = false;
  bool selected = false;
  GeomId id = -1;
  GeomType type;
  std::string name;
  rl::Color color{};
  Data data{};

  void init(GeomId id_, GeomType type_, const std::array<GeomId, 5> &args, GeomId define,
            GeomId soln_id);

  void remove();

  void update();

  bool hovered(Vec2 pos) const;

  void draw() const;

  void draw_name() const;

  bool visible() const { return active && valid; }

  void activate();

  void deactivate();

  void select() { selected = true; }

  void deselect() { selected = false; }

private:
  using Point = Vec2;

  union Render {
    Point pt;

    struct Line {
      Point point1, point2;
    } ln;

    struct Circle {
      Point center;
      float radius;
    } cr;
  };

  unsigned version = 0;
  Render render{};
  Point name_pos{};
};

class Handle {
public:
  Handle() : id(-1) {
  }

  explicit Handle(const GeomId id) : id(id) {
  }

  Geometry *operator->() const { return &objects[id]; }

  GeomId get_id() const { return id; }

  bool valid() const { return id != -1; }

private:
  static std::vector<Geometry> &objects;
  GeomId id;
};

void init();
void cleanup();
void draw_all();
void remove_all();
void update_all();
Handle get_hovered_object(Vec2 pos);

Handle new_object(GeomType type, const std::array<GeomId, 5> &args, GeomId define = -1,
                  GeomId soln_id = 0);

void set_xform(const Transform &xform);

}

#endif //GGB_GEOMETRY_HPP