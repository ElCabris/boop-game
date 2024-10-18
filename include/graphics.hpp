#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include <board.hpp>

namespace boop {
class GBoard {
private:
  Board &_board;

public:
  GBoard(Board &board);
  void draw() const;
};

} // namespace boop
#endif
