#ifndef BOARD_HPP
#define BOARD_HPP
#include <linkedlist.hpp>
#include <piece.hpp>
namespace boop {
class Board {
private:
  NodeMatrix<Piece> _matrix;

public:
  Board(const std::size_t &size);
};
} // namespace boop
#endif
