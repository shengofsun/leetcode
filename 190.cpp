#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    static int r[16] = {0b0000, 0b1000, 0b0100, 0b1100,
                        0b0010, 0b1010, 0b0110, 0b1110,
                        0b0001, 0b1001, 0b0101, 0b1101,
                        0b0011, 0b1011, 0b0111, 0b1111};

    uint32_t result = 0;
    uint32_t upper_bits = 0xf0000000;
    uint32_t lower_bits = 0x0000000f;
    int upper_pos = 28;
    int lower_pos = 0;
    for (int i=0; i<4; ++i) {
      uint32_t ru = r[(n & upper_bits) >> upper_pos] << lower_pos;
      uint32_t lu = r[(n & lower_bits) >> lower_pos] << upper_pos;
      result = result + ru + lu;
      upper_bits >>= 4;
      lower_bits <<= 4;
      upper_pos -= 4;
      lower_pos += 4;
    }
    return result;
  }
};

int main() {
  Solution s;
  std::cout << s.reverseBits(43261596) << std::endl;
  std::cout << s.reverseBits(1) << std::endl;
  std::cout << s.reverseBits(0) << std::endl;
}
