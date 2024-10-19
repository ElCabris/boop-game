#include <board.hpp>
#include <cassert>
#include <piece.hpp>
#include <stdexcept>
#include <string>

boop::Board::Board(const std::size_t &size) : _matrix(size) {}

boop::Node<boop::Piece> *boop::Board::get_piece(Position position) const {
  auto aux = _matrix.get_head();

  for (auto i = 0; i < position.row; i++) {
    if (aux->right == nullptr) {
      throw std::invalid_argument(std::to_string(position.row) + ", " +
                                  std::to_string(position.col) + "is no valid");
    }
    aux = aux->right;
  }

  for (auto i = 0; i < position.col; i++) {
    if (aux->down == nullptr) {
      throw std::invalid_argument(std::to_string(position.row) + ", " +
                                  std::to_string(position.col) + "is no valid");
    }
  }
  return aux;
}

void boop::Board::add_piece(Position &position, PieceType type) {
  auto aux = get_piece(position);

  if (aux->value.get_type() != EMPTY) {
    throw std::invalid_argument("box " + std::to_string(position.row) + ',' +
                                std::to_string(position.col) +
                                "is not available");
  }

  aux->value.set_type(type);
}

std::size_t boop::Board::get_size() const { return _matrix.get_size(); }

bool boop::Board::is_game_over() {
  for (int i = 0, size = static_cast<int>(get_size()) - 2; i < size; i++) {
    for (int j = 0; j < size; j++) {
      auto current = get_piece({i, j});

      if (current->value.get_type() == CAT) {

        // check horizontally
        if (current->value.get_type() == current->right->value.get_type() &&
            current->right->value.get_type() ==
                current->right->right->value.get_type() &&
            current->value.get_side() == current->right->value.get_side() &&
            current->right->value.get_side() ==
                current->right->right->value.get_side())
          return true;

        // check vertically
        if (current->value.get_side() == current->down->value.get_side() &&
            current->down->value.get_side() ==
                current->down->down->value.get_side() &&
            current->value.get_type() == current->down->value.get_type() &&
            current->down->value.get_type() ==
                current->down->down->value.get_type())
          return true;

        // check on the right diagonal
        if (current->value.get_type() ==
                current->down->right->value.get_type() &&
            current->down->right->value.get_type() ==
                current->down->down->right->right->value.get_type() &&
            current->value.get_side() ==
                current->down->right->value.get_side() &&
            current->down->right->value.get_side() ==
                current->down->down->right->right->value.get_side())
          return true;

        // check on the left diagonal
        if (j >= 2) {
          if (current->value.get_side() ==
                  current->down->left->value.get_side() &&
              current->down->left->value.get_side() ==
                  current->down->down->left->left->value.get_side() &&
              current->value.get_type() ==
                  current->down->left->value.get_type() &&
              current->down->down->left->left->value.get_type())
            return true;
        }
      }
    }
  }

  return false;
}

void boop::Board::delete_piece(const Position &position) {
  auto current = get_piece(position);

  if (current->value.get_type() == EMPTY)
    throw std::invalid_argument("You want to remove a piece from position " +
                                std::to_string(position.row) + ',' +
                                std::to_string(position.col) +
                                " but it is already empty");

  current->value.set_type(EMPTY);
}

void boop::Board::move_piece(const Position &from, const Position &to) {
  auto piece_from = get_piece(from);
  auto piece_to = get_piece(to);
  assert(piece_from->value.get_type() != EMPTY &&
         piece_to->value.get_type() == EMPTY);

  piece_to->value.set_type(piece_from->value.get_type());
  piece_from->value.set_type(EMPTY);
}

