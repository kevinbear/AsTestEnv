// autograder.exe configuration_filename.config - the name of the configuration file
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "A03.h"

//Code book length and character array
constexpr auto CODE_BOOK_LENGTH = 64;

int main(int argc, char* argv[]) {
	// A3: Declare a configuration struct
	Configuration configuration;

	// A2: Declare a codebook array
	char codebook[CODE_BOOK_LENGTH];

	// A2: string used to store plaintext or ciphertext
	std::string msg;

	// Insufficient arguments, exit program
	if (argc < 2) {
		std::cerr << "Error: Insufficient arguments.\n";
		return -1;
	}

	// A3: Use the command line arguments to get config file
	configuration.config_filename = argv[1];// "a03.config";

	// A3 Task 1: Parse the configuration file to initialize the configuration struct
	parse_config_file(configuration);
	
	// A3 Task 2: initialize the codebook array with characters from the codebook.csv file
	read_codebook(configuration, codebook, CODE_BOOK_LENGTH);

	// A3 Step 3: read in -i file specified in the configuration and store string in msg
	read_input_file(msg, configuration);

	// A3 Tasks 4a/b: Call enrypt and decrypt function	
	// If -E option is in the config file, encrypt the msg
	if (configuration.encrypt)
		//A3 Task 4a: move all encryption code to a function named encrypt
		encrypt(msg, configuration.k, codebook, CODE_BOOK_LENGTH);
	// If -D option is in the config file, decrypt the msg
	else
		//A3 Task 4b: move all decryption code to a function named decrypt
		decrypt(msg, configuration.k, codebook, CODE_BOOK_LENGTH);

	// A3 Task 5: write out the string msg to the -o outfile
	write_outfile(msg, configuration);
	
	//////////AUTOGRADER CODE///////////////
	std::ifstream ifs(configuration.outfile);
	std::string s; ifs >> s; std::cout << s << std::endl;
	ifs.close();
	//////////AUTOGRADER CODE///////////////

	return 0;
}//main
