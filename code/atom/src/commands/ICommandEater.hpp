#ifndef __atom_icommandeater__
#define __atom_icommandeater__

#include <memory>
#include "ArgParser.hpp"
#include "../server/Connection.hpp"
#include "../AtomDag/AtomDag.hpp"

namespace atom {
	class ICommandEater {
	public:
		ICommandEater() {
		}
		virtual ~ICommandEater() {
		}

		/**
		 * Derived classes should decide whether to consume the command.  Return true if the command was consumed, or false if not.
		 * @param parser     Input arguments of the command.
		 * @param connection Connection that sent the command. Send responses to this connection.
		 * @param adag       ADag for getting scene data.
		 * @returns True if the command was consumed; false otherwise.
		 */
		virtual bool consume( const ArgParser& parser, std::shared_ptr<atom::Connection> connection, std::shared_ptr<dag::AtomDag> adag )=0;
	};
}

#endif /* __atom_icommandeater__ */