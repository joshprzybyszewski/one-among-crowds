#include "map.h"

int map_init()
{
  return build_basic_map();
}

int build_basic_map()
{
  int x, y;
  for(y = 0; y < MAP_Y; y++) {
    path_preference_t pref;
    char tile_sym;
    switch( y % 4) {
    case 0:
      pref = PREFFERED;
      tile_sym = '`';
      break;
    case 1:
      pref = NATURAL;
      tile_sym = '-'
      break;
    case 2:
      pref = AVOIDED;
      tile_sym = '0';
      break;
    case 3:
      pref = IMPASSABLE;
      tile_sym = 'X';
      break;
    default:
      pref = PREFERRED;
      tile_sym = '`';
    }
    for(x = 0; x < MAP_X; x++) {
      map[y][x].preference = pref;
      map[y][x].symbol = tile_sym;
    }
  }

  return 0;
}

void show_map()
{
  int x, y;
  for(y = 0; y < MAP_Y; y++) {
    for(x = 0; x < MAP_X; x++) {
      printf("%c", map[y][x].symbol);
    }
    printf("\n");
  }
}
