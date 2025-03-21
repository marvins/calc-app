
// Project Libraries
#include <tmns/app/calc/core/Options.hpp>


int main( int argc, char* argv[] ){

    // Parse Command-Line and Configuration-File Options
    auto config = Options::parse( argc, argv );


    return 0;
}