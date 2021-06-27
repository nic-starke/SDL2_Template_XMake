# blank_sdl2

- A blank sdl2 project ready to go.
- Uses xmake for build configuration, compilation, dependency management: [[link]](https://xmake.io/#/)

# Dependencies
  - SDL2 
  - XMake

# Configuration
Firstly, configure the project:
```
xmake f -c
```
You can modify the config template /src/utils/Config.h.in.
Do not add comments (or commented-out lines) as this will break xmake.
Config variables (the defines in the Config.h) are set in the **xmake.lua** file:

```
set_configvar("PROJ_NAME", "blank_sdl2")
```

# Compilation
- To build debug
```
xmake f -m debug
xmake
```
- To build release
```
xmake f -m release
xmake
```
- To clean
```
xmake f -c
```

