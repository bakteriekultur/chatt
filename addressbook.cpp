#include <fstream>
#include <iostream>
#include <vector>
//#include "wsa.h"
struct address{
  uint32_t ip;
  uint16_t port;
  uint64_t id;
  uint64_t timestamp;
};
void writeBinary(const std::vector<struct address>& output){
  std::fstream file;
  file.open("address.bin",std::ios_base::out|std::ios_base::binary);
  file.write((const char*)&output[0],output.size()*sizeof(struct address));
};
void updateBinary(std::vector<struct address>& localBinary){
  //skickar id förfrågning
  //om man tar emot så jämför man med sin
  //annars får den andra den informationen
  //
  //
}

std::vector<struct address> readBinary(){
  char c = 0;
  int count = 0;
  std::fstream file;
  file.open("address.bin", std::ios_base::in|std::ios_base::binary);
  file.seekg(0,std::ios_base::end);
  int fileLength = file.tellg();
  file.seekg(0,std::ios_base::beg);
  std::vector <struct address> input(fileLength/sizeof(struct address));
  //printf("%d",fileLength);
  file.read((char*)&input[0],input.size()*sizeof(struct address));
  return input;
  }


int main(){
  std::vector<struct address> v;
  v.push_back({1,2,3,4});
  v.push_back({5,6,7,8});
  writeBinary(v);
  std::vector<struct address> input = readBinary();
  for(auto& i:input)
    printf("%u",i.ip);
  return 0;
}
















