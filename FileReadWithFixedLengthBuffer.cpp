#include <iostream>
#include <fstream>

using namespace std;

const int buffer_length = 10;

int main () {

  ifstream is ("FileReadWithFixedLengthBuffer.cpp");
  if (is) {
   
    // get length of file:
    is.seekg (0, is.end);
    int length = is.tellg();
    length -= 1;

    //move pointer to start of the file
    is.seekg (0, is.beg);

    char * buffer = new char [buffer_length];

    int loop = length / buffer_length;
    int rem = length % buffer_length;

    for(int i=0;i<loop;i++)
	{	
       is.read (buffer,buffer_length);
       cout << buffer;
	}

    is.read (buffer,rem);    
    buffer[rem]='\0';
    cout << buffer;

    delete[] buffer;
  }
  return 0;
}
