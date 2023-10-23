#include <iostream>
#include <string>
#include <fstream>
#include "A03.h"

void parse_config_file(Configuration& c) 
{
	std::ifstream configFile(c.config_filename); // open config file from defs.h of headfile A03.h
    // ----------- You should do ------------
	// Use the a function to check the openfile is correct
    if(configFile.fail()){
        std::cout << "Open file fail" << std::endl;
    }
    // --------------------------------------
	std::string line;
    while (std::getline(configFile, line)) {
        if (line.find("-k") == 0) {
            c.k = std::stoi(line.substr(3)); // e.g. substract the number when -k space number typed(string)
        } else if (line.find("-i") == 0) {  //각 알파벳 찾도록 (string to integer)
            c.infile = line.substr(3);
        } else if (line.find("-o") == 0) {
            c.outfile = line.substr(3);
        } else if (line.find("-E") == 0) {
        	c.encrypt = true;
        } else if (line.find("-c") == 0) {
            c.codebook_filename = line.substr(3);
        }
    }
    // ----------- for debug purpose ------------
    std::cout <<"codebook file name: " << c.codebook_filename << std::endl;
    std::cout <<"confige file name: " <<  c.config_filename << std::endl;
    std::cout <<"encrypt: " << std::boolalpha << c.encrypt << std::endl;
    std::cout << "infile name: " << c.infile << std::endl;
    std::cout << "outfile name: " << c.outfile << std::endl;
    // --------------------------------------
    configFile.close();
   //todo: parse the configuration file and store information in Configuration c

}

//read codebook from file and initialize char codebook array
void read_codebook(Configuration& c, char codebook[], int length) //declaration of c(configuration [%=reference operator], [.=member access operator])
{
	std::ifstream codebookFile(c.codebook_filename);    //by using std::ifstream read 
    // codebookFile.read(codebook, length); // After you read in the codebook, you still need to prcoess the data and store into codebook.
    // Because your codebook.cvs file contians comma; this is not the letters that we want.
    std::string str;
    int count{0};
    std::getline(codebookFile, str); // take whole line into string    
    for(char ch: str){
        if(ch != ',') codebook[count++] = ch;
    }
    //--------- for debug purpose --------
    for(int i=0; i<length; i++){
        std::cout << codebook[i];
    }
    std::cout <<std::endl;
    //------------------------------------
    codebookFile.close();
}


void read_input_file(std::string& msg, const Configuration& c)
{

	std::ifstream inputFile(c.infile);

	std::string line;
	while(std::getline(inputFile, line)){   // read the input file line by line
        msg += line +'\n';
    }

    inputFile.close();
	// todo: read the Configuration.infile and store the text in the msg string
}

void write_outfile(std::string& msg, const Configuration& c)
{
	std::ofstream outputFile(c.outfile);
	
	outputFile << msg;
	outputFile.close();
	// todo: write the msg string to the Configuration.outfile 
}

//encrypt using a shift cipher
void encrypt(std::string& plaintext, int k, char codebook[], int CODE_BOOK_LENGTH)
{
    for (int i = 0; i < plaintext.length(); i++) { 
        char character = plaintext[i];
        // plaintext[i] >> character

        for (int j = 0; j < CODE_BOOK_LENGTH; j++) {
            if (character == codebook[j]) {             // 캐릭터가 코북 글자와 같으면
                int newIndex = (j + k) % CODE_BOOK_LENGTH;  // 계산식 >> newIndex
                plaintext[i] = codebook[newIndex];          // plaintext의 [i]는 계산식이 입력된 newIndex의 값으로 변경됨 in codebook
                break;
            }
        }
    }
}

//decrypt using a shift cipher
void decrypt(std::string& ciphertext, int k, char codebook[], int CODE_BOOK_LENGTH) {
    for (int i = 0; i < ciphertext.length(); i++) {
        char character = ciphertext[i];
        // ciphertext[i] >> character

        for (int j = 0; j < CODE_BOOK_LENGTH; j++) {
            if (character == codebook[j]) {             // character가 코드북의 [j]와 같을경우
                int newIndex = (j - k + CODE_BOOK_LENGTH) % CODE_BOOK_LENGTH; //계산식
                ciphertext[i] = codebook[newIndex];     // ciphertext의 [i]는 계산식이 입력된 newIndex의 값으로 변경됨 in codebook
                break;
            }
        }
    }
}
	// todo: decrypt the ciphertext (same code as Assignment 2)