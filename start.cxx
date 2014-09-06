#include "FdInStream.h"
#include "FdOutStream.h"
#include "Exception.h"

//#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include<iostream>

int main()
{

	rdr::FdInStream* instream;
    	rdr::FdOutStream* outstream;

	int fd = open("hello.txt", O_RDONLY, 0666);


	instream = new rdr::FdInStream(fd);
	unsigned char arr = -1;
	instream->readBytes(&arr, 1);
	std::cout<<arr;
	instream->readBytes(&arr, 1);
	std::cout<<arr;
	instream->readBytes(&arr, 1);
	std::cout<<arr;
	instream->readBytes(&arr, 1);
	std::cout<<arr;
	instream->readBytes(&arr, 1);
	std::cout<<arr;



	int fd1 = open("hello1.txt", O_CREAT | O_RDWR, 0666);

	outstream = new rdr::FdOutStream(fd1);
	outstream->writeString("Hello");
	outstream->flush();

	close(fd);
	close(fd1);

return 0;
}
