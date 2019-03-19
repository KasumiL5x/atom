#ifndef __atom_utils__
#define __atom_utils__

#include <sstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <regex>
#include <array>

namespace atom { namespace utils {

/**
 * Encodes an integer into four bytes.
 * @param val Integer to encode.
 * @returns std::array of the four encoded bytes.
 */
static std::array<unsigned char, 4> encodeHeader( int32_t val ) {
	std::array<unsigned char, 4> header;
	//header[0] = (val >> 24) & 0xFF;
	//header[1] = (val >> 16) & 0xFF;
	//header[2] = (val >> 8) & 0xFF;
	//header[3] = (val & 0xFF);

	header[3] = (val >> 24) & 0xFF;
	header[2] = (val >> 16) & 0xFF;
	header[1] = (val >> 8) & 0xFF;
	header[0] = (val & 0xFF);

	return header;
}

/**
 * Decodes an encoded integer from bytes.
 * @param data std::array of four bytes making up the encoded integer.
 * @returns Decoded integer.
 */
static int32_t decodeHeader( const std::array<unsigned char, 4>& data ) {
	//return (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	return (data[3] << 24) | (data[2] << 16) | (data[1] << 8) | data[0];
}

/**
	* Converts an integer to a hexidecimal string with an optional 0x prefix.
	* @param i      Integer to convert.
	* @param prefix If true, prefixes the string with 0x.
	* @returns Hexidecimal string representing the given integer.
	*/
template<typename T>
static std::string int_to_hex( T i, bool prefix ) {
	std::stringstream ss;
	if( prefix ) {
		ss << "0x";
	}
	ss << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << i;
	return ss.str();
}

/** 
	* Splits a string by a delimiter into a vector.
	* @param str     Null terminated string to split.
	* @param delim   Delimiter character to split by.
	* @pararm outVec Vector to populate with resulting splits.
	* @returns outVec for convenience.
	*/
static std::vector<std::string>& splitString( const char* str, char delim, std::vector<std::string>& outVec ) {
	do {
		const char* begin = str;
		while( *str != delim && *str ) {
			str++;
		}
		outVec.emplace_back(begin, str);
	} while( 0 != *str++ );
	return outVec;
}

/**
	* Checks if a given string is a bool.  "true" and "false" are assumed.
	* @param str Null-terminated string to check.
	* @return True if "true" or "false" are found; false otherwise.
	*/
static bool isBool( const char* str ) {
	return (strcmp("true", str)==0 || strcmp("false", str)==0);
}

/**
	* Checks if a given string is an integer.
	* @param str String to check.
	* @returns True if the string is a whole integer, even negative.
	*/
static bool isInteger( const std::string& str ) {
	const std::regex expr("^-?[0-9]\\d*$");
	return std::regex_match(str, expr);
}

/**
	* Checks if a given string is a real.
	* @param str String to check.
	* @returns True if the string is a decimal, even negative.
	*/
static bool isReal( const std::string& str ) {
	const std::regex expr("^-?[0-9]\\d*(\\.\\d+)$");
	return std::regex_match(str, expr);
}
	
}
}

#endif /* __atom_utils__ */