#ifndef __atom_UnwatchCmd__
#define __atom_UnwatchCmd__

#include "ICommandEater.hpp"

namespace atom {

	class UnwatchCmd : public ICommandEater {
	public:
		UnwatchCmd();
		virtual ~UnwatchCmd();

		virtual bool consume( const ArgParser& parser, std::shared_ptr<atom::Connection> connection, std::shared_ptr<dag::AtomDag> adag ) override;
	};

}

#endif