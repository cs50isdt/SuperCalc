/*
  annotations.h
  SuperCalc

  Created by C0deH4cker on 6/19/20.
  Copyright (c) 2020 C0deH4cker. All rights reserved.
*/

#ifndef SC_ANNOTATIONS_H
#define SC_ANNOTATIONS_H

#include <stdlib.h>


#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#ifndef __has_feature
# define __has_feature(x) 0
#endif

#ifndef __has_builtin
# define __has_builtin(x) 0
#endif


# define WARN_UNUSED_RESULT

# define NORETURN __attribute__((noreturn))

# define ATTR_FORMAT(...)

# define FALLTHROUGH

# define NOESCAPE

# define ATTR_CF_CONSUMED

# define ATTR_CF_RETURNS_RETAINED

# define ATTR_CF_RETURNS_NOT_RETAINED

# define ASSUME(...)

# define UNREACHABLE __builtin_assume(false)

# define _Nullable
# define _Nonnull
# define ASSUME_NONNULL_BEGIN
# define ASSUME_NONNULL_END

/* Used in a function body to signify that the named parameter is intentionally unused */
#ifndef UNREFERENCED_PARAMETER
# define UNREFERENCED_PARAMETER(param) do { param = param; } while(0)
#endif

/* Attributes purely for documentation purposes */
#define IN
#define OUT
#define INOUT

#define OWNED
#define UNOWNED

#define PRINTFLIKE(fmtstr, va) ATTR_FORMAT(__printf__, fmtstr, va)
#define ESCAPING
#define CONSUMED ATTR_CF_CONSUMED
#define RETURNS_OWNED ATTR_CF_RETURNS_RETAINED
#define RETURNS_UNOWNED ATTR_CF_RETURNS_NOT_RETAINED

/* These aren't possible to implement with current attributes, so they serve as documentation only */
#define INVARIANT(...)
#define _Nonnull_unless(...) _Nonnull
#define _Nullable_unless(...) _Nullable
#define OWNED_WHEN(...)
#define UNOWNED_WHEN(...)


/* Convenience macro telling the clang static analyzer that this pointer is nonnull at this point */
#define CAST_NONNULL(ptr) ((__typeof__(*ptr) * _Nonnull)(ptr))

/* Convenience typedefs */
typedef const char* _Nonnull * _Nonnull istring;

#ifdef __clang_analyzer__
/* Tell the analyzer that this object has been consumed. This "function" has no body */
void analyzer_consume(void* _Nullable CONSUMED arg);
#else /* __clang_analyzer__ */
# define analyzer_consume(...) (void)(__VA_ARGS__)
#endif /* __clang_analzer__ */

#endif /* SC_ANNOTATIONS_H */
