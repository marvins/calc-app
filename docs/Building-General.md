# Building Terminus Geospatial Toolbox

This application expects you have the `terminus-setup` repo setup on your machine.  This can be found [at this link](https://github.com/Terminus-Geospatial/terminus-setup).  This can alternatively be setup using the `conan` build system manually. 

**Note:** See `./scripts/` folder for example shell scripts which skip using the conan wrappers.

## About Conan

For those not accustomed to `conan`, use the `terminus-setup` repo to install conan, add conan via `go-conan` command, then use `conan-build.sh -c -r` to compile the application.

Conan is a dependency manager for C++ similar to [vcpkg](https://vcpkg.io/en/). I prefer `conan` because it uses a highly rigid versioning system, and this works well when trying to build across many platforms.

## CMake Notes

I like really strict compiler checking.  It forces me to be deliberate. 

- [A good Reference I used](https://www.foonathan.net/2018/10/cmake-warnings/)


### Building for Fedora Linux

Make sure the required dependencies are installed. 

```bash
sudo dnf install raylib-devel
```


Next, build normally using `conan-build.sh -c -r -o platform="desktop"`