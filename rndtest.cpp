#include <iostream>
#include "advrand.hpp"

int main() {
    advrand::rnd random;
    std::string sentence = "I need to hide this sentence plz help.";
    int rndSentence = random.rnd_nmb(sentence, random.numbers);

    std::cout << rndSentence << "\n";
    std::cout << sentence << "\n";

    int rndInt = random.gen_int(0, 10000);
    std::cout << rndInt << "\n";

    double rndDec = random.gen_dec(0.0, 1.000000000000001);
    std::cout << rndDec << "\n";
    return 0;
}
