/* HSTMATCH module=hstp_trans_main.prx start=0x00066bb0 end=0x00066cdc symbol=FUN_00066bb0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* csv_reader.cpp: look a row up by its key (C-string map find 0x670b4, -1 when absent), assert row/column are
   valid ("false", line 362), and return the cell through its third virtual (slot 2; return type unknown, int
   assumed). GetNumColumn/GetCell are the inline accessors whose assertions (lines 204 and 210) expand here. */
extern "C" {
void FUN_0006600c(...);
extern char DAT_00377108[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern char DAT_00377134[]; /* "row < GetNumRow()" */
extern char DAT_00377148[]; /* "csv_reader.cpp" */
extern char DAT_00377158[]; /* "false" */
extern char DAT_002cc4a0[]; /* "csv_reader.cpp" */
extern char DAT_002cc4b0[]; /* "column < GetNumColumn(row)" */
extern char DAT_002cc4cc[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
}

struct Cell {
  virtual ~Cell();
  virtual int GetInt();
  virtual int GetValue2(); /* slot 2 */
  virtual const char *GetString();
};
struct Row {
  Cell **data;
  int size;
  int cap;
};
struct MapNode {
  MapNode *left;
  MapNode *right;
  unsigned parent;
  const char *key;
  int data;
};
struct MapIt {
  MapNode *node;
  MapIt() {}
};
struct Map;
extern "C" void FUN_000670b4(MapIt *r, Map *m, const char *const &key);
struct MapHeader {
  MapNode *root;
  MapNode *left;
  MapNode *right;
};
struct Map {
  int size;
  MapHeader header;
  MapNode *end() { return (MapNode *)&header; }
  MapIt find(const char *const &key)
  {
    MapIt it;
    FUN_000670b4(&it, this, key);
    return it;
  }
};

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
    Row *r = rows + row;
    return r->size;
  }
  Cell *GetCell(int row, int column)
  {
    if (!(column < GetNumColumn(row))) {
      FUN_0006600c(DAT_002cc4cc, DAT_002cc4b0, DAT_002cc4a0, 210);
      for (;;) {
      }
    }
    return rows[row].data[column];
  }
  int FindRow(const char *key)
  {
    MapIt it = rowIndex.find(key);
    return it.node != rowIndex.end() ? it.node->data : -1;
  }
};

extern "C" int FUN_00066bb0(CsvReader *self, const char *rowKey, int column)
{
  int row = self->FindRow(rowKey);
  if (row >= 0 && column >= 0) {
    return self->GetCell(row, column)->GetValue2();
  }
  FUN_0006600c(DAT_00377108, DAT_00377158, DAT_00377148, 362);
  for (;;) {
  }
}
