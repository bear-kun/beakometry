#ifndef BEAKOMETRY_TYPES_HPP
#define BEAKOMETRY_TYPES_HPP

#include <cstdint>

typedef int32_t GeomInt;
typedef int32_t GeomId;
typedef uint32_t GeomSize;

typedef enum {
  UNKNOWN = 0,
  POINT = 1,
  LINE = 2,
  CIRCLE = 4,
  ANY = 7
} GeomType;

#endif //BEAKOMETRY_TYPES_HPP