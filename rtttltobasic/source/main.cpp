#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <fstream>
#include <sstream>

class Note {
public:
	static uint16_t const PICAXE_PITCH_C;
	static uint16_t const PICAXE_PITCH_CS;
	static uint16_t const PICAXE_PITCH_D;
	static uint16_t const PICAXE_PITCH_DS;
	static uint16_t const PICAXE_PITCH_E;
	static uint16_t const PICAXE_PITCH_F;
	static uint16_t const PICAXE_PITCH_FS;
	static uint16_t const PICAXE_PITCH_G;
	static uint16_t const PICAXE_PITCH_GS;
	static uint16_t const PICAXE_PITCH_A;
	static uint16_t const PICAXE_PITCH_AS;
	static uint16_t const PICAXE_PITCH_B;
	static uint16_t const PICAXE_PITCH_P;
	static uint16_t const PICAXE_OCTAVE_5;
	static uint16_t const PICAXE_OCTAVE_6;
	static uint16_t const PICAXE_OCTAVE_7;
	static uint16_t const PICAXE_DURATION_CROTCHET;
	static uint16_t const PICAXE_DURATION_QUAVER;
	static uint16_t const PICAXE_DURATION_SEMIBREVE;
	static uint16_t const PICAXE_DURATION_MINUM;
	static uint16_t const PICAXE_SPEED[15];

	static uint16_t PICAXE_OCTAVE_DEFAULT;
	static uint16_t PICAXE_DURATION_DEFAULT;
	static uint16_t PICAXE_SPEED_DEFAULT;

	uint16_t note_duration;
	uint16_t note_pitch;
	uint16_t note_octave;
	
	static std::string songName;

	static std::string lookup_pitch_rtttl(uint16_t picaxe);
	static std::string lookup_octave_rtttl(uint16_t picaxe, uint16_t autoDefault = 1);
	static std::string lookup_duration_rtttl(uint16_t picaxe, uint16_t autoDefault = 1);
	static uint16_t lookup_pitch_picaxe(std::string rtttl);
	static uint16_t lookup_octave_picaxe(std::string rtttl);
	static uint16_t lookup_duration_picaxe(std::string rtttl);
	static uint16_t lookup_speed_picaxe(std::string rtttl);

	static std::string get_metaData_rtttl();
	static std::string get_metaData_picaxe();
	std::string get_picaxeNote();
	std::string get_rtttlNote();
	static void set_metaData_rtttl(std::string metaData);
	static void set_metaData_picaxe(std::string metaData);
	void set_picaxeNote(std::string note);
	void set_rtttlNote(std::string note);

	Note();
};

uint16_t const Note::PICAXE_PITCH_C = 0x0;
uint16_t const Note::PICAXE_PITCH_CS = 0x1;
uint16_t const Note::PICAXE_PITCH_D = 0x2;
uint16_t const Note::PICAXE_PITCH_DS = 0x3;
uint16_t const Note::PICAXE_PITCH_E = 0x4;
uint16_t const Note::PICAXE_PITCH_F = 0x5;
uint16_t const Note::PICAXE_PITCH_FS = 0x6;
uint16_t const Note::PICAXE_PITCH_G = 0x7;
uint16_t const Note::PICAXE_PITCH_GS = 0x8;
uint16_t const Note::PICAXE_PITCH_A = 0x9;
uint16_t const Note::PICAXE_PITCH_AS = 0xA;
uint16_t const Note::PICAXE_PITCH_B = 0xB;
uint16_t const Note::PICAXE_PITCH_P = 0xF;
uint16_t const Note::PICAXE_OCTAVE_5 = 0x2;
uint16_t const Note::PICAXE_OCTAVE_6 = 0x0;
uint16_t const Note::PICAXE_OCTAVE_7 = 0x1;
uint16_t const Note::PICAXE_DURATION_CROTCHET = 0x0;
uint16_t const Note::PICAXE_DURATION_QUAVER = 0x1;
uint16_t const Note::PICAXE_DURATION_SEMIBREVE = 0x2;
uint16_t const Note::PICAXE_DURATION_MINUM = 0x3;
uint16_t const Note::PICAXE_SPEED[15] = { 812,406,270,203,162,135,116,101,90,81,73,67,62,58,54 };
uint16_t Note::PICAXE_OCTAVE_DEFAULT = 0x0;		//PICAXE_OCTAVE_6
uint16_t Note::PICAXE_DURATION_DEFAULT = 0x0;	//PICAXE_DURATION_CROTCHET
uint16_t Note::PICAXE_SPEED_DEFAULT = 7;			//PICAXE_SPEED_8
std::string Note::songName = "untitled";

