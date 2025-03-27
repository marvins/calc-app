# Design Notes for the Terminus Geospatial Toolbox

This is more of an SDK with included app, rather than just an application. 

In order to get a mildly functional app that wasn't too painful to expand upon, I decided to literally just recreate many of the components you'd find in a normal SDK. 

- Advanced Math API
- UI / GUI App
- Geospatial API
- Webservice API

## C++ Architecture

This package defines a few core libraries.  <b><u>Someday</u></b> these will get compiled into standalone libraries as well as standalone repos. 

* **Module:** <u>***Terminus***</u>, **Namespace:** `tmns`, **Folder:** `terminus/`
   * **Module:** <u>***Drivers***</u>, **Namespace:** `tmns::drv`, **Folder:** `terminus/drivers/`
      * Pure library
      * Stores system-specific state information. 
   * **Module:** <u>***Graph***</u>, **Namespace:** `tmns::graph`, **Folder:** `terminus/graph/`
      * Pure Library
      * Demo app may be available.
      * This is the primary graphing calculator application.
   * **Module:** <u>***GUI***</u>, **Namespace:** `tmns::gui`, **Folder:** `terminus/gui`
      * Pure library
      * Provides a re-usable and extensible user-interface for all systems.
   * **Module:** <u>***Log***</u>, **Namespace:** `tmns::log`, **Folder:** `terminus/log/`
      * Pure library
      * Provides a universally-accessible logger for all systems.
   * **Module:** <u>***Toolbox***</u>, **Namespace:** `tmns::calc`
      * This is the <u>primary application</u>.
   * **Module:** <u>***Utilities***</u>, **Namespace:** `tmns::utils`
      * Pure library
      * Provides basic helper functions anyone is free to use.

### Dependency Tree

When building apps for this SDK, you need to keep in mind how the libraries were designed to interact. 
