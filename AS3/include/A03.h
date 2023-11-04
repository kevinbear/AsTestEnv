#pragma once
#ifndef A03_H
#define A03_H
#include <string>
#include "defs.h"
//
// A03 function prototypes:
//
void parse_config_file(Configuration& c);
void read_codebook(Configuration& c, char codebook[], int length);
void read_input_file(std::string& msg, const Configuration& c);
void write_outfile(std::string& msg, const Configuration& c);
void encrypt(std::string& plaintext, int k, char codebook[], int CODE_BOOK_LENGTH);
void decrypt(std::string& ciphertext, int k, char codebook[], int CODE_BOOK_LENGTH);
#endif