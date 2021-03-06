/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 *
 * Signature1.cpp
 *
 *  Created on: Oct 19, 2017
 *      Author: William F Godoy godoywf@ornl.gov
 */
#include "Signature1.h"

namespace adios2
{
namespace callback
{
#define declare_type(T, L)                                                     \
    Signature1::Signature1(                                                    \
        const std::function<void(const T *, const std::string &,               \
                                 const std::string &, const std::string &,     \
                                 const Dims &)> &function,                     \
        const Params &parameters, const bool debugMode)                        \
    : Operator("Signature1", parameters, debugMode), m_Function##L(function)   \
    {                                                                          \
    }
ADIOS2_FOREACH_TYPE_2ARGS(declare_type)
#undef declare_type

#define declare_type(T, L)                                                     \
    void Signature1::RunCallback1(const T *arg1, const std::string &arg2,      \
                                  const std::string &arg3,                     \
                                  const std::string &arg4, const Dims &arg5)   \
    {                                                                          \
        if (m_Function##L)                                                     \
        {                                                                      \
            m_Function##L(arg1, arg2, arg3, arg4, arg5);                       \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            throw std::runtime_error("ERROR: Signature1 with type " +          \
                                     std::string(#L) +                         \
                                     " callback function failed\n");           \
        }                                                                      \
    }
ADIOS2_FOREACH_TYPE_2ARGS(declare_type)
#undef declare_type

} // end namespace callback
} // end namespace adios2