void boop::Board::move_adjacent_pieces(const Position &last_move) {
  auto current = get_piece(last_move);

  // right
  if (current->right != nullptr && current->right->value.get_type() != EMPTY &&
      current->right->value.get_type() <= current->value.get_type()) {
    if (current->right->right == nullptr)
      delete_piece({last_move.row, last_move.col + 1});
    else if (current->right->right->value.get_type() == EMPTY)
      move_piece({last_move.row, last_move.col + 1},
                 {last_move.row, last_move.col + 2});
  }

  // left
  if (current->left != nullptr && current->left->value.get_type() != EMPTY &&
      current->left->value.get_type() <= current->value.get_type()) {
    if (current->left->left == nullptr)
      delete_piece({last_move.row, last_move.col - 1});
    else if (current->left->left->value.get_type() == EMPTY)
      move_piece({last_move.row, last_move.col - 1},
                 {last_move.row, last_move.col - 2});
  }

  // up
  if (current->up != nullptr && current->up->value.get_type() != EMPTY &&
      current->up->value.get_type() <= current->value.get_type()) {
    if (current->up->up == nullptr)
      delete_piece({last_move.row - 1, last_move.col});
    else if (current->up->up->value.get_type() == EMPTY)
      move_piece({last_move.row - 1, last_move.col},
                 {last_move.row - 2, last_move.col});
  }

  // down
  if (current->down != nullptr && current->down->value.get_type() != EMPTY &&
      current->down->value.get_type() <= current->value.get_type()) {
    if (current->down->down == nullptr)
      delete_piece({last_move.row + 1, last_move.col});
    else if (current->down->down->value.get_type() == EMPTY)
      move_piece({last_move.row + 1, last_move.col},
                 {last_move.row + 2, last_move.col});
  }

  // up-right
  if (current->up != nullptr && current->up->right != nullptr &&
      current->up->right->value.get_type() != EMPTY &&
      current->up->right->value.get_type() <= current->value.get_type()) {
    if (current->up->right->up == nullptr ||
        current->up->right->right == nullptr)
      delete_piece({last_move.row - 1, last_move.col + 1});
    else if (current->up->right->up->value.get_type() == EMPTY ||
             current->up->right->right->value.get_type() == EMPTY)
      move_piece({last_move.row - 1, last_move.col + 1},
                 {last_move.row - 2, last_move.col + 2});
  }

  // up-left
  if (current->up != nullptr && current->up->left != nullptr &&
      current->up->left->value.get_type() != EMPTY &&
      current->up->left->value.get_type() <= current->value.get_type()) {
    if (current->up->left->up == nullptr || current->up->left->left == nullptr)
      delete_piece({last_move.row - 1, last_move.col - 1});
    else if (current->up->left->up->value.get_type() == EMPTY ||
             current->up->left->left->value.get_type() == EMPTY)
      move_piece({last_move.row - 1, last_move.col - 1},
                 {last_move.row - 2, last_move.col - 2});
  }

  // down-right
  if (current->down != nullptr && current->down->right != nullptr &&
      current->down->right->value.get_type() != EMPTY &&
      current->down->right->value.get_type() <= current->value.get_type()) {
    if (current->down->right->down == nullptr ||
        current->down->right->right == nullptr)
      delete_piece({last_move.row + 1, last_move.col + 1});
    else if (current->down->right->down->value.get_type() == EMPTY ||
             current->down->right->right->value.get_type() == EMPTY)
      move_piece({last_move.row + 1, last_move.col + 1},
                 {last_move.row + 2, last_move.col + 2});
  }

  // down-left
  if (current->down != nullptr && current->down->left != nullptr &&
      current->down->left->value.get_type() != EMPTY &&
      current->down->left->value.get_type() <= current->value.get_type()) {
    if (current->down->left->down == nullptr ||
        current->down->left->left == nullptr)
      delete_piece({last_move.row + 1, last_move.col - 1});
    else if (current->down->left->down->value.get_type() == EMPTY ||
             current->down->left->left->value.get_type() == EMPTY)
      move_piece({last_move.row + 1, last_move.col - 1},
                 {last_move.row + 2, last_move.col - 2});
  }
}
