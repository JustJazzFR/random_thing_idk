#ifndef ADVRAND_HPP
#define ADVRAND_HPP

#include <random>
#include <vector>
#include <string>

namespace advrand {
    class rnd {
    public:
        //datasets
        std::vector<char> alphabet_lower = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
        };

        std::vector<int> numbers = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        };

        std::vector<char> symbols = {
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+',
            '[', ']', '{', '}', ';', ':', ',', '.', '<', '>', '/', '?', '~', '`'
        };

        std::vector<char> alphabet_upper = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        };

        std::vector<char> all = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '=', '+',
            '[', ']', '{', '}', ';', ':', ',', '.', '<', '>', '/', '?', '~', '`'
        };
        //randomize w/ lowercase alphabet
        std::string rnd_alph_l(std::string source, std::vector<char> alph_l) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, alph_l.size() - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = alph_l[dist(rnd)];
            }

            return rndm;
        }

        //randomize w/ uppercase alphabet
        std::string rnd_alph_up(std::string source, std::vector<char> alph_u) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, alph_u.size() - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = alph_u[dist(rnd)];
            }

            return rndm;
        }
        //randomize w/ symbols
        std::string rnd_sym(std::string source, std::vector<char> symb) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, symb.size() - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = symb[dist(rnd)];
            }

            return rndm;
        }

        //randomize w/ numbers
        int rnd_nmb(std::string source, std::vector<int> nmbs) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, nmbs.size() - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = '0' + nmbs[dist(rnd)];
            }

            return std::stoi(rndm);
        }
        //randomize w/ literally everything
        std::string rnd_true(std::string source, std::vector<char> all) {
            static std::mt19937 rnd(std::random_device{}());
            std::uniform_int_distribution<int> dist(0, all.size() - 1);
            std::string rndm = source;

            for(char &c : rndm) {
                c = all[dist(rnd)];
            }

            return rndm;
        }

        //random number shytte
        // random int!
        long gen_int(long min, long max) {
            static std::mt19937_64 rnd(std::random_device{}());
            std::uniform_int_distribution<long> dist(min, max);

            return dist(rnd);
        }
        //random decimal
        double gen_dec(double min, double max) {
            static std::default_random_engine rnd(std::random_device{}());
            std::uniform_real_distribution<double> dist(min, max);

            return dist(rnd);
        }
    };
}

#endif