//TODO: Make it so that we can have if(picaxe == default) return("");
std::string Note::lookup_pitch_rtttl(uint16_t picaxe) {
	switch (picaxe) {
	case(PICAXE_PITCH_C) :
		return("c");
		break;
	case(PICAXE_PITCH_CS) :
		return("c#");
		break;
	case(PICAXE_PITCH_D) :
		return("d");
		break;
	case(PICAXE_PITCH_DS) :
		return("d#");
		break;
	case(PICAXE_PITCH_E) :
		return("e");
		break;
	case(PICAXE_PITCH_F) :
		return("f");
		break;
	case(PICAXE_PITCH_FS) :
		return("f#");
		break;
	case(PICAXE_PITCH_G) :
		return("g");
		break;
	case(PICAXE_PITCH_GS) :
		return("g#");
		break;
	case(PICAXE_PITCH_A) :
		return("a");
		break;
	case(PICAXE_PITCH_AS) :
		return("a#");
		break;
	case(PICAXE_PITCH_B) :
		return("b");
		break;
	case(PICAXE_PITCH_P) :
		return("p");
	default:
		break;
	}
	return("p");
}

std::string Note::lookup_octave_rtttl(uint16_t picaxe,uint16_t autoDefault) {
	switch (picaxe) {
	case(PICAXE_OCTAVE_5) :
		if ((autoDefault) && (PICAXE_OCTAVE_5 == PICAXE_OCTAVE_DEFAULT)) break;
		return("5");
		break;
	case(PICAXE_OCTAVE_6) :
		if ((autoDefault) && (PICAXE_OCTAVE_6 == PICAXE_OCTAVE_DEFAULT)) break;
		return("6");
		break;
	case(PICAXE_OCTAVE_7) :
		if ((autoDefault) && (PICAXE_OCTAVE_7 == PICAXE_OCTAVE_DEFAULT)) break;
		return("7");
		break;
	default:
		break;
	}
	return("");
}

std::string Note::lookup_duration_rtttl(uint16_t picaxe, uint16_t autoDefault) {
	switch (picaxe) {
	case(PICAXE_DURATION_CROTCHET) :
		if ((autoDefault) && (PICAXE_DURATION_CROTCHET == PICAXE_DURATION_DEFAULT)) break;
		return("4");
		break;
	case(PICAXE_DURATION_QUAVER) :
		if ((autoDefault) && (PICAXE_DURATION_QUAVER == PICAXE_DURATION_DEFAULT)) break;
		return("8");
		break;
	case(PICAXE_DURATION_SEMIBREVE) :
		if ((autoDefault) && (PICAXE_DURATION_SEMIBREVE == PICAXE_DURATION_DEFAULT)) break;
		return("1");
		break;
	case(PICAXE_DURATION_MINUM) :
		if ((autoDefault) && (PICAXE_DURATION_MINUM == PICAXE_DURATION_DEFAULT)) break;
		return("2");
		break;
	default:
		break;
	}
	return("");
}

