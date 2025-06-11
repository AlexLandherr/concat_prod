#include <string>
#include <cstdint>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    bool is_1_to_n_pandigital(const std::string &num_str, const int64_t &n, const int64_t &num_length);
    int64_t solver(const int64_t &n, const int64_t &num_length);
}

#endif