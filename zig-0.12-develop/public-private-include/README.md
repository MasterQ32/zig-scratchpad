# Private/Public Include Requirement

This example models a situation where two required libraries can be used,
but only if a library has private include paths.

Dependency Graph:

- exe (requires `lib-a/include/compression.h`, `lib-b/include/loader.h`)
  - lib-a (provides `lib-a/include/compression.h`)
  - lib-b (provides `lib-b/include/loader.h`, `requires lib-c/include/compression.h`)
    - lib-c (provides `lib-c/include/compression.h`)

This path can only be properly expressed with modules when `std.Build.Module` both exposes a set of public and private include paths,
where the private and public ones are passed to files compiled, but only the public ones are passed to dependents.

[CMake](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#target-usage-requirements) also specifies `INTERFACE`, which is
only passed to dependents, but not the files in the module itself.
