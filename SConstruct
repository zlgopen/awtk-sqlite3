import os
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS);

APP_LIBS=['sqlite3']
helper.add_libs(APP_LIBS).call(DefaultEnvironment)

helper.SConscript(['src/SConscript', 'demos/SConscript'])
