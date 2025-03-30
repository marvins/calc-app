#  Terminus Calculator App

This is my attempt to build a nice handy calculator app for the ClockworkPi PicoCalc device.  This is an open-source graphing calculator built on a Raspberry-Pi Pico. 

---
## Building the C++ Application

See [Building Terminus Toolbox](./docs/Building-General.md) for more information on how to compile this repo. 

### Supported Platforms

- Linux:
    - **Tested Configurations:**
        - ClockworkPi uConsole A06
        - 


---

## C++ Application Usage Instructions 

The `./examples/` folder contains a few example commands to run which flex the capabilities of this application. 

### Generate a Config File

Run the following script to create a file at `./sample.options.cfg'.  This file will be immediately usable. 

```bash
./scripts/cpp-gen-config.sh
```

### Run Application

Run the following script to launch and run `terminus_toolbox` on any `desktop` compiled system. 

```bash
./scripts/cpp-run-app.sh
```

## Helper Applications

### CMake Build File List : `./tools/cmake-build-file-list`

This is a handy app to find all C++ header and source files in the repo and make sure you match.  Why this matters is 
when you forget files in the CMakeLists.txt file, they will either fail to compile (`.cpp`) or won't be scanned for changes
prior to rebuilding (`.hpp`).  I therefore recommend you always provide both headers and footers to the `add_executable()` cmake command.

**Example Usage:**

    ./tools/cmake-build-file-list.py -d cpp/

Then copy and paste this variable to the global `CMakeLists.txt` file and compare. Note that driver files are in `${EXTRA_SOURCES}`, so transfer them to those areas.

**Extra Note:**

I'm super lazy, so if you run this with `--is-test`, it will prepend the `${CMAKE_SOURCE_DIR}` for `test/unit/CMakeLists.txt`. 

    ./tools/cmake-build-file-list.py -d cpp/ --is-test

## Action Items / Todo

- [ ] Add Boost Libraries
    - [ ] Boost UUID
    - [ ] Boost Results
- [ ] Code Updates
    - [ ] Make App API auto-generate stack-layout
        - Note: User just has to define each page.

## References / Citations

All icons in this project are free / Open-Source icons from Icon8.


### Icons Used
- <a target="_blank" href="https://icons8.com/icon/12784/settings">Settings</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>
- <a target="_blank" href="https://icons8.com/icon/wLptoyIYwLb3/calculator">Calculator</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>
- <a target="_blank" href="https://icons8.com/icon/479A9XKbRJ4e/text-editor">Text Editor</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>
