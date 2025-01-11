#ifndef FUNCTION_HASH_H_
#define FUNCTION_HASH_H_

#include <functional>
template <typename TFunction>
struct FunctionHash {
    using signature = typename TFunction::result_type(*)(typename TFunction::argument_type); // Extract the signature

    size_t operator()(const TFunction& func) const {
        // Extract the function target based on its signature
        auto ptr = func.template target<signature>();
        if (ptr == nullptr) {
            return 0;
        } else {
            return std::hash<void*>()((void*)(ptr));
        }
    }
};

#endif // FUNCTION_HASH_H_
