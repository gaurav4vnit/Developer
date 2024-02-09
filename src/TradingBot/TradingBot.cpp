#include <iostrem>
#include <threads>
void readData()
{

}

void writeData()
{

}
int ( int argc, char* argv[] )
{

MarketData m; 
std::jthread t1(m.readApi);
std::jthread t2(writeApi);

return 0;
}





