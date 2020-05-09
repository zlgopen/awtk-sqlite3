#include "sqlite3.h"
#include "tkc/types_def.h"

static int dump_table(void* data, int argc, char** argv, char** azColName) {
  int i;
  log_info("%s: ", (const char*)data);

  for (i = 0; i < argc; i++) {
    log_info("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  log_info("\n");
  return 0;
}

int sqlite3_demo(const char* db_filename) {
  int rc = 0;
  sqlite3* db = NULL;
  char* zErrMsg = NULL;
  
  sqlite3_initialize();

  rc = sqlite3_open(db_filename, &db);
  if (rc) {
    log_warn("Can't open database: %s\n", sqlite3_errmsg(db));
  } else {
    const char* sql = "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sql, dump_table, (void*)"dump", &zErrMsg);

    if (rc != SQLITE_OK) {
      log_info("SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    } else {
      log_info("Operation done successfully\n");
    }
    log_warn("Opened database successfully:%s\n", db_filename);
  }
  sqlite3_close(db);

	return 0;
}
