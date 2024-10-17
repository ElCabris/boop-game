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

char type_piece_to_char(const PieceType &type);
} // namespace boop
#endif
