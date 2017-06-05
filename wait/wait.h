#ifndef __WAIT_H
#define __WAIT_H

    //This file defines the wait() function to support cross-platform sleeping. 
    //There are several wait "modes:
    //  1. If supplied with an integer X >= 0 the system will sleep X seconds.
    //  2. If supplied with an integer X < 0 the system will wait for a newline character.
    //  3. If compiled with __NOTIMEOUT all calls will behave like 2.
    // 
    // If there is no input and __NOCLEAR is not defined it might be possible that the system waits
    // for multiple newline/EOF characters.
    //
    // Version 2 and 3 without __NOCLEAR will clear the input buffer.
    //
    //Compilation using gcc: 
    //
    //Standard: gcc file.c
    //NOTIMEOUT: gcc -D __NOTIMEOUT file.c
    //NOCLEAR: gcc -D __NOCLEAR file.c
    //NOTIMEOUT, NOCLEAR: gcc -D __NOTIMEOUT -D __NOCLEAR file.c
    //
    //The flags may also be defined in the source file, before the include of wait.h.
    //Example usage may be found in wait_ex.c.

    #if defined(unix) || defined(__unix) || defined(__unix__)
    #define _ISUNIX
    #include <unistd.h>
    #endif
    
    #if defined(_WIN32) || defined(WIN32) 
    #define _ISWIN
    #include <Windows.h>
    #endif

    //sleep X seconds
    #ifdef _ISUNIX
    #define OFF 1
    #endif
    #ifdef _ISWIN
    #define OFF 1000
    #define sleep Sleep
    #endif
    
    void wait(int seconds){
        fflush(stdout);
        #ifndef __NOTIMEOUT
        if(seconds >= 0){
            sleep(seconds*OFF);
            return;
        }
        #endif
        #ifndef __NOCLEAR
        char c;
        while( (c = getchar() != '\n' && c != EOF ) );
        #endif
        getchar();
    }

    #ifdef sleep
    #undef sleep
    #endif

#endif
