#include "ConfigFile.hpp"
#include <fstream>
#include <algorithm>

using namespace atom;

ConfigFile::ConfigFile() : currentSectionName_("") {
}

ConfigFile::~ConfigFile() {
}

bool ConfigFile::readFromFile( const std::string& filename ) {
	std::ifstream in(filename, std::ios::in);
	if( !in.is_open() ) {
		return false;
	}

	reset();

	// create and add a default section, then set the current section idx to it
	sections_["default"] = Section();
	currentSectionName_ = "default";

	while( !in.eof() ) {
		std::string currentLine;
		std::getline(in, currentLine);

		lineNumber_++;
		// check for empty line
		if( currentLine.empty() ) {
			continue;
		}
		// remove all prefixed whitespace
		stripPrefixedWhitespace(currentLine);
		// remove comments from the line (includes parsing comment lines)
		stripComments(currentLine);
		if( currentLine.empty() ) { // stripping comment-only lines become empty
			continue;
		}
		// handle sections
		if( handleParseSection(currentLine) ) {
			continue;
		}
		// handle remaining option of key-value combos
		handleParseKey(currentLine);
	}

	in.close();

	return true;
}

bool ConfigFile::readFromMemory( std::istringstream& str ) {
	if( str.str().empty() ) {
		return false;
	}

	reset();

	std::string currentLine;
	while( std::getline(str, currentLine) ) {
		lineNumber_++;
		if( currentLine.empty() ) {
			continue;
		}
		stripPrefixedWhitespace(currentLine);
		stripComments(currentLine);
		if( currentLine.empty() ) {
			continue;
		}
		if( handleParseSection(currentLine) ) {
			continue;
		}
		handleParseKey(currentLine);
	}
	return true;
}

void ConfigFile::reset() {
	sections_.clear();
	currentSectionName_ = "";
	comments_.clear();
	errors_.clear();
	lineNumber_ = 0;
}

const std::vector<std::string>& ConfigFile::getComments() const {
	return comments_;
}

const std::vector<std::string>& ConfigFile::getErrors() const {
	return errors_;
}

bool ConfigFile::hasError() const {
	return !errors_.empty();
}

bool ConfigFile::getVec3( const std::string& key, const std::string& section, float& outX, float& outY, float& outZ ) {
	std::string value = "";
	if( !getValue(key, section, value) ) {
		return false;
	}

	// format: x,y,z
	
	// check minimum characters
	if( value.size() < 5 ) { // x,y,z = 5 characters minimum
		return false;
	}

	// find first comma
	const size_t firstCommaIndex = value.find(',');
	if( std::string::npos == firstCommaIndex ) {
		return false;
	}
	// ensure characters exist before the first comma
	if( 0 == firstCommaIndex ) {
		return false;
	}
	// ensure characters exist after the comma
	if( firstCommaIndex+1 >= value.length() ) {
		return false;
	}
	// find second comma
	const size_t secondCommaIndex = value.find(',', firstCommaIndex+1);
	if( std::string::npos == secondCommaIndex ) {
		return false;
	}
	// ensure content between the commas
	if( secondCommaIndex - firstCommaIndex == 1 ) {
		return false;
	}
	// ensure characters exist after the comma
	if( secondCommaIndex+1 >= value.length() ) {
		return false;
	}
	// ensure character after second comma is not another comma
	if( ',' == value[secondCommaIndex+1] ) {
		return false;
	}
	// get the three value strings
	const std::string strX = value.substr(0, firstCommaIndex);
	const std::string strY = value.substr(firstCommaIndex+1, secondCommaIndex-firstCommaIndex-1);
	const std::string strZ = value.substr(secondCommaIndex+1, value.length()-secondCommaIndex-1);

	outX = static_cast<float>(std::atof(strX.c_str()));
	outY = static_cast<float>(std::atof(strY.c_str()));
	outZ = static_cast<float>(std::atof(strZ.c_str()));

	return true;
}

bool ConfigFile::getVec3( const std::string& key, float& outX, float& outY, float& outZ ) {
	return getVec3(key, findKeySection(key), outX, outY, outZ);
}

bool ConfigFile::getBool( const std::string& key, const std::string& section, bool& out ) {
	std::string value = "";
	if( !getValue(key, section, value) ) {
		return false;
	}

	if( strcmp(value.c_str(), "true")==0 || strcmp(value.c_str(), "yes")==0 || strcmp(value.c_str(), "1")==0 ) {
		out = true;
		return true;
	}
	out = false;
	return true; // assumes anything except true/yes/1 is false
}

bool ConfigFile::getBool( const std::string& key, bool& out ) {
	return getBool(key, findKeySection(key), out);
}

bool ConfigFile::getFloat( const std::string& key, const std::string& section, float& out ) {
	std::string value = "";
	if( !getValue(key, section, value) ) {
		return false;
	}

	out = static_cast<float>(std::atof(value.c_str()));
	return true;
}

bool ConfigFile::getFloat( const std::string& key, float& out ) {
	return getFloat(key, findKeySection(key), out);
}

bool ConfigFile::getInt( const std::string& key, const std::string& section, int& out ) {
	std::string value = "";
	if( !getValue(key, section, value) ) {
		return false;
	}

	out = static_cast<int>(std::atoi(value.c_str()));
	return true;
}

bool ConfigFile::getInt( const std::string& key, int& out ) {
	return getInt(key, findKeySection(key), out);
}

