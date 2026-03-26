//advanced random library!!
// i made this so tht doing random stuff isnt a pain, especially random
// number generation with all the mt_19937 and what not
// if u are gonna use this plz give credits to me ( ͡° ͜ʖ ͡°)
// Made by @JustJazzFR

#ifndef ADVRAND_HPP
#define ADVRAND_HPP

#include <random>
#include <string>
#include <array>
#include <fstream>
#include <sstream>

namespace advrand {
    class rnd {
    public:
        //arrays and stuff
        const std::array<char, 26> alphabet_lower = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
        };

        const std::array<int, 10> numbers = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        };

        const std::array<char, 32> symbols = {
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+',
            '[', ']', '{', '}', ';', ':', ',', '.', '<', '>', '/', '?', '~', '`'
        };

        const std::array<char, 26> alphabet_upper = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        };

        const std::array<char, 89> all = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+',
            '[', ']', '{', '}', ';', ':', ',', '.', '<', '>', '/', '?', '~', '`'
        };
        //The randomizations dont modify the original string
        //randomize w/ lowercase alphabet
        std::string rnd_alph_l(std::string source, const std::array<char, 26> &alph_l) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, static_cast<int>(alph_l.size()) - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = alph_l[dist(rnd)];
            }

            return rndm;
        }

        //randomize w/ uppercase alphabet
        std::string rnd_alph_up(std::string source, const std::array<char, 26> &alph_u) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, static_cast<int>(alph_u.size()) - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = alph_u[dist(rnd)];
            }

            return rndm;
        }
        //randomize w/ symbols
        std::string rnd_sym(std::string source, const std::array<char, 32> &symb) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, static_cast<int>(symb.size()) - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = symb[dist(rnd)];
            }

            return rndm;
        }

        //randomize w/ numbers
        std::string rnd_nmb(std::string source, const std::array<int, 10> &nmbs) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, static_cast<int>(nmbs.size()) - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = '0' + nmbs[dist(rnd)];
            }

            return rndm;
        }
        //randomize w/ literally everything
        std::string rnd_true(std::string source, const std::array<char, 89> &all) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, static_cast<int>(all.size()) - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = all[dist(rnd)];
            }

            return rndm;
        }

        //random number stuff
        // random int!
        static long gen_int(long min, long max) {
            static std::mt19937_64 rnd(std::random_device{}());
            std::uniform_int_distribution<long> dist(min, max);

            return dist(rnd);
        }
        //random decimal
        static double gen_dec(double min, double max) {
            static std::default_random_engine rnd(std::random_device{}());
            std::uniform_real_distribution<double> dist(min, max);

            return dist(rnd);
        }

        //file stuffs! (File randomization)
        // I plan on using this to make a file scrubber. U can use it too if u want idrc.
        bool rnd_file(const std::string &in_path, const std::string &out_path) {
            std::ifstream infile(in_path);
            if(!infile) return false;

            std::stringstream buffer;
            buffer << infile.rdbuf();
            std::string file_contents = buffer.str();

            std::string rndm = rnd_true(file_contents, all);

            std::ofstream outfile(out_path);
            if(!outfile) return false;
            outfile << rndm;

            return true;
        }
    };
}

#endif
