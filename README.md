# This is my foray into creating a ray tracer from scratch.


I am referencing the following books:
- An Introduction to Ray Tracer by Andrew Glassner. Available at https://archive.org/details/AnIntroductionToRayTracing_201902
- Ray Tracing from the Ground Up by Kevin Suffern.
- The Ray Tracer Challenge by Jamis Buck.

## Building the Code and Tests
```
> mkdir build
> cd build
> cmake ../
> cmake --build .
```

### Executing the Tests
```
> cd build
> ctest
```

## Requirements
- `cmake` version `3.10` or greater.
- `cppcheck` (latest).
- `googletest` included in the repository as a submodule. Use `--recursive` flag while cloning to download the correct version.