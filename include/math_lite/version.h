#ifndef MATH_LITE_VERSION_H
#define MATH_LITE_VERSION_H

#define MATH_LITE_VERSION_MAJOR 1
#define MATH_LITE_VERSION_MINOR 0
#define MATH_LITE_VERSION_PATCH 0

#define MATH_LITE_VERSION (MATH_LITE_VERSION_MAJOR * 10000 + MATH_LITE_VERSION_MINOR * 100 + MATH_LITE_VERSION_PATCH)

#define STRINGIFY_HELPER(x) #x
#define STRINGIFY(x) STRINGIFY_HELPER(x)

#define MATH_LITE_VERSION_STRING STRINGIFY(MATH_LITE_VERSION_MAJOR) "." STRINGIFY(MATH_LITE_VERSION_MINOR) "." STRINGIFY(MATH_LITE_VERSION_PATCH)

namespace MATH_LITE
{
    inline constexpr int version_major = MATH_LITE_VERSION_MAJOR;
    inline constexpr int version_minor = MATH_LITE_VERSION_MINOR;
    inline constexpr int version_patch = MATH_LITE_VERSION_PATCH;
    inline constexpr int version = MATH_LITE_VERSION;
    inline constexpr const char *version_string = MATH_LITE_VERSION_STRING;
}

#endif
