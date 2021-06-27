set_project("blank_sdl2")
set_xmakever("2.5.4")
set_version("0.1", {build = "%Y%m%d%H%M"})
set_warnings("all", "error")

set_languages("c99", "cxx11")

set_configdir("src/Utils/")
add_configfiles("src/Utils/Config.h.in")
set_configvar("PROJ_NAME", "blank_sdl2")

add_syslinks("SDL2") -- dynamic?
add_sysincludedirs("/usr/include")
add_includedirs("/usr/local/include")

target("blank_sdl2")
  set_kind("binary")
  set_basename("blank_sdl2_$(mode)")
  
  add_files("src/**.c") -- recursive
  add_headerfiles("src/**.h")

  add_rules("mode.release", "mode.debug")

  if is_mode("debug") then
    set_symbols("debug")
    add_defines("DEBUG")
    set_optimize("none")
    set_targetdir("build/debug/")
  
  elseif is_mode("release") then
    set_symbols("release")
    add_defines("RELEASE")
    set_optimize("fastest")
    set_strip("all")
    set_targetdir("build/release/")
  end
  
  before_build_file(function (target)
    os.exec("./format.sh")
  end)

target_end()