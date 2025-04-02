# Building Toolbox for ClockworkPi uConsole

The uConsole is a tricky-ish setup due to it's default image having some older dependencies. 

**Note:** I did a bunch of extra stuff here, as I then wanted the uConsole to actually compile the Pico-based release for my <u>PicoCalc</u>. 

---
##  Building desktop variant for uConsole (on the uConsole)

### Step 1 : Install required software on uConsole

**Normal Debian Packages:**

- Needed for Raylib

```bash
sudo apt install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev`
```

- Needed for OpenCV

```bash
sudo apt install libopencv-dev
```

- Needed since uConsole uses GCC 11.4, rather than 14, which I tested with Fedora.

```bash
sudo apt install gcc-12 gdb
```

**Note 1:** I strongly recommend you install a manually-compiled, and newer variant of CMake.  This will make building the PicoCalc build easier. 

**Building CMake on uConsole:**
- Unpack tarball and enter folder
- `./bootstrap`
- `make -j4`
- `sudo make install`

**Note 2:** This will take a <u><b>LONG</b></u> time!

Alternatively:  `sudo apt install cmake`

### Step 2 : Clone repositories

I usually create a fresh workspace

```bash
mkdir workspace
pushd workspace
```

Next, clone the repos

```bash
git clone git@github.com:marvins/calc-app.git
```

### Step 3 : Setup Conan Build System

Inside the workspace, setup a Python3.10 or higher virtual environment. 

```bash
python3.10 -m venv ~/conan
```

If this is a regular occurrance, I like to add this to my bashrc.  I usually like to keep Conan out of my system python environment.  Therefore always use Virtual Environments.

```bashrc
function go-conan() {
    . ${HOME}/conan/bin/activate
}

function stop-conan() {
    deactivate
}
```

Then, 

```bash
. ~/.bashrc
go-conan
pip install --upgrade pip
pip install conan
```

Now, we need to setup our profile.   This will 

```bash
(conan) cpi@clockworkpi-a06:~/Desktop/workspace$ conan profile detect
```
Here is the output from that command:
```bash
detect_api: Found cc=gcc- 11.4.0
detect_api: gcc>=5, using the major as version
detect_api: gcc C++ standard library: libstdc++11

Detected profile:
[settings]
arch=armv8
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=11
os=Linux
```

I manually change the compiler C++ standard to 23.  This file is located in `${HOME}/.conan2/profiles/default`.  This is not explicitly required since I hard-code the C++ standard in the project's `CMakeLists.txt` file.

My setup:

```
[settings]
arch=armv8
build_type=Release
compiler=gcc
compiler.cppstd=gnu23
compiler.libcxx=libstdc++11
compiler.version=13
os=Linux
[buildenv]
CC=gcc-12
CXX=g++-12
```


### Step 4 : Install Project Dependencies

#### Step 4.1 : <u><b>Raylib:</b></u>

Raylib is a game engine used to allow the desktop apps to simulate the embeded hardware. 

I could not find it, so I had to build it from source. 

From the workspace: `./workspace/`:
```bash
git clone https://github.com/raysan5/raylib

mkdir build
pushd build
export CXX='g++-12'
cmake -DPLATFORM=DRM -DBUILD_EXAMPLES=true -DBUILD_SHARED_LIBS=true -DINCLUDE_EVERYTHING=true -DCMAKE_BUILD_TYPE=Release -DWITH_PIC=true ..
make -j4
sudo make install
popd
```

### Step 5 : Build Toolbox App

I strongly recommend learning about `conan`.  This is a great tool for 
building C++ apps in a controlled and reproducable manner.

```bash
popd terminus-toolbox
./scripts/build-with-conan.sh
```

**Note:** You can command out the `BUILD_MISSING` variable after the first time you run this script.


---

##  Building Pico Software

### Step 1:  Setup Pico SDK

- <u><b><span style="color:red">Precondition:</b></u></span> Download CMake version 3.13 or later, 

Clone Pico SDK

```bash
git clone git@github.com:raspberrypi/pico-sdk.git
```

Next, make sure core dependencies are installed, per their instructions:

```bash
sudo apt install cmake python3 build-essential gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
```

Navigate into the directory and record it's location

```bash
pushd pico-sdk
export PICO_SDK_PATH="${PWD}"
```

Next, navigate to this repo and run

```bash
popd
pushd calc-app/
./scripts/build-with-conan.pico.sh
```
