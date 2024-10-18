#include <graphics.hpp>
#include <iostream>
#include <player.hpp>

int main() {
  const std::size_t initial_number_chips = 8;

  // boards
  boop::Board board(3);
  boop::GBoard gboard(board);

  // players
  boop::Player player1(initial_number_chips, boop::PLAYER1);
  boop::Player player2(initial_number_chips, boop::PLAYER2);

  // print funciont (It is advisable to pass a lambda function)
  auto print = [&]() -> void {
    std::cout << "- - - - - - - - - - - - - - - -" << std::endl;
    gboard.draw();
    std::cout << std::endl << "player 1" << std::endl << "{ ";

    for (const auto &it : player1.get_pieces()) {
      std::cout << type_piece_to_char(it.get_type()) << ' ';
    }
    std::cout << "} " << std::endl << "player 2" << std::endl << "{ ";

    for (const auto &it : player2.get_pieces()) {
      std::cout << type_piece_to_char(it.get_type()) << ' ';
    }
    std::cout << "} " << std::endl
              << "- - - - - - - - - - - - - - - -" << std::endl;
  };

  char type_piece;
  int row, col;

  while (!board.is_game_over()) {
    print();

    // player 1's turn
    std::cout << "player1, push your piece: ";
    std::cin >> type_piece >> row >> col;
    std::cin.ignore();

    // player 2's turn
    std::cout << "player2, push your piece: ";
    std::cin >> type_piece >> row >> col;
    std::cin.ignore();
  }
  return 0;
}
