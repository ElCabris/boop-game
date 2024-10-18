#include <board.hpp>
#include <player.hpp>

namespace boop {
class GameManager {
private:
  Board &_board;
  Player &_player1;
  Player &_player2;

public:
  GameManager(Board &board, Player &player1, Player &player2);
};
} // namespace boop
