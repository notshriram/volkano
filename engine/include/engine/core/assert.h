/*
 * Copyright (C) 2022 Emre Simsirli
 *
 * Licensed under GPLv3 or any later version.
 * Refer to the included LICENSE file.
 */

#pragma once

#include <cstdlib>

#include "engine/core/int_types.h"
#include "engine/core/logging/logging.h"

namespace volkano {

#if DEBUG || defined(ENABLE_ASSERTIONS)
    #define VK_ASSERT_MSG(predicate, ...)           \
      do {                                          \
          if(!(predicate)) {                        \
              VK_LOG(general, error,                \
                "!(" #predicate "): " __VA_ARGS__); \
              std::terminate();                     \
              /* todo debugger */                   \
          }                                         \
      } while(0)
#else
  #define VK_ASSERT_MSG(...) void(0)
#endif // DEBUG || defined(ENABLE_ASSERTIONS)

#define VK_ASSERT(predicate) VK_ASSERT_MSG(predicate, "assertion failed")

} // namespace volkano