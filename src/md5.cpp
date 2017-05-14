#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "rc4_enc.c"
#include "rc4_skey.c"
#include "md5.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
using namespace std;


int main(){
string name = "";
string temp = "";
string tmp= "";
string pass = "";
int size, fd;

//cout << "pass?" << endl;
//cin >> pass;


ifstream inFile;

inFile.open("keyPass.txt");

cout << "file name to read?" << endl;
cin >> name;

while (getline(inFile, temp)){
pass += temp;
}

cout << pass << endl << pass.length() << endl;

unsigned char digest[MD5_DIGEST_LENGTH];
char in[sizeof(pass)];
strcpy(in,pass.c_str());
MD5((unsigned char*)&in, strlen(in), (unsigned char*)&digest);

fd =open(name.c_str(),O_RDWR);

if (fd == -1){
std::cout << "Couldnt fine read file!" << std::endl;
return -1;
}

int fileLength = lseek(fd, 0, SEEK_END);

unsigned char* fcontents;
fcontents = (unsigned char*) calloc(fileLength, sizeof(char));

if (0 == (pread(fd , fcontents, fileLength, 0))){
cout << "SORRY" << endl;
free (fcontents);
}

string change(reinterpret_cast<char const*>(fcontents), fileLength);

RC4_KEY key;
int length = change.length();
unsigned char *buff = (unsigned char*)malloc(length-1);
memset(buff, 0, length-1);
RC4_set_key(&key, sizeof(digest) ,(const unsigned char*)digest);
RC4(&key, length, (const unsigned char*)change.c_str(), buff);
string result((char*)buff, length);
free(buff);
pwrite(fd, result.c_str(), fileLength, 0);



}