uint16_t Note::lookup_pitch_picaxe(std::string rtttl) {
	if (rtttl == "c") return(PICAXE_PITCH_C);
	if (rtttl == "c#") return(PICAXE_PITCH_CS);
	if (rtttl == "d") return(PICAXE_PITCH_D);
	if (rtttl == "d#") return(PICAXE_PITCH_DS);
	if (rtttl == "e") return(PICAXE_PITCH_E);
	if (rtttl == "f") return(PICAXE_PITCH_F);
	if (rtttl == "f#") return(PICAXE_PITCH_FS);
	if (rtttl == "g") return(PICAXE_PITCH_G);
	if (rtttl == "g#") return(PICAXE_PITCH_GS);
	if (rtttl == "a") return(PICAXE_PITCH_A);
	if (rtttl == "a#") return(PICAXE_PITCH_AS);
	if (rtttl == "b") return(PICAXE_PITCH_B);
	return(PICAXE_PITCH_P);
}

uint16_t Note::lookup_octave_picaxe(std::string rtttl) {
	if (rtttl == "5") return(PICAXE_OCTAVE_5);
	if (rtttl == "6") return(PICAXE_OCTAVE_6);
	if (rtttl == "7") return(PICAXE_OCTAVE_7);
	return(PICAXE_OCTAVE_DEFAULT);
}

uint16_t Note::lookup_duration_picaxe(std::string rtttl) {
	if (rtttl == "4") return(PICAXE_DURATION_CROTCHET);
	if (rtttl == "8") return(PICAXE_DURATION_QUAVER);
	if (rtttl == "1") return(PICAXE_DURATION_SEMIBREVE);
	if (rtttl == "2") return(PICAXE_DURATION_MINUM);
	return(PICAXE_DURATION_DEFAULT);
}

uint16_t Note::lookup_speed_picaxe(std::string rtttl) {
	std::stringstream stream;
	stream << rtttl;
	stream.flags(std::ios_base::dec);
	uint16_t tmpInt;
	stream >> tmpInt;
	for (uint16_t i = 0; i < 15; i++) {
		if (tmpInt == PICAXE_SPEED[i]) {
			return(i);
			break;
		}
	}
	return(PICAXE_SPEED_DEFAULT);
}

std::string Note::get_metaData_rtttl () {
	std::stringstream stream;
	stream << PICAXE_SPEED[PICAXE_SPEED_DEFAULT];
	return(songName + ":" + "d=" + lookup_duration_rtttl(PICAXE_DURATION_DEFAULT,0) + ",o=" + lookup_octave_rtttl(PICAXE_OCTAVE_DEFAULT,0) + ",b=" + stream.str()+":");
}

std::string Note::get_metaData_picaxe() {
	std::stringstream stream;
	stream << PICAXE_SPEED_DEFAULT+1;
	return(";" + songName + "\n" + "tune ," + stream.str() + ",");
}

std::string Note::get_picaxeNote() {
	uint16_t byte = (note_pitch & 0x000f) | ((note_octave & 0x0003) << 4) | ((note_duration & 0x0003) << 6);
	std::stringstream stream;
	stream << "$" << std::hex << byte;
	return (stream.str());
}

std::string Note::get_rtttlNote() {
	return(lookup_duration_rtttl(note_duration)+lookup_pitch_rtttl(note_pitch)+lookup_octave_rtttl(note_octave));
}

//TODO: Rewrite using std::string find
void Note::set_metaData_rtttl(std::string metaData) {
	uint32_t offset = 0;
	songName.clear();
	for (uint32_t i = 0; i < metaData.length(); i++) {
		if (metaData[i] == ':') {
			offset = i+1;
			break;
		}
		songName.append(metaData,i,1);
	}
	metaData.erase(metaData.begin(), metaData.begin() + offset);
	for (uint32_t i = 0; i < metaData.length(); i++) {
		if (metaData[i] == 'd') {
			i+=2;	//Should be 'd='
			std::string tmpStr;
			for (tmpStr.clear(); i < metaData.length(); i++) {	//TODO: Make this a lambda expresssion
				if (metaData[i] == ',') {
					break;
				}
				tmpStr.append(metaData, i, 1);
			}
			PICAXE_DURATION_DEFAULT = lookup_duration_picaxe(tmpStr);
		}
		else if (metaData[i] == 'o') {
			i += 2;	//Should be 'o='
			std::string tmpStr;
			for (tmpStr.clear(); i < metaData.length(); i++) {	//TODO: Make this a lambda expresssion
				if (metaData[i] == ',') {
					break;
				}
				tmpStr.append(metaData, i, 1);
			}
			PICAXE_OCTAVE_DEFAULT = lookup_octave_picaxe(tmpStr);
		}
		else if (metaData[i] == 'b') {
			i += 2;	//Should be 'b='
			std::string tmpStr;
			for (tmpStr.clear(); i < metaData.length(); i++) {	//TODO: Make this a lambda expresssion
				if (metaData[i] == ',') {
					break;
				}
				tmpStr.append(metaData, i, 1);
			}
			
			PICAXE_SPEED_DEFAULT = lookup_speed_picaxe(tmpStr);
		}
		else if (metaData[i] == ':') {
			break;
		}
	}
}

