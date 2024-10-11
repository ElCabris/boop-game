#ifndef PIECE_HPP 
#define PIECE_HPP
namespace boop {
	enum PieceType {
		EMPTY,
		CAT,
		KITTEN	
	};

	class Piece {
	private:
		PieceType _type;
	public:
		Piece();
		PieceType get_type() const;
		void set_type(const PieceType& type);
	};
}
#endif
