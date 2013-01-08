#############################################################################
# Makefile for building: Othello
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Jan 8 17:26:14 2013
# Project:  Othello.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile Othello.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Isrc -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/AIMobility.cpp \
		src/AIPlayer.cpp \
		src/BoardLayout.cpp \
		src/Cell.cpp \
		src/Human.cpp \
		src/Othello.cpp \
		src/OthelloAction.cpp \
		src/OthelloBoard.cpp \
		src/OthelloGame.cpp \
		src/OthelloSearchNode.cpp \
		src/StartButton.cpp moc_AIPlayer.cpp \
		moc_BoardLayout.cpp \
		moc_Cell.cpp \
		moc_Human.cpp \
		moc_OthelloGame.cpp \
		moc_Player.cpp \
		moc_StartButton.cpp
OBJECTS       = AIMobility.o \
		AIPlayer.o \
		BoardLayout.o \
		Cell.o \
		Human.o \
		Othello.o \
		OthelloAction.o \
		OthelloBoard.o \
		OthelloGame.o \
		OthelloSearchNode.o \
		StartButton.o \
		moc_AIPlayer.o \
		moc_BoardLayout.o \
		moc_Cell.o \
		moc_Human.o \
		moc_OthelloGame.o \
		moc_Player.o \
		moc_StartButton.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Othello.pro
QMAKE_TARGET  = Othello
DESTDIR       = 
TARGET        = Othello

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Othello.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile Othello.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile Othello.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Othello1.0.0 || $(MKDIR) .tmp/Othello1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Othello1.0.0/ && $(COPY_FILE) --parents src/AIMobility.h src/AIPlayer.h src/BoardInterface.h src/BoardLayout.h src/Cell.h src/defines.h src/Human.h src/OthelloAction.h src/OthelloBoard.h src/OthelloGame.h src/OthelloSearchNode.h src/Player.h src/StartButton.h src/Tools.hpp .tmp/Othello1.0.0/ && $(COPY_FILE) --parents src/AIMobility.cpp src/AIPlayer.cpp src/BoardLayout.cpp src/Cell.cpp src/Human.cpp src/Othello.cpp src/OthelloAction.cpp src/OthelloBoard.cpp src/OthelloGame.cpp src/OthelloSearchNode.cpp src/StartButton.cpp .tmp/Othello1.0.0/ && (cd `dirname .tmp/Othello1.0.0` && $(TAR) Othello1.0.0.tar Othello1.0.0 && $(COMPRESS) Othello1.0.0.tar) && $(MOVE) `dirname .tmp/Othello1.0.0`/Othello1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Othello1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_AIPlayer.cpp moc_BoardLayout.cpp moc_Cell.cpp moc_Human.cpp moc_OthelloGame.cpp moc_Player.cpp moc_StartButton.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_AIPlayer.cpp moc_BoardLayout.cpp moc_Cell.cpp moc_Human.cpp moc_OthelloGame.cpp moc_Player.cpp moc_StartButton.cpp
moc_AIPlayer.cpp: src/Player.h \
		src/defines.h \
		src/OthelloBoard.h \
		src/BoardInterface.h \
		src/OthelloSearchNode.h \
		src/AIPlayer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/AIPlayer.h -o moc_AIPlayer.cpp

moc_BoardLayout.cpp: src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/Cell.h \
		src/BoardLayout.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h \
		src/BoardLayout.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/BoardLayout.h -o moc_BoardLayout.cpp

moc_Cell.cpp: src/BoardLayout.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h \
		src/Cell.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/Cell.h -o moc_Cell.cpp

moc_Human.cpp: src/Player.h \
		src/defines.h \
		src/Human.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/Human.h -o moc_Human.cpp

moc_OthelloGame.cpp: src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h \
		src/OthelloGame.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/OthelloGame.h -o moc_OthelloGame.cpp

moc_Player.cpp: src/defines.h \
		src/Player.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/Player.h -o moc_Player.cpp

moc_StartButton.cpp: src/BoardLayout.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h \
		src/StartButton.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/StartButton.h -o moc_StartButton.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

AIMobility.o: src/AIMobility.cpp src/AIMobility.h \
		src/AIPlayer.h \
		src/Player.h \
		src/defines.h \
		src/OthelloBoard.h \
		src/BoardInterface.h \
		src/OthelloSearchNode.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/StartButton.h \
		src/Tools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AIMobility.o src/AIMobility.cpp

AIPlayer.o: src/AIPlayer.cpp src/AIPlayer.h \
		src/Player.h \
		src/defines.h \
		src/OthelloBoard.h \
		src/BoardInterface.h \
		src/OthelloSearchNode.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/StartButton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AIPlayer.o src/AIPlayer.cpp

BoardLayout.o: src/BoardLayout.cpp src/BoardLayout.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BoardLayout.o src/BoardLayout.cpp

Cell.o: src/Cell.cpp src/Cell.h \
		src/BoardLayout.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Cell.o src/Cell.cpp

Human.o: src/Human.cpp src/Human.h \
		src/Player.h \
		src/defines.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/OthelloBoard.h \
		src/BoardInterface.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/StartButton.h \
		src/Tools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Human.o src/Human.cpp

Othello.o: src/Othello.cpp src/OthelloGame.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/StartButton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Othello.o src/Othello.cpp

OthelloAction.o: src/OthelloAction.cpp src/OthelloAction.h \
		src/OthelloGame.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/StartButton.h \
		src/Tools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OthelloAction.o src/OthelloAction.cpp

OthelloBoard.o: src/OthelloBoard.cpp src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/StartButton.h \
		src/AIMobility.h \
		src/AIPlayer.h \
		src/OthelloSearchNode.h \
		src/Human.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OthelloBoard.o src/OthelloBoard.cpp

OthelloGame.o: src/OthelloGame.cpp src/OthelloGame.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/StartButton.h \
		src/AIMobility.h \
		src/AIPlayer.h \
		src/OthelloSearchNode.h \
		src/Human.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OthelloGame.o src/OthelloGame.cpp

OthelloSearchNode.o: src/OthelloSearchNode.cpp src/OthelloSearchNode.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/OthelloAction.h \
		src/OthelloGame.h \
		src/BoardLayout.h \
		src/Cell.h \
		src/StartButton.h \
		src/Tools.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OthelloSearchNode.o src/OthelloSearchNode.cpp

StartButton.o: src/StartButton.cpp src/StartButton.h \
		src/BoardLayout.h \
		src/OthelloBoard.h \
		src/defines.h \
		src/Player.h \
		src/BoardInterface.h \
		src/Cell.h \
		src/OthelloAction.h \
		src/OthelloGame.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o StartButton.o src/StartButton.cpp

moc_AIPlayer.o: moc_AIPlayer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AIPlayer.o moc_AIPlayer.cpp

moc_BoardLayout.o: moc_BoardLayout.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BoardLayout.o moc_BoardLayout.cpp

moc_Cell.o: moc_Cell.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Cell.o moc_Cell.cpp

moc_Human.o: moc_Human.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Human.o moc_Human.cpp

moc_OthelloGame.o: moc_OthelloGame.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_OthelloGame.o moc_OthelloGame.cpp

moc_Player.o: moc_Player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_Player.o moc_Player.cpp

moc_StartButton.o: moc_StartButton.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_StartButton.o moc_StartButton.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

