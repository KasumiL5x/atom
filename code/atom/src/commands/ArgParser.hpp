#ifndef __atom_arg_parser__
#define __atom_arg_parser__

#include <cstring>
#include <string>
#include <algorithm>
#include <regex>
#include <vector>
#include <map>
#include "../Utils.hpp"

namespace atom {
	/**
	 * Datatypes of parsed arguments.
	 */
	enum class ArgType {
		Invalid,
		String,  // std::string
		Bool,    // bool
		Integer, // int
		Real     // float
	};

	class ArgParser {
	public:
		ArgParser( std::string cmd );

		size_t count() const;

		ArgType argType( unsigned int index ) const;

		/**
		 * Gets the value of the argument at the given index.
		 * Note that only certain datatypes are supported and linking will fail if unsupported types are used.
		 * @param index Index of the desired argument.
		 * @returns Value of argument at the given index, treat as the specified type.  The user must ensure the datatype is correct using argType.
		 */
		template<typename T> T argValue( unsigned int index ) const;

	private:
		/**
		 * Splits the command by spaces and figures out the datatype of each split component.
		 * @param cmd Command string to parse.
		 */
		void parse( std::string& cmd );

	private:
		std::vector<std::string> values_; // all split values
		std::map<int, ArgType> types_; // maps values_ entries to their type
	};
}

#endif /* __atom_arg_parser__ */