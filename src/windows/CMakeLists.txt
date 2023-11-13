file(GLOB_RECURSE __src *.cpp *.c *.h *.hpp)

set(main_src ${main_src} ${__src} PARENT_SCOPE)
