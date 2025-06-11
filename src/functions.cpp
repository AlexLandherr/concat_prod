#include "include/functions.h"
#include <string>
#include <cstdint>

/*
Take the number 192 and multiply it by each of 1, 2, and 3:
                                                         192 x 1 = 192
                                                         192 x 2 = 384
                                                         192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576.
We will call 192384576 the concatenated product of 192 and (1,2,3).

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the
concatenated product of 9 and (1, 2, 3, 4, 5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with
(1, 2,...,n) where n > 1?
*/

namespace func {
    bool is_1_to_n_pandigital(const std::string &num_str, const int64_t &n, const int64_t &num_length) {
        if (num_length < n) {
            return false;
        }
        std::string necessary_digits;
        for (int i = 1; i <= n; i++) {
            necessary_digits = necessary_digits + std::to_string(i);
        }
        bool is_1_to_n_pandigital = true;

        for (char c : necessary_digits) {
            if (num_str.find(c) == std::string::npos) {
                is_1_to_n_pandigital = false;
                break;
            }
        }

        return is_1_to_n_pandigital;
    }

    int64_t solver(const int64_t &n, const int64_t &num_length) {
        int64_t result;
        for (int64_t i = 9876; i > 9000; i--) {
            std::string candidate = std::to_string(i) + std::to_string(2 * i);
            if (is_1_to_n_pandigital(candidate, n, num_length)) {
                result = std::stol(candidate);
                break;
            }
        }

        return result;
    }
}