#ifndef BOARD_HPP
#define BOARD_HPP
#include <linkedlist.hpp>
#include <piece.hpp>
namespace boop {

struct Position {
  int row, col;
};

class Board {
private:
  NodeMatrix<Piece> _matrix;

public:
  Board(const std::size_t &size);
  void add_piece(Position &position, PieceType type);
  Node<Piece> *get_piece(Position position) const;
  std::size_t get_size() const;
  bool is_game_over();
  void delete_piece(const Position &position);
};
} // namespace boop
#endif
