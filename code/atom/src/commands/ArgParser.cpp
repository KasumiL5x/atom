#include "ArgParser.hpp"

namespace atom {
	ArgParser::ArgParser( std::string cmd ) {
		parse(cmd);
	}

	size_t ArgParser::count() const {
		return values_.size();
	}

	ArgType ArgParser::argType( unsigned int index ) const {
		return (index >= values_.size()) ? ArgType::Invalid : types_.at(index);
	}

	void ArgParser::parse( std::string& cmd ) {
		// make all lowercase
		//std::transform(std::begin(cmd), std::end(cmd), std::begin(cmd), ::tolower);
		// split the string by spaces
		atom::utils::splitString(cmd.data(), ' ', values_);
		// figure out datatypes
		for( size_t i = 0; i < values_.size(); ++i ) {
			ArgType type;
			const std::string& val = values_[i];
			if( atom::utils::isBool(val.data()) ) {
				type = ArgType::Bool;
			} else if( atom::utils::isInteger(val) ) {
				type = ArgType::Integer;
			} else if( atom::utils::isReal(val) ) {
				type = ArgType::Real;
			} else {
				type = ArgType::String;
			}
			types_[(int)i] = type;
		}
	}

	/**
	 * argValue implementation for std::string.
	 * Simply returns the raw value.
	 */
	template<>
	std::string ArgParser::argValue<std::string>( unsigned int index ) const {
		return values_[index];
	}

	/**
	 * argValue implementation for bool.
	 * Returns true for "true" and false for anything else.
	 */
	template<>
	bool ArgParser::argValue<bool>( unsigned int index ) const {
		return (strcmp("true", values_[index].data())==0) ? true : false;
	}

	/**
	 * argValue implementation for int.
	 * Converts using std::stoi.
	 */
	template<>
	int ArgParser::argValue<int>( unsigned int index ) const {
		return std::stoi(values_[index]);
	}

	/**
	 * argValue implementation for float.
	 * Converts using std::stof.
	 */
	template<>
	float ArgParser::argValue<float>( unsigned int index ) const {
		return std::stof(values_[index]);
	}
}