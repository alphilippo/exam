#ifndef MARINE_CLASS_HPP
# define MARINE_CLASS_HPP

# include "Unit.class.hpp"

class Marine : public Unit {

	public:
		Marine( void );
		Marine( int x, int y );
		Marine( Marine const & m);
		virtual ~Marine( void );

		Marine &	operator=(Marine const & m);
		void		die( void );
		void		move( int x, int y );
		void		stimpack( void );
};

#endif
