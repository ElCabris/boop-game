#include <board.hpp>
#include <player.hpp>

namespace boop {
class GameManager {
private:
  Board &_board;
  Player &_player;

public:
  GameManager(Board &board, Player &player);
};
} // namespace boop
