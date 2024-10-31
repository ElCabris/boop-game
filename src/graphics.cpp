#include <graphics.hpp>
#include <iostream>
#include <piece.hpp>

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

boop::GBoard::GBoard(Board &board) : _board(board) {}

void boop::GBoard::draw() const {
  const auto size = static_cast<int>(_board.get_size());
  std::cout << "  ";
  for (auto i = 0; i < size; i++) {
    std::cout << (char)('A' + i) << ' ';
  }
  std::cout << std::endl;
  for (auto i = 0; i < size; i++) {
    std::cout << (i + 1) << ' ';
    for (auto j = 0; j < size; j++) {
      std::cout << type_piece_to_char(
          _board.get_piece({i, j})->value.get_type());
      std::cout << ' ';
    }
    std::cout << std::endl;
  }
}
