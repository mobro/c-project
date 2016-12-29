/*
 * =====================================================================================
 *
 *       Filename:  config.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10.08.2016 19:49:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
// The defines come from the CMakeLists.txt file
#define C_PROJECT_VERSION_MAJOR @C_PROJECT_VERSION_MAJOR@
#define C_PROJECT_VERSION_MINOR @C_PROJECT_VERSION_MINOR@

#ifdef __linux__
  //printf("You are running under linux\n");
#elif _WIN32
  #error "You are running under windows\n"
#else
#endif
