#include <player.hpp>

boop::Player::Player(std::size_t initial_number_chips, Side side)
    : _side(side), _max_number_pieces(initial_number_chips) {
  _pieces.assign(initial_number_chips, Piece(KITTEN, side));
}

boop::Side boop::Player::get_side() const { return _side; }

std::vector<boop::Piece> boop::Player::get_pieces() const { return _pieces; }

std::size_t boop::Player::get_max_number_pieces() const {
  return _max_number_pieces;
}

bool boop::Player::use_cat() {
  for (int i = 0, size = _pieces.size(); i < size; i++) {
    if (_pieces[i].get_type() == CAT) {
      _pieces.erase(_pieces.begin() + i);
      return true;
    }
  }
  return false;
}

bool boop::Player::use_kitten() {
  for (int i = 0, size = _pieces.size(); i < size; i++) {
    if (_pieces[i].get_type() == KITTEN) {
      _pieces.erase(_pieces.begin() + i);
      return true;
    }
  }
  return false;
}

bool boop::Player::add_kitten() {
  if (_pieces.size() < _max_number_pieces) {
    _pieces.push_back(Piece(KITTEN, _side));
    return true;
  }
  return false;
}

bool boop::Player::add_cat() {
  if (_pieces.size() < _max_number_pieces) {
    _pieces.push_back(Piece(CAT, _side));
    return true;
  }
  return false;
}
