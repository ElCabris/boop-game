#include <cassert>
#include <game_manager.hpp>
#include <graphics.hpp>
#include <iostream>
#include <player.hpp>

int main() {
  const std::size_t initial_number_chips = 8;
  const std::size_t size_board = 6;

  // boards
  boop::Board board(size_board);
  boop::GBoard gboard(board);

  // players
  boop::Player player1(initial_number_chips, boop::PLAYER1);
  boop::Player player2(initial_number_chips, boop::PLAYER2);

  boop::GameManager game_manager(board, player1, player2);

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

  char type_piece_char;
  boop::PieceType type_piece;
  int row, col;

  while (true) {
    print();

    // player 1's turn
    std::cout << "player1, push your piece (piece, row, col): ";
    std::cin >> type_piece_char >> row >> col;
    std::cin.ignore();

    // get piece type
    type_piece = boop::char_to_type_piece(type_piece_char);
    switch (type_piece) {
    case boop::CAT:
      player1.use_cat();
      break;
    case boop::KITTEN:
      player1.use_kitten();
      break;
    default:
      std::cout << "tipo de pieza no compatible" << std::endl;
      return -1;
    }

    // add piece to board
    board.add_piece({row, col}, type_piece);

    game_manager.exchange_kittens_for_cats();

    // show board
    print();

    if (board.is_game_over())
      break;

    // player 2's turn
    std::cout << "player2, push your piece (piece, row, col): ";
    std::cin >> type_piece_char >> row >> col;
    std::cin.ignore();

    // get piece type
    type_piece = boop::char_to_type_piece(type_piece_char);

    switch (type_piece) {
    case boop::CAT:
      player2.use_cat();
      break;
    case boop::KITTEN:
      player2.use_kitten();
      break;
    default:
      std::cout << "topo de pieza no compatible" << std::endl;
      return -1;
    }

    // show board
    board.add_piece({row, col}, type_piece);

    game_manager.exchange_kittens_for_cats();

    if (board.is_game_over())
      break;
  }
  return 0;
}
