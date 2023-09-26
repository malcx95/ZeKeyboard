import os

# Where arduino is installed.
ARDUINO_DIR         = '/usr/share/arduino'
ARDUINO_USER_DIR    = os.environ['HOME']+'/Arduino'

# Set this to './libraries' or something similar,
# if there is a libraries folder in project folder
LOCAL_LIBRARIES_DIR = None

# Libraries to include
LIBRARIES = ['SoftwareSerial']

ARDUINO_CORES_DIR   = ARDUINO_DIR+'/hardware/arduino/'
# Uncomment this line if you are using Arch Linux.
# ARDUINO_CORES_DIR = ARDUINO_DIR+'/hardware/archlinux-arduino/'

INCLUDE_DIRS = [\
        ARDUINO_CORES_DIR+'/avr/cores/arduino/',
        ARDUINO_CORES_DIR+'/avr/variants/standard/',
        ]

CXXFLAGS            = ['-x','c++','-Wall','-Wextra','-Werror']

# ------------------------------------------------------------------------------

_libraries_dir_sys  = ARDUINO_CORES_DIR+'/avr/libraries'
_libraries_dir_user = ARDUINO_USER_DIR+'/libraries'

import pathlib

for lib in LIBRARIES:
    if LOCAL_LIBRARIES_DIR is not None:
        lib_candidates += [LOCAL_LIBRARIES_DIR+'/'+lib]

    lib_candidates = [_libraries_dir_sys+'/'+lib,
                      _libraries_dir_user+'/'+lib,
                     ]

    for lib_candidate in lib_candidates:
        if pathlib.Path(lib_candidate).is_dir:
            INCLUDE_DIRS += [lib_candidate]
            break
    else:
        print("Library {} not found.".format(lib))
        exit(-1)


def FlagsForFile(filename, **kwargs):
    flags = []
    for include_dir in INCLUDE_DIRS:
        flags+=['-I'+include_dir]
    flags += CXXFLAGS
    return {
        'flags' : flags
    }


