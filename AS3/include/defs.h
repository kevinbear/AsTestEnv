#pragma once
#ifndef DEFS_H
#define DEFS_H
#include <string>
//
// A03 Configuration structure:
//
struct Configuration {
	int k = 0;
	std::string infile = "";
	std::string outfile = "";
	bool encrypt = true;
	std::string config_filename = "";
	std::string codebook_filename = "";
};
#endif