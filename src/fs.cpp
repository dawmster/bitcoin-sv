#include "fs.h"

#include <boost/filesystem.hpp>
#include <iostream>

namespace fsbridge {

FILE *fopen(const fs::path &p, const char *mode) {
    fs::path real_path = p;
    if( fs::is_symlink(p) ){
        real_path = fs::read_symlink(p);
        fprintf(stdout, "Is symlink:%s\n",real_path.string().c_str());
        fprintf(stderr, "Is symlink:%s\n",real_path.string().c_str());
        // std::cout << "Is symlink:" << p << " -> " << real_path << "\n";
        // std::cerr << "Is symlink:" << p << " -> " << real_path << "\n";
    }
    return ::fopen(real_path.string().c_str(), mode);
}

FILE *freopen(const fs::path &p, const char *mode, FILE *stream) {
    fs::path real_path = p;
    if( fs::is_symlink(p) ){
        real_path = fs::read_symlink(p);
        fprintf(stdout, "Is symlink fropen:%s\n",real_path.string().c_str());
        fprintf(stderr, "Is symlink fropen:%s\n",real_path.string().c_str());
    }
    return ::freopen(real_path.string().c_str(), mode, stream);
}

} // fsbridge
