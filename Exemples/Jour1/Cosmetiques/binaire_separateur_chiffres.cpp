#include <iostream>
#include <iomanip>
#include <bitset>

int main()
{
    std::int16_t bvalue = 0b0111'1010'0101'0011;
    std::int16_t hvalue = 0x7A'53;
    std::int16_t dvalue = 31'315;

    std::cout << "0b" << std::bitset<16>(bvalue).to_string() 
              << " == 0x" << std::hex << hvalue << std::dec 
              << " == " << dvalue << std::endl;

    double omega = 3'546.13'779'423;
    std::cout << "omega = " << std::setprecision(14) << omega 
              << std::endl;
    return EXIT_SUCCESS;
}