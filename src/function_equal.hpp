#ifndef FUNCTION_EQUAL_H_
#define FUNCTION_EQUAL_H_

template <typename TFunction>
struct FunctionEqual {
    using signature_type = typename TFunction::result_type(*)(typename TFunction::argument_type);

    bool operator()(const TFunction& lhs, const TFunction& rhs) const {
        return lhs.template target<signature_type>() ==
               rhs.template target<signature_type>();
    }
};

#endif // FUNCTION_EQUAL_H_
