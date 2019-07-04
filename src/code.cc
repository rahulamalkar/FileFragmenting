#include <iostream>
#include <fstream>
#include "md5.h"
#include "md5.cc"

#define MAX_TRANSFER_SIZE	100

bool Fragmenter(std::string &contentFileName, std::string &content){
		int contentLength = content.length();
		std::string contentMd5 = md5(content);
		std::cout << "md5: " << contentMd5 << std::endl;
		int sequence = 0;
		while((contentLength - MAX_TRANSFER_SIZE) > 0){
				contentLength -= MAX_TRANSFER_SIZE;
		}
}

int main(int argc, char** args)
{
		std::string fileName("./meta/in.txt");
		//std::string fileName(args[0]);
		std::ifstream ifs(fileName.c_str());
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
						(std::istreambuf_iterator<char>()    ) );

		std::cout << " length:" << content.length() << std::endl;

		if(content.length() > MAX_TRANSFER_SIZE){
				if(!Fragmenter(fileName, content)){
				}
		}
		return 0;
}
