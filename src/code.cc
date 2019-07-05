#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "md5.h"
#include "md5.cc"
#include <iostream>
#include <fstream>

#define TBR_LOG(msg) std::cout << std::endl << "TBR--- " << msg << std::endl;
unsigned int MAX_TRANSFER_SIZE = 100;

bool Fragmenter(std::string &contentFileName, std::string &content){
		std::string contentMd5 = md5(content);
		//std::cout << "md5: " << contentMd5 << std::endl;
		unsigned int sequence = 0;
		unsigned int contentIndex = 0;
		unsigned int contentFinalSequence = content.length() / MAX_TRANSFER_SIZE;

		while(sequence <= contentFinalSequence){
				rapidjson::StringBuffer s;
				rapidjson::Writer<rapidjson::StringBuffer> writer(s);

				writer.StartObject();
				writer.Key("key");
				writer.String(contentMd5.c_str());
				writer.Key("sequence");
				writer.Uint(sequence);
				writer.Key("finalSequence");
				writer.Uint(contentFinalSequence);
				writer.Key("data");
				if(sequence == contentFinalSequence){
						writer.String(content.substr (contentIndex, std::string::npos).c_str());
				}else{
						writer.String(content.substr (contentIndex, contentIndex + MAX_TRANSFER_SIZE).c_str());
				}
				writer.EndObject();

				std::cout << s.GetString() << std::endl << std::endl;

				sequence++;
				contentIndex += MAX_TRANSFER_SIZE;
		}
}

int main(int argc, char** args)
{
		std::string fileName("./meta/in.txt");
		//std::string fileName(args[0]);
		std::ifstream ifs(fileName.c_str());
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
						(std::istreambuf_iterator<char>()    ) );

		//std::cout << " length:" << content.length() << std::endl;

		if(content.length() > MAX_TRANSFER_SIZE){
				if(!Fragmenter(fileName, content)){
				}
		}
		return 0;
}
