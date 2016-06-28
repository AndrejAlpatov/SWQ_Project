# Hello Googlemock Project

Welcome to the "Hello Googlemock" project - a small example of using [Google
Test](https://github.com/google/googletest/blob/master/README.md) and [Google
Mock](https://github.com/google/googletest/blob/master/googlemock/README.md) as
an [xUnit]( https://en.wikipedia.org/wiki/XUnit) like [Unit
Testing](https://en.wikipedia.org/wiki/Unit_testing) framework in a `qmake`
based C++ project.

--------------------------------------------------------------

## Contents

- Hello Googlemock Project
  - [Intention](#intention)
  - [Features](#features)
  - [Quickstart](#quickstart)
  - [Links](#links)
  - [License](#license)
- [Project Structure](#projectstructure)
  - [Directories](#directories)
  - [Documentation](#documentation)
- [Build Instructions](#buildinstructions)
  - [Prerequisites](#prerequisites)
  - [Installing QT](#installingqt)
  - [Checking out the code](#checkingoutthecode)
  - [Preparations](#preparations)
  - [Building the application and the unit test program](#building)
  - [Cleaning the build directory](#cleaning)

--------------------------------------------------------------

## Intention<a name=intention></a>

- simple project base
- Google Mock evalation environment

## Features<a name=features></a>

- portable C++ (Linux, Windows, OS X), due to
- `qmake` project based build environment
- multi directory project layout supports building libraries
- GoogleTest xUnit-like unit test environment
- GoogleMock supporting
- Open Source License (GPLv3)

## Quickstart<a name=quickstart></a>

## Links<a name=links></a>
- [Project Home](
  https://atlas.ai.it.hs-worms.de/bitbucket/projects/TST/repos/googlemock-hello)
- [Qt](http://www.qt.io)
- [Google Test & Google Mock](https://github.com/google/googletest)
- [Doxygen](http://www.stack.nl/~dimitri/doxygen)
- [Git](https://git-scm.com/)

## License<a name=license></a>
- Code: GPLv3
- Documentation: CC BY SA

--------------------------------------------------------------

# Project Structure<a name=projectstructure></a>

## Directories<a name=directories></a>

## Documentation<a name=documentation></a>

--------------------------------------------------------------

# Build Instructions<a name=buildinstructions></a>

## Prerequisites:<a name=prerequisites></a>
- QT 5.2 or later
  - download version for your environment from
    http://www.qt.io/download-open-source/

## Installing QT:<a name=installingqt></a>
This is only one way that worked on Ubuntu 14.04 - if in doubt, follow
the instructions on http://qt-project.org

- E.g. download the Qt Online Installer for Linux (32-bit or 64-bit,
  depending on your system); for me (with Qt 5.1), the file name was
  `qt-linux-opensource-1.4.0-2-x86_64-online.run`. Adapt the following to
  the current file name.

      chmod +x qt-linux-opensource-1.4.0-2-x86_64-online.run
      sudo qt-linux-opensource-1.4.0-2-x86_64-online.run
      PATH=/opt/Qt/5.3/gcc_64/bin:$PATH	# adapt to your needs,
      					# put it into $HOME/.profile or similar

## Checking out the code:<a name=checkingoutthecode></a>
You can check out the code (and binary libraries) with a command similar
to:

    git clone https://infXXXX@atlas.ai.it.fh-worms.de/bitbucket/scm/tst/googlemock-hello.git

## Preparations:<a name=preparations></a>
Generate your platform specific build environment using cmake started
from a command line prompt (bash on Linux / Mac OS X; cmd or PowerShell
or Cygwin on Windows):

    cd build
    qmake ../src/hello-googlemock.pro CONFIG+=debug	# generates Makefile

Visual Studio (not yet tested):

    cd build
    qmake -tp vc ../src/hello-googlemock.pro	# should create Visual Studio project!?

## Building the application and the unit test program:<a name=building></a>
    cd build      # only if not already there
    make          # generates all
    ./helloworld  # enjoy the famous program
    ./unit-test   #
    make clean    # optionally, remove all temporary files

## Cleaning the build directory:<a name=cleaning></a>
- initially the build directory is empty, so all files there are
  generated by the build - and if you didn't save anything there, you
  can safely remove all files by using rm
- alternatively, just remove the files built by 'make':

      cd build		# only if not already there
      make clean		# optionally, remove all temporary files
      make distclean		# as clean, but removes also libs and Makefiles

