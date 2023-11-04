// Name: YinBo Kuo
// SSID: 1878120
// Assignment #: 3
// Submission Date: 10/11/2023

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "A03.h"

void parse_config_file(Configuration& c) 
{
   //todo: parse the configuration file and store information in Configuration c
    std::ifstream fin;
	fin.open(c.config_filename); // open file stream
	if(fin.fail()){ // error handling
		std::cerr << "Configuration open fail!!" << std::endl;
		std::cerr << "Error: " << strerror(errno) << '\n';
		exit(1);
	}
	std::string line;
	// The newline in Window and Uinx or Linux is different. It seems to a03.config use '\r\n' to change line
	while (std::getline(fin, line)) {
		std::stringstream ss;
		ss << line;
		std::string arg;
		std::getline(ss, arg, ' ');

		if (arg == "-k") {
			ss >> line;
			c.k = std::stoi(line);
		}
		else if (arg == "-i") {
			ss >> line;
			c.infile = line;
		}
		else if (arg == "-o") {
			ss >> line;
			c.outfile = line;
		}
		else if (arg == "-E") {
			c.encrypt = true;
		}
		else if (arg == "-c") {
			ss >> line;
			c.codebook_filename = line;
		}
	}
	fin.close(); // close file stream
}

//read codebook from file and initialize char codebook array
void read_codebook(Configuration& c, char codebook[], int length)
{
	//todo: read the codebook.csv file and store characters in codebook array
	std::ifstream fin;
	char code;
	int idx = 0;
	fin.open(c.codebook_filename); // open file stream
	if(fin.fail()){ // error handling
		std::cerr << "file open fail!! [read_codebook]" << std::endl;
		std::cerr << "Error: " << strerror(errno) << '\n';
		fin.close();
		exit(1);
	} 
	while(fin >> code){ // read all character and store to the code_book characters array
		if(code != ','){
			codebook[idx++] = code; // use idx++ to count the size of code book
		}
	}
	fin.close(); // close file
}

void read_input_file(std::string& msg, const Configuration& c)
{
	std::ifstream fin;
	fin.open(c.infile); // open file stream
	if(fin.fail()) {
		std::cerr << c.infile << " open failed!! [write_input_file]" << std::endl;
		std::cerr << "Error: " << strerror(errno) << '\n';
		fin.close();
		exit(1);
	}
	std::getline(fin, msg); 
	fin.close(); // close file stream
}

void write_outfile(std::string& msg, const Configuration& c)
{
	// todo: write the msg string to the Configuration.outfile 
	std::ofstream fout; 
	fout.open(c.outfile); // open output file stream
	if(fout.fail()) { // error handling
		std::cerr << c.outfile << " open failed!! [write_outfile]" << std::endl;
		std::cerr << "Error: " << strerror(errno) << '\n';
		fout.close();
		exit(1);
	}
	fout << msg; // write the string to file
	fout.close(); // close output file stream
}


//encrypt using a shift cipher
void encrypt(std::string& plaintext, int k, char codebook[], int CODE_BOOK_LENGTH)
{
	// todo: encrypt the plaintext (same code as Assignment 2)
	int encrypt_index(0); // initialize the index of encrypt
	for(int i=0;i<plaintext.length();i++){ // first for-loop control the msg's each character
		for(int j=0; j<CODE_BOOK_LENGTH; j++){ // second for-loop use for comparing the character that in the codebook 
			if(plaintext[i] == codebook[j]) { // find the index of the codebook(j)
				encrypt_index = (j + k) % CODE_BOOK_LENGTH; // calculate the index of encrypt
				plaintext[i] = codebook[encrypt_index]; // store back the shifted character to corresponding place into msg
				break; // prevent doing the extra iteration 
			} 
		}
	}
}

//decrypt using a shift cipher
void decrypt(std::string& ciphertext, int k, char codebook[], int CODE_BOOK_LENGTH)
{
	// todo: decrypt the ciphertext (same code as Assignment 2)
	int decrypt_index(0); // initialize the index of decrypt
	for(int i=0;i<ciphertext.length();i++){ // first for-loop control the msg's each character
		for(int j=0; j<CODE_BOOK_LENGTH; j++){ // second for-loop use for comparing the character that in the codebook 
			if(ciphertext[i] == codebook[j]) { // find the index of the codebook(j)
				decrypt_index = (j-k) >= 0 ? (j - k) % CODE_BOOK_LENGTH : (((j - k) % CODE_BOOK_LENGTH) + CODE_BOOK_LENGTH) % CODE_BOOK_LENGTH; // use the ternary condition to determine which formula that should be use
				ciphertext[i] = codebook[decrypt_index]; // store back the shifted character to corresponding place into msg
				break; // prevent doing the extra iteration 
			} 
		}
	}
}
