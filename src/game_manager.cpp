#include <game_manager.hpp>
#include <stdexcept>

boop::GameManager::GameManager(Board &board, Player &player1, Player &player2)
    : _board(board), _player1(player1), _player2(player2) {}

std::tuple<boop::Position, boop::Position, boop::Position>
boop::GameManager::get_three_kittens() {
  for (int i = 0, size = static_cast<int>(_board.get_size()) - 2; i < size;
       ++i) {
    for (int j = 0; j < size; ++j) {
      auto current = _board.get_piece({i, j});

      if (current->value.get_type() == KITTEN) {
        if (current->value.get_type() == current->right->value.get_type() &&
            current->right->value.get_type() ==
                current->right->right->value.get_type() &&
            current->value.get_side() == current->right->value.get_side() &&
            current->right->value.get_side() ==
                current->right->right->value.get_side())
          return std::tuple<Position, Position, Position>({i, j}, {i, j + 1},
                                                          {i, j + 2});

        if (current->value.get_type() == current->down->value.get_type() &&
            current->down->value.get_type() ==
                current->down->down->value.get_type() &&
            current->value.get_side() == current->down->value.get_side() &&
            current->down->value.get_side() ==
                current->down->down->value.get_side())
          return std::tuple<Position, Position, Position>({i, j}, {i, j},
                                                          {i, j});

        if (current->value.get_type() ==
                current->down->right->value.get_type() &&
            current->down->right->value.get_type() ==
                current->down->down->right->right->value.get_type() &&
            current->value.get_side() ==
                current->down->right->value.get_side() &&
            current->down->right->value.get_side() ==
                current->down->down->right->right->value.get_side())
          return std::tuple<Position, Position, Position>(
              {i, j}, {i + 1, j + 1}, {i + 2, j + 2});

        if (j >= 2) {
          if (current->value.get_type() ==
                  current->down->left->value.get_type() &&
              current->down->left->value.get_type() ==
                  current->down->down->left->left->value.get_type() &&
              current->value.get_side() ==
                  current->down->left->value.get_side() &&
              current->down->left->value.get_side() ==
                  current->down->down->left->left->value.get_side())
            return std::tuple<Position, Position, Position>(
                {i, j}, {i + 1, j - 1}, {i + 2, j - 2});
        }
      }
    }
  }
  throw std::runtime_error("no kittens were found lined up");
}

bool boop::GameManager::exchange_kittens_for_cats() {
  try {
    auto kittens = get_three_kittens();

    // Identify the player to whom the change is to be made
    Player *select_player;
    switch (_board.get_piece(std::get<0>(kittens))->value.get_side()) {
    case PLAYER1:
      select_player = &_player1;
      break;
    case PLAYER2:
      select_player = &_player2;
      break;
    default:
      select_player = nullptr;
    }

    // remove kittens
    _board.delete_piece(std::get<0>(kittens));
    _board.delete_piece(std::get<1>(kittens));
    _board.delete_piece(std::get<2>(kittens));

    // add cats to player
    for (auto i = 0; i < 3; i++) {
      select_player->add_cat();
    }

    return true;
  } catch (const std::runtime_error &e) {
    return false;
  }
}
