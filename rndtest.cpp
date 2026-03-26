//test file :)
#include <iostream>
#include "advrand.hpp"

using namespace advrand;

int main() {
    rnd random;
    std::string sentence = "I need to hide this sentence plz help.";
    std::string rndSentence1 = random.rnd_nmb(sentence, random.numbers);
    std::string rndSentence2 = random.rnd_alph_l(sentence, random.alphabet_lower);
    std::string rndSentence3 = random.rnd_alph_up(sentence, random.alphabet_upper);
    std::string rndSentence4 = random.rnd_sym(sentence, random.symbols);
    std::string rndSentence5 = random.rnd_true(sentence, random.all);

    std::cout << rndSentence1 << "\n";
    std::cout << rndSentence2 << "\n";
    std::cout << rndSentence3 << "\n";
    std::cout << rndSentence4 << "\n";
    std::cout << rndSentence5 << "\n";
    std::cout << sentence << "\n";

    int rndInt = rnd::gen_int(0, 79835478943);
    std::cout << rndInt << "\n";

    double rndDec = rnd::gen_dec(0.00000001, 1.00000001);
    std::cout << rndDec << "\n";

    if (random.rnd_file("file2rnd.txt", "rndfile.txt")) {
        std::cout << "File randomized successfully.\n";
    } else {
        std::cout << "Failed to randomize file.\n";
    }

    return 0;
}