void Note::set_metaData_picaxe(std::string metaData) {
	uint32_t pos;
	uint32_t pos1;
	pos = metaData.find_first_of("\n");
	if (pos != std::string::npos) {
		songName = metaData.substr(1, pos - 1);
		metaData.erase(metaData.begin(), metaData.begin() + pos);
	}
	pos = metaData.find_last_of(",");
	if (pos != std::string::npos) {
		pos1 = metaData.find_last_of(",", pos - 1);
		std::string tmpStr = metaData.substr(pos1+1, (pos-pos1)-1);
		while (tmpStr.find(" ") != std::string::npos) {
			tmpStr.erase(tmpStr.begin() + tmpStr.find(" "));
		}
		std::stringstream stream;
		stream << tmpStr;
		uint16_t tmpInt;
		stream >> tmpInt;
		PICAXE_SPEED_DEFAULT = tmpInt-1;
	}
	else {
		PICAXE_SPEED_DEFAULT = 7;
	}
	PICAXE_DURATION_DEFAULT = 0x00;
	PICAXE_OCTAVE_DEFAULT = 0x00;
}

void Note::set_picaxeNote(std::string note) {
	if(note[0] == '$') note.erase(note.begin());
	std::stringstream stream;
	stream << note;
	uint16_t byte;	//Wont work with uint8... Darn it.
	stream.flags(std::ios_base::hex);
	stream >> byte;
	note_pitch = byte & 0x000f;
	note_octave = (byte & 0x0030) >> 4;
	note_duration = (byte & 0x00c0) >> 6;
}

//TODO: Rewrite this bit for error checking
void Note::set_rtttlNote(std::string note) {
	uint16_t contains_duration = 0;
	uint16_t contains_sharp = 0;
	uint16_t contains_octave = 0;
	uint16_t contains_dot = 0;
	uint16_t offset = 0;
	{
		if (note.length()-offset > 0) {
			if (((uint16_t)note[offset]) - 0x30 < 10) {
				contains_duration = 1;
				offset++;
			}
		}
		offset++;		//Note has to be here
		if (note.length() - offset > 0) {
			if (note[offset] == '#') {
				contains_sharp = 1;
				offset++;
			}
		}
		if (note.length() - offset > 0) {
			if (((uint16_t)note[offset]) - 0x30 < 10) {
				contains_octave = 1;
				offset++;
			}
		}
		if (note.length() - offset > 0) {
			if (note[offset] == '.') {
				contains_dot = 1;
				offset++;
			}
		}
	}
	if (contains_duration) note_duration = lookup_duration_picaxe(note.substr(0, 1));
	else note_duration = PICAXE_DURATION_DEFAULT;
	note_pitch = lookup_pitch_picaxe(note.substr(0 + contains_duration, 1 + contains_sharp));
	if (contains_octave) note_octave = lookup_octave_picaxe(note.substr(1 + contains_duration + contains_sharp,1));
	else note_octave = PICAXE_OCTAVE_DEFAULT;
}

Note::Note() : note_duration(PICAXE_DURATION_DEFAULT), note_pitch(PICAXE_PITCH_C), note_octave(PICAXE_OCTAVE_DEFAULT) {
}

