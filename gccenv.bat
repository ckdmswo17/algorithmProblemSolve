@echo off

:L2

@rem
@rem	set for windows 10
@rem

	@set PATH=%PATH%;C:\Program Files (x86)\Dev-Cpp\MinGW64\bin;C:\Program Files (x86)\Dev-Cpp\MinGW64\libexec\gcc\x86_64-w64-mingw32\4.9.2;C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\bin;

	goto last_message_L


:HELP_L	 
@echo =============================================================================  
@echo        devenv.bat , __T( set devC++ environment )
@echo,
@echo =============================================================================
@echo Usage: devenv.bat  
@echo    ex: devenv.bat  ? 	; help(this)
@echo    ex: devenv.bat   	; set dev env for gcc building ( xp / 1x )

:last_message_L
@echo =============================================================================

@echo you can run gcc.exe  or  mingw32-make.exe
@echo,

@echo To build  x32
@echo   gcc -m32 file.c -o file.exe

@echo,
@echo To build  x64
@echo   gcc      file.c -o file.exe


@echo, 
@echo To build compatible -m32 application,
@echo 	mingw32-make.exe -f Makefile.win  app=file-name-without-ext-here
@echo, 
@echo To clean,
@echo, 
@echo 	mingw32-make.exe -f Makefile.win clean app=file-name-without-ext-here
@echo, 
@echo =============================================================================

	goto end_L


:error_L

:end_L
