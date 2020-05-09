
extern int sqlite3_demo(const char* db_filename);

int main(int argc, char* argv[]) {
  const char* db_filename = "data/test.db";

  return sqlite3_demo(db_filename);
}
