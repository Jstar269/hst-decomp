/* HSTMATCH module=hstp_trans_main.prx start=0x00066a84 end=0x00066bb0 symbol=FUN_00066a84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* csv_reader.cpp (assert strings): look a row up by name in the name->row map (find 0x670b4 returns the iterator by value), assert the row/column bounds and return the cell's value through its slot-1 virtual. Shape notes: the iterator has a user default ctor and a memberwise copy ctor, and the inline find() returns a named copy; that pair gives retail's frame (iterator at sp+20, an unwritten slot at sp+24). Names provisional. */
extern const char DAT_00377108[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00377134[];   /* "row < GetNumRow()" */
extern const char DAT_00377148[];   /* "csv_reader.cpp" */
extern const char DAT_00377158[];   /* "false" */
extern const char DAT_002cc4cc[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_002cc4b0[];   /* "column < GetNumColumn(row)" */
extern const char DAT_002cc4a0[];   /* "csv_reader.cpp" */
extern "C" void FUN_0006600c(...);
#define HST_ASSERT(cond, fmt, text, file, line) do { if (!(cond)) { FUN_0006600c(fmt, text, file, line); for (;;) {} } } while (0)

struct Node { Node *l; Node *r; unsigned parent; const char *key; int value; };
struct Iter {
    Node *n;
    Iter() {}
    Iter(const Iter &o) : n(o.n) {}
    bool operator!=(const Iter &o) const { return n != o.n; }
};
struct Tree;
extern "C" Iter FUN_000670b4(Tree *t, const char *const &key);
struct Tree {
    int pad0;
    Node *root;
    Iter find(const char *const &key) { Iter r = FUN_000670b4(this, key); return r; }
    Iter end() { Iter e; e.n = (Node *)&root; return e; }
};

struct Cell {
    virtual void d0();
    virtual int Get();
};

struct Row {
    Cell **cells;
    int count;
    int cap;
};

struct Csv {
    int pad0;
    Row *rows;      /* 0x04 */
    int numRows;    /* 0x08 */
    int pad0c;
    Tree index;     /* 0x10 */

    int GetNumRow() const { return numRows; }
    int FindRow(const char *name)
    {
        Iter it = index.find(name);
        int r;
        if (it != index.end()) r = it.n->value;
        else r = -1;
        return r;
    }
    Cell *GetCell(int row, int column)
    {
        HST_ASSERT(row < GetNumRow(), DAT_00377108, DAT_00377134, DAT_00377148, 0xcc);
        Row *r = &rows[row];
        HST_ASSERT(column < r->count, DAT_002cc4cc, DAT_002cc4b0, DAT_002cc4a0, 0xd2);
        return r->cells[column];
    }
};

extern "C" int FUN_00066a84(Csv *self, const char *name, int column)
{
    int row = self->FindRow(name);
    if (row >= 0 && column >= 0)
        return self->GetCell(row, column)->Get();
    HST_ASSERT(false, DAT_00377108, DAT_00377158, DAT_00377148, 0x160);
}