void allocateNotes_picaxe(std::vector<Note>* note,std::string* data) {
	for (uint32_t i = 0; i < data->length(); i++) {
		for (; i < data->length(); i++) {
			if (data->at(i) == '$') break;
		}
		uint32_t o = i;
		for (; o < data->length(); o++) {
			if (data->at(o) == ',') break;
		}
		Note nnote;
		nnote.set_picaxeNote(data->substr(i, o-i));
		note->push_back(nnote);
		i = o;
	}
}

void allocateNotes_rtttl(std::vector<Note>* note, std::string* data) {
	for (uint32_t i = 0; i < data->length(); i++) {
		for (; i < data->length(); i++) {
			if (data->at(i) != ' ') break;
		}
		uint32_t o = i;
		for (; o < data->length(); o++) {
			if (data->at(o) == ',') break;
		}
		Note nnote;
		nnote.set_rtttlNote(data->substr(i, o - i));
		note->push_back(nnote);
		i = o;
	}
}

void deallocateNotes_picaxe(std::vector<Note>* note, std::string* data) {
	for (auto&& element : *note) {
		*data += element.get_picaxeNote() + ",";
	}
	data->erase(data->end() - 1);
}

void deallocateNotes_rtttl(std::vector<Note>* note, std::string* data) {
	for (auto&& element : *note) {
		*data += element.get_rtttlNote() + ",";
	}
	data->erase(data->end() - 1);
}

void loadData(std::string* fileName,std::string* data) {
	std::ifstream inFile(fileName->c_str());
	std::stringstream stream;
	stream << inFile.rdbuf();
	*data = stream.str();
	inFile.close();
}

void writeData(std::string* fileName, std::string* data) {
	std::ofstream outFile(fileName->c_str());
	outFile << *data;
	outFile.close();
}

void convertData_basicRtttl(std::string* input, std::string* output) {
	uint32_t pos = input->find_first_of("(");
	Note::set_metaData_picaxe(input->substr(0, pos));
	input->erase(input->begin(), input->begin() + pos);
	std::vector<Note> note;
	allocateNotes_picaxe(&note, input);
	deallocateNotes_rtttl(&note, output);
	*output = Note::get_metaData_rtttl() + *output;
}

void convertData_rtttlBasic(std::string* input, std::string* output) {
	uint32_t pos = input->find_last_of(":");
	Note::set_metaData_rtttl(input->substr(0, pos));
	input->erase(input->begin(), input->begin() + pos + 1);
	std::vector<Note> note;
	allocateNotes_rtttl(&note,input);
	deallocateNotes_picaxe(&note,output);
	*output = Note::get_metaData_picaxe() + "(" + *output + ")";
}

//TODO: Make it so that you can use terminal arguments
int main() {
	std::cout << "RTTTL <-> PICAXE Basic Converter | Created by Teddy Hutteddy" << std::endl;
	std::cout << "Note: This software is as buggy as you-know-what.\nIt has 0% error detection, so if you type in something odd... Well." << std::endl;
	std::cout << std::endl;
	while (1) {
		uint16_t mode = 0;
		std::string modestr;
		std::stringstream modestrm;
		std::string inputFile;
		std::string outputFile;
		std::string input;
		std::string output;
		std::cout << "Conversion Mode; 0 = rtttl to basic; 1 = basic to rtttl;\n->" << std::flush;
		std::getline(std::cin,modestr);
		modestrm << modestr;
		modestrm >> mode;
		std::cout << "Input File Name;\n->" << std::flush;
		std::getline(std::cin,inputFile);
		std::cout << "Output File Name;\n->" << std::flush;
		std::getline(std::cin,outputFile);
		loadData(&inputFile,&input);
		if (mode) {
			convertData_basicRtttl(&input,&output);
		}
		else {
			convertData_rtttlBasic(&input,&output);
		}
		std::cout << output << std::endl << std::endl;
		writeData(&outputFile, &output);
	}
	system("pause");
}//Koder Test