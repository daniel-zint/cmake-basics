#include <iostream>

#include "cmakeConfig.h"

int main( int argc, char* argv[] ) {
#ifdef USE_GLOG
	google::InitGoogleLogging( argv[0] );
	google::LogToStderr();
#endif // USE_GLOG

	PRINT( "Hello World!" );
	
}