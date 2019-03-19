#ifndef __atom_config_file__
#define __atom_config_file__

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

namespace atom {

class ConfigFile {
public:
	struct Section {
		std::unordered_map<std::string, std::string> entries; // key/value
	};

public:
	ConfigFile();
	~ConfigFile();

	bool readFromFile( const std::string& filename );
	bool readFromMemory( std::istringstream& str );
	void reset();
	const std::vector<std::string>& getComments() const;
	const std::vector<std::string>& getErrors() const;
	bool hasError() const;

	bool getVec3( const std::string& key, const std::string& section, float& outX, float& outY, float& outZ );
	bool getVec3( const std::string& key, float& outX, float& outY, float& outZ );
	bool getBool( const std::string& key, const std::string& section, bool& out );
	bool getBool( const std::string& key, bool& out );
	bool getFloat( const std::string& key, const std::string& section, float& out );
	bool getFloat( const std::string& key, float& out );
	bool getInt( const std::string& key, const std::string& section, int& out );
	bool getInt( const std::string& key, int& out );
	bool getString( const std::string& key, const std::string& section, std::string& out );
	bool getString( const std::string& key, std::string& out );


private:
	std::string makeStringValid( const std::string& str ) const;
	std::string formLineErrorStr() const;
	bool handleParseSection( const std::string& line );
	void handleParseKey( const std::string& line );
	bool getValue( const std::string& key, const std::string& section, std::string& out ) const;
	std::string findKeySection( const std::string& key );
	void stripComments( std::string& str );
	void stripPrefixedWhitespace( std::string& str );

private:
	std::unordered_map<std::string, Section> sections_;
	std::string currentSectionName_;
	std::vector<std::string> comments_;
	std::vector<std::string> errors_;
	int lineNumber_;
};

}

#endif