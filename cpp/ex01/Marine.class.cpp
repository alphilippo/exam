#include <iostream>
#include "Marine.class.hpp"

Marine::Marine( void ) : Unit("Marine", 0, 0, 6, 40, 40) {

	std::cout << "Unit #" << _index << ": You want a piece of me, boy ?" << std::endl;
	return ;
}

Marine::Marine( int x, int y ) : Unit("Marine", x, y, 6, 40, 40) {

	std::cout << "Unit #" << _index << ": You want a piece of me, boy ?" << std::endl;
	return ;
}

Marine::Marine( Marine const & m) : Unit(m) {

	std::cout << "Unit #" << _index << ": You want a piece of me, boy ?" << std::endl;
	return ;
}

Marine::~Marine( void ) {

	return ;
}

void		Marine::die( void ) {

	if (_hpCur == 0)
		return ;
	Unit::die();
	std::cout << "Unit #" << _index << ": Aaaargh..." << std::endl;
	return ;
}

void		Marine::move( int x, int y ) {

	if (_hpCur == 0)
		return ;
	Unit::move(x, y);
	std::cout << "Unit #" << _index << ": Rock'n'roll !!!" << std::endl;
	return ;
}

void		Marine::stimpack( void ) {

	if (_hpCur == 0)
		return ;
	_hpCur -= 10;
	if (_hpCur <= 0)
		_hpCur = 1;
	_dmg *= 2;
	std::cout << "Unit #" << _index << ": Ho yeah..." << std::endl;
	return ;
}

Marine &		Marine::operator=(Marine const & m) {

	if (this != &m) {
		_type = m.getType();
		_x = m.getX();
		_y = m.getY();
		_dmg = m.getDam();
		_hpCur = m.getCHP();
		_hpMax = m.getMHP();
	}
	return *this;
}
