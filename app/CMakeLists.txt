# Add executable called "application" that is built from the source files
# in the app folder. 
set(source_files
  src/sms/src/main.c
  src/sms/src/sysctrl.c
  src/as/meas/src/measctrl.c
  src/ui/terminal/src/uitask.c
     )

set(EXECUTABLE_OUTPUT_PATH build)

include_directories( src ../fw/src ../pf/src)

add_executable (application ${source_files})

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (application LINK_PUBLIC fw)
