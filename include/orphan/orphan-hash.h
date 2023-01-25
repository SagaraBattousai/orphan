#ifndef __ORPHAN_HASH_H__
#define __ORPHAN_HASH_H__

#include <cstddef>

#include <vector>
#include <functional>

#include <orphan/_orphanconfig.h>

namespace orphan
{

    using hash_output = std::vector<std::byte>;
    // don't like using const and/or ref inside of using/typedef
    using hash_input = const std::vector<std::byte>&;

		using HashFunction = std::function<hash_output(hash_input)>;

    //Function Composition
		ORPHAN_EXPORT_SYMBOL HashFunction operator*(HashFunction&& lhs, HashFunction&& rhs); 

} //namespace orphan

#endif