bool ConfigFile::getString( const std::string& key, const std::string& section, std::string& out ) {
	std::string value = "";
	if( !getValue(key, section, value) ) {
		return false;
	}

	out = value;
	return true;
}

bool ConfigFile::getString( const std::string& key, std::string& out ) {
	return getString(key, findKeySection(key), out);
}

std::string ConfigFile::makeStringValid( const std::string& str ) const {
	std::string result = str;
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}

std::string ConfigFile::formLineErrorStr() const {
	return "Line " + std::to_string(lineNumber_);
}

//bool ConfigFile::handleParseComment( const std::string& line ) {
//	// process lines starting with ';' as a comment
//	if( ';' == line[0] ) {
//		if( line.size() > 1 ) {
//			comments_.push_back(line.substr(1, line.size()-1));
//		}
//		return true;
//	}
//
//	return false;
//}

bool ConfigFile::handleParseSection( const std::string& line ) {
	// starting with '[' and ending with ']' defines a section

	const bool hasOpening = line.find('[') != std::string::npos;
	const bool hasClosing = line.find(']') != std::string::npos;

	// not a section
	if( !hasOpening && !hasClosing ) {
		return false;
	}
	// has only opening brace
	if( hasOpening && !hasClosing ) {
		errors_.push_back(formLineErrorStr() + ": Section is missing closing ].");
		return true;
	}
	// has only closing brace
	if( !hasOpening && hasClosing ) {
		errors_.push_back(formLineErrorStr() + ": Section is missing opening [.");
		return true;
	}

	// ensure the opening bracket is in the first position
	if( '[' != line[0] ) {
		errors_.push_back(formLineErrorStr() + ": Section defined but misplaced opening [.");
		return true;
	}

	// ensure the closing bracket is in the last position
	if( ']' != line[line.size()-1] ) {
		errors_.push_back(formLineErrorStr() + ": Section defined but misplaced closing ].");
		return true;
	}

	// handle bad size (less than 3 characters means no name in between [])
	if( line.size() < 3 ) {
		errors_.push_back(formLineErrorStr() + ": Section definition has no name.");
		return true;
	}

	// validate section name
	std::string sectionName = makeStringValid(line.substr(1, line.size()-2));
	if( sectionName.empty() ) { // stripping all whitespace could result in an emptry str
		errors_.push_back(formLineErrorStr() + ": Section defined but name was empty.");
		return true;
	}			

	// create a new section and update the current section index
	sections_[sectionName] = Section();
	currentSectionName_ = sectionName;
	return true;
}

void ConfigFile::handleParseKey( const std::string& line ) {
	// line must be at least three characters, e.g. a=b
	if( line.size() < 3 ) {
		errors_.push_back(formLineErrorStr() + ": Key/value syntax error; too short.");
		return;
	}

	// find the splitting '='
	const size_t equalsPos = line.rfind('=');
	if( equalsPos == std::string::npos ) {
		errors_.push_back(formLineErrorStr() + ": Key/value missing =.");
		return;
	}

	// if the equals is at the beginning, there's no key
	if( 0 == equalsPos ) {
		errors_.push_back(formLineErrorStr() + ": Key/value missing key.");
		return;
	}

	// check a value exists after the =
	const size_t sizeAfterEquals = line.size() - equalsPos - 1;
	if( 0 == sizeAfterEquals ) {
		errors_.push_back(formLineErrorStr() + ": Key/value missing value.");
		return;
	}

	// get the key/value strings
	std::string key = makeStringValid(line.substr(0, equalsPos));
	std::string value = makeStringValid(line.substr(equalsPos+1, sizeAfterEquals));

	// validate key/value strings
	if( key.empty() ) {
		errors_.push_back(formLineErrorStr() + ": Key/value invalid key.");
		return;
	}
	if( value.empty() ) {
		errors_.push_back(formLineErrorStr() + ": Key/value invalid value.");
		return;
	}

	// add key/value to the current section
	sections_[currentSectionName_].entries[key] = value;
}

bool ConfigFile::getValue( const std::string& key, const std::string& section, std::string& out ) const {
	// make valid key/section
	std::string validKey = makeStringValid(key);
	std::string validSection = makeStringValid(section);

	// get the section
	const auto theSection = sections_.find(validSection);
	if( sections_.end() == theSection ) {
		return false;
	}

	// find entry
	const auto theKey = theSection->second.entries.find(validKey);
	if( theSection->second.entries.end() == theKey ) {
		return false;
	}

	// output value
	out = theKey->second;

	return true;
}

std::string ConfigFile::findKeySection( const std::string& key ) {
	for( auto& section : sections_ ) {
		if( section.second.entries.find(key) != section.second.entries.end() ) {
			return section.first;
		}
	}

	return "";
}

void ConfigFile::stripComments( std::string& str ) {
	const size_t firstSemicolon = str.find(';');
	if( std::string::npos == firstSemicolon ) {
		return;
	}

	// extract comment
	const std::string comment = str.substr(firstSemicolon+1, str.length()-firstSemicolon);
	if( !comment.empty() ) {
		comments_.push_back(comment);
	}

	// erase all from ; onward inclusive
	str.erase(firstSemicolon, str.length()-firstSemicolon);
}

void ConfigFile::stripPrefixedWhitespace( std::string& str ) {
	const size_t index = str.find_first_not_of(' ');
	if( std::string::npos == index || 0 == index ) {
		return;
	}
	str.erase(0, index);
}