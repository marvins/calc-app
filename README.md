#  Terminus Calculator App

This is my attempt to build a nice handy calculator app for the ClockworkPi PicoCalc device.  This is an open-source graphing calculator built on a Raspberry-Pi Pico. 

**Note:** Currently I'm debating between a Python-based and C++-based app.  There are some major pros and cons between them. 

## Python vs C++ App

### Python


### C++


---
## Building the C++ Application

This application expects you have the `terminus-setup` repo setup on your machine.  This can be found [at this link](https://github.com/Terminus-Geospatial/terminus-setup).  This can alternatively be setup using the `conan` build system manually. 

For those not accustomed to `conan`, use the `terminus-setup` repo to install conan, add conan via `go-conan` command, then use `conan-build.sh -c -r` to compile the application.

### Building for Fedora Linux

Make sure the required dependencies are installed. 

```bash
sudo dnf install allegro-devel
```

Next, build normally using `conan-build.sh -c -r -o platform="desktop"`


---

## C++ Application Usage Instructions 

The `./examples/` folder contains a few example commands to run which flex the capabilities of this application. 

### Generate a Config File

Run the following script to create a file at `./sample.options.cfg'.  This file will be immediately usable. 

```bash
./scripts/cpp-gen-config.sh
```

### Run Application

Run the following script to launch and run `terminus-calculator` on any `desktop` compiled system. 

```bash
./scripts/cpp-run-app.sh
```
