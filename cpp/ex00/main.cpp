#include "Unit.class.hpp"

int main( void ) {
	Unit    u0;
	Unit    u1("Marine",
	       13, 45,
	       6,
	       40, 40);
	Unit    u2( u1 );
	u0 = u1;

	std::cout << "Index: " << u0.getIndex() << std::endl;
	std::cout << "Type: "<< u0.getType() << std::endl;
	std::cout <<"X: "<< u0.getX() << std::endl;
	std::cout <<"Y: "<< u0.getY() << std::endl;
	std::cout << "Damage: "<< u0.getDam() << std::endl;
	std::cout << "Current HP: " << u0.getCHP() << std::endl;
	std::cout << "Maximum HP: " << u0.getMHP() << std::endl;

	std::cout << u0 << std::endl;
	std::cout << u1 << std::endl;
	std::cout << u2 << std::endl;

	u2.die();
	u0.move( 12, 45 );
	u1.move( 14, 45 );
	while ( u0.getCHP() > 0 && u1.getCHP() > 0 ) {
		u0.attack( u1 );
		u1.attack( u0 );
	}
	return 0;
}