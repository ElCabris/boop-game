#include <board.hpp>
#include <iostream>
#include <ostream>

int main() {
  boop::Board board(3);
  auto b = board.get_piece({2, 2});
  auto a = board.get_piece({0, 0});

  std::cout << b->value.get_type() << std::endl
            << a->value.get_type() << std::endl;
  return 0;
}
