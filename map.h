#ifndef MAP_H
# define MAP_H

#define MAP_X 64
#define MAP_Y 32

typedef enum path_preference {
  PREFERRED,
  NATURAL,
  AVOIDED,
  IMPASSABLE
} path_preference_t;

typedef struct tile {
  char symbol;
  path_preference_t preference;
} tile_t;

tile_t map[MAP_Y][MAP_X];

int map_init();
int build_basic_map();

void show_map();

#endif
