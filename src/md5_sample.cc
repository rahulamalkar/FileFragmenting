#include <iostream>
#include "md5.h"
#include "md5.cc"
 
using std::cout; using std::endl;
 
int main(int argc, char *argv[])
{
    cout << "md5 of 'grape': " << md5("grape") << endl;
    return 0;
}
