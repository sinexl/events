#ifndef FN_SET_H_
#define FN_SET_H_

#include "function_hash.hpp"
#include "function_equal.hpp"
#include <unordered_set>

template<typename TFunction>
using fn_set = std::unordered_set<TFunction, FunctionHash<TFunction>, FunctionEqual<TFunction>>;


#endif // FN_SET_H_
