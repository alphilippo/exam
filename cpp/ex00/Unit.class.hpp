#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

# include <string>
# include <iostream>

class Unit {

	protected:
		int			_index;
		std::string	_type;
		int			_x;
		int			_y;
		int			_dmg;
		int			_hpCur;
		int			_hpMax;

	public:
		Unit( void );
		static int	_staticIndex;
		Unit( std::string type, int x, int y, int dmg, int hpCur, int hpMax );
		Unit( Unit const & u);
		~Unit( void );

		Unit &	operator=(Unit const & u);
		Unit &	operator+=(int i);
		Unit &	operator-=(int i);
	
		int						getIndex( void ) const;
		std::string	const &		getType( void ) const;
		int 					getX( void ) const;
		int 					getY( void ) const;
		int 					getDam( void ) const;
		int 					getCHP( void ) const;
		int 					getMHP( void ) const;

		void					die( void );
		void					move(int x, int y);
		void					attack( Unit & target ) const;

		static int		getStaticIndex( void );
};

std::ostream &		operator<<(std::ostream & o, Unit const & u);

#endif
