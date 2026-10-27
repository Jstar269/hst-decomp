/* HSTMATCH module=hstp_trans_main.prx start=0x00066260 end=0x00066384 symbol=FUN_00066260 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* csv_reader.cpp: read the table (0x65ab8), then optionally index the first column (row keys -> row number) and the
   first row (column keys -> column number) into two C-string maps through insert_unique 0x676d4. GetNumColumn is
   the inline whose "row < GetNumRow()" assertion (line 204) is expanded in the column loop's test. */
extern "C" {
void FUN_0006600c(...);
extern char DAT_00377108[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00377134[]; /* "row < GetNumRow()" */
extern char DAT_00377148[]; /* "csv_reader.cpp" */
}

struct Cell;
struct Row {
  Cell **data;
  int size;
  int cap;
};
struct Key {
  const char *key;
  int data;
};
struct Res {
  void *node;
  bool inserted;
};
struct Map {
  int f[4];
};
struct CsvReader;
extern "C" {
int FUN_00065ab8(CsvReader *self, void *src, int a, void *b);
const char *FUN_000661a8(CsvReader *self, int row, int column);
void FUN_000676d4(Res *r, Map *m, const Key &v);
}

struct CsvReader {
  void *vptr;
  Row *rows;
  int numRow;
  int capRow;
  Map rowIndex;
  Map columnIndex;

  int GetNumRow() { return numRow; }
  int GetNumColumn(int row)
  {
    if (!(row < GetNumRow())) {
      FUN_0006600c(DAT_00377108, DAT_00377134, DAT_00377148, 204);
      for (;;) {
      }
    }
    return rows[row].size;
  }
};

extern "C" int FUN_00066260(CsvReader *self, void *src, int rowIndex, int columnIndex, void *opt)
{
  if (!FUN_00065ab8(self, src, 0, opt)) {
    return 0;
  }
  if (rowIndex) {
    for (int i = 0; i < self->GetNumRow(); i++) {
      Res r;
      Key k;
      k.key = FUN_000661a8(self, i, 0);
      k.data = i;
      FUN_000676d4(&r, &self->rowIndex, k);
    }
  }
  if (columnIndex) {
    for (int i = 0; i < self->GetNumColumn(0); i++) {
      Res r;
      Key k;
      k.key = FUN_000661a8(self, 0, i);
      k.data = i;
      FUN_000676d4(&r, &self->columnIndex, k);
    }
  }
  return 1;
}
