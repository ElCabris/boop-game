#include <graphics.hpp>

int main() {
  boop::Board board(3);

	boop::GBoard gboard(board);

	gboard.draw();
  return 0;
}
