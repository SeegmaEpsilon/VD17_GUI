#############################################################################
# Makefile for building: GUI_CurrentLoop
# Generated by qmake (2.01a) (Qt 4.8.4) on: ?? 22. ??? 19:13:25 2023
# Project:  GUI_CurrentLoop.pro
# Template: app
# Command: e:\Agapitov_data\Tool\Qt\4.8.4\bin\qmake.exe -spec ..\..\Tool\Qt\4.8.4\mkspecs\win32-g++ -o Makefile GUI_CurrentLoop.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = e:\Agapitov_data\Tool\Qt\4.8.4\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: GUI_CurrentLoop.pro  ../../Tool/Qt/4.8.4/mkspecs/win32-g++/qmake.conf ../../Tool/Qt/4.8.4/mkspecs/features/device_config.prf \
		../../Tool/Qt/4.8.4/mkspecs/qconfig.pri \
		../../Tool/Qt/4.8.4/mkspecs/modules/qt_webkit_version.pri \
		../../Tool/Qt/4.8.4/mkspecs/features/qt_functions.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/qt_config.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/exclusive_builds.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/default_pre.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/default_pre.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/debug.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/debug_and_release.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/default_post.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/default_post.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/serialport.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/rtti.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/exceptions.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/stl.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/shared.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/warn_on.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/qt.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/thread.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/moc.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/win32/windows.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/resources.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/uic.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/yacc.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/lex.prf \
		../../Tool/Qt/4.8.4/mkspecs/features/include_source_dir.prf \
		e:/Agapitov_data/Tool/Qt/4.8.4/lib/qtmaind.prl
	$(QMAKE) -spec ..\..\Tool\Qt\4.8.4\mkspecs\win32-g++ -o Makefile GUI_CurrentLoop.pro
..\..\Tool\Qt\4.8.4\mkspecs\features\device_config.prf:
..\..\Tool\Qt\4.8.4\mkspecs\qconfig.pri:
..\..\Tool\Qt\4.8.4\mkspecs\modules\qt_webkit_version.pri:
..\..\Tool\Qt\4.8.4\mkspecs\features\qt_functions.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\qt_config.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\exclusive_builds.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\default_pre.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\default_pre.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\debug.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\debug_and_release.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\default_post.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\default_post.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\serialport.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\rtti.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\exceptions.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\stl.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\shared.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\warn_on.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\qt.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\thread.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\moc.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\win32\windows.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\resources.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\uic.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\yacc.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\lex.prf:
..\..\Tool\Qt\4.8.4\mkspecs\features\include_source_dir.prf:
e:\Agapitov_data\Tool\Qt\4.8.4\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec ..\..\Tool\Qt\4.8.4\mkspecs\win32-g++ -o Makefile GUI_CurrentLoop.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
