#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Model3d.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/Stairs.o \
	${OBJECTDIR}/src/math3d.o \
	${OBJECTDIR}/src/GLScene.o \
	${OBJECTDIR}/src/SkyBox.o \
	${OBJECTDIR}/src/Train.o \
	${OBJECTDIR}/src/Studio.o \
	${OBJECTDIR}/src/MyScene.o \
	${OBJECTDIR}/src/Cylinder.o \
	${OBJECTDIR}/src/Railway.o \
	${OBJECTDIR}/src/Drawable.o \
	${OBJECTDIR}/src/Ground.o \
	${OBJECTDIR}/src/Box.o \
	${OBJECTDIR}/src/Arch.o \
	${OBJECTDIR}/src/Sphere.o \
	${OBJECTDIR}/src/Light.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lGLU -lGL -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio `pkg-config --libs assimp` `pkg-config --libs openal`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/metro-simulation

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/metro-simulation: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/metro-simulation ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/Model3d.o: src/Model3d.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Model3d.o src/Model3d.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Stairs.o: src/Stairs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Stairs.o src/Stairs.cpp

${OBJECTDIR}/src/math3d.o: src/math3d.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/math3d.o src/math3d.cpp

${OBJECTDIR}/src/GLScene.o: src/GLScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GLScene.o src/GLScene.cpp

${OBJECTDIR}/src/SkyBox.o: src/SkyBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/SkyBox.o src/SkyBox.cpp

${OBJECTDIR}/src/Train.o: src/Train.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Train.o src/Train.cpp

${OBJECTDIR}/src/Studio.o: src/Studio.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Studio.o src/Studio.cpp

${OBJECTDIR}/src/MyScene.o: src/MyScene.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MyScene.o src/MyScene.cpp

${OBJECTDIR}/src/Cylinder.o: src/Cylinder.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Cylinder.o src/Cylinder.cpp

${OBJECTDIR}/src/Railway.o: src/Railway.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Railway.o src/Railway.cpp

${OBJECTDIR}/src/Drawable.o: src/Drawable.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Drawable.o src/Drawable.cpp

${OBJECTDIR}/src/Ground.o: src/Ground.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Ground.o src/Ground.cpp

${OBJECTDIR}/src/Box.o: src/Box.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Box.o src/Box.cpp

${OBJECTDIR}/src/Arch.o: src/Arch.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Arch.o src/Arch.cpp

${OBJECTDIR}/src/Sphere.o: src/Sphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Sphere.o src/Sphere.cpp

${OBJECTDIR}/src/Light.o: src/Light.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude `pkg-config --cflags assimp` `pkg-config --cflags openal`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Light.o src/Light.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/metro-simulation

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
