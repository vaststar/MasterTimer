# Timer using C++
A very nice timer in c++11 written by Thomas Zhu.

# Usage
* firstly, link library in your project-set
* write some common code in your codings

## Using in project
* install first
* set dir in your CMakeList,eg `set(MasterTimer_DIR $InstalledDir$/MasterTimer/install/Release/cmake) `
* use find package , `find_package(MasterTimer REQUIRED)`
* include headers, `include_directories(${MasterTimer_INCLUDE_DIRS})`
* link target to you library, `target_link_libraries(testProgram MasterTimerExport::MasterTimer)`

## Using in code
* `#include "Timer.h"`
* create timer object, `Timer tm(4000,std::bind(function,params),"testTag",true);`
* start timer, `tm.start()`

# Requirement
* >= c++11
* >= cmake3.1

# Install
* make and cd in `build` dir
* run commond: `cmake .. && make && make install`

