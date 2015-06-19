#include <iostream>
#include "Unit.class.hpp"

Unit::Unit( void ) : _index(Unit::getStaticIndex()), _type("Unit"), _x(0), _y(0), _dmg(0), _hpCur(0), _hpMax(0) {
	std::cout << "[CREATED] Unit #" << _index << ": " << _type << " in " << _x << "/" << _y << " with "
		<< _hpCur << "/" << _hpMax << "HP damaging at " << _dmg << "." << std::endl;
	_staticIndex++;
	return ;
}

Unit::Unit( std::string type, int x, int y, int dmg, int hpCur, int hpMax ) : _index(getStaticIndex()), _type(type), _x(x), _y(y), _dmg(dmg), _hpCur(hpCur), _hpMax(hpMax) {
	std::cout << "[CREATED] Unit #" << _index << ": " << _type << " in " << _x << "/" << _y << " with "
		<< _hpCur << "/" << _hpMax << "HP damaging at " << _dmg << "." << std::endl;
	_staticIndex++;
	return ;
}

Unit::Unit( Unit const & u ) {

	*this = u;
	this->_index = _staticIndex;
	std::cout << "[CREATED] Unit #" << _index << ": " << _type << " in " << _x << "/" << _y << " with "
		<< _hpCur << "/" << _hpMax << "HP damaging at " << _dmg << "." << std::endl;
	_staticIndex++;
	return ;
}

Unit::~Unit( void ) {

	std::cout << "[DESTRUCTED] Unit #" << _index << ": " << _type << " in " << _x << "/" << _y << " with "
		<< _hpCur << "/" << _hpMax << "HP damaging at " << _dmg << "." << std::endl;
	return ;
}

Unit &		Unit::operator=(Unit const & u) {

	if (this != &u) {
		_type = u.getType();
		_x = u.getX();
		_y = u.getY();
		_dmg = u.getDam();
		_hpCur = u.getCHP();
		_hpMax = u.getMHP();
	}
	return *this;
}

Unit &		Unit::operator+=(int i) {

	_hpCur += i;
	if (_hpCur > _hpMax)
		_hpCur = _hpMax;
	if (_hpCur <= 0)
		die();
	return *this;
}

Unit &		Unit::operator-=(int i) {

	_hpCur -= i;
	if (_hpCur > _hpMax)
		_hpCur = _hpMax;
	if (_hpCur <= 0)
		die();
	return *this;
}

int			Unit::getStaticIndex( void ) {

	return _staticIndex;
}

int			Unit::getIndex( void ) const {

	return _index;
}

std::string const &		Unit::getType( void ) const {

	return _type;
}

int			Unit::getX( void ) const {

	return _x;
}


int			Unit::getY( void ) const {

	return _y;
}


int			Unit::getDam( void ) const {

	return _dmg;
}

int			Unit::getCHP( void ) const {

	return _hpCur;
}

int			Unit::getMHP( void ) const {

	return _hpMax;
}

std::ostream &			operator<<(std::ostream & o, Unit const & u) {

	o << "Unit #" << u.getIndex() << ": " << u.getType() << " in " << u.getX() << "/" << u.getY()
		<< " with " << u.getCHP() << "/" << u.getMHP() << "HP damaging at " << u.getDam() << ".";
	return o;
}

void			Unit::die( void ) {

	if (_hpCur != 0)
		_hpCur = 0;
	std::cout << "Unit #" << _index << " (" << _type << ") died." << std::endl;
	
	return ;
}

void			Unit::move(int x, int y) {

	if (_hpCur == 0)
		return ;
	std::cout << "Unit #" << _index << " (" << _type << ") is moving from " << _x << "/" << _y << " to "
		<< x << "/" << y << "." << std::endl;
	_x = x;
	_y = y;
	return ;
}

void			Unit::attack( Unit & target ) const {

	if (_hpCur == 0)
		return ;
	std::cout << "Unit #" << _index << " (" << _type << ") damaged unit #" << target.getIndex()
		<< " (" << target.getType() << ")." << std::endl;
	target -= _dmg;
	return ;
}


int Unit::_staticIndex = 0;
