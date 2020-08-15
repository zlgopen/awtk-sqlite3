import os
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS);

APP_LIBS=['sqlite3']
APP_CCFLAGS = '-DWITH_RAM_DISK '
helper.add_libs(APP_LIBS).add_ccflags(APP_CCFLAGS).call(DefaultEnvironment)

SConscript(['src/SConscript', 'demos/SConscript'])
