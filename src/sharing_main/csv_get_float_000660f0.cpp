/* HSTMATCH module=hstp_trans_main.prx start=0x000660f0 end=0x000661a0 symbol=FUN_000660f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* csv_reader.cpp (debug build): the float value of cell (row, column). Two asserts from the retail
   strings: "row < GetNumRow()" (line 204, this function's string pool at 0x377108) and
   "column < GetNumColumn(row)" (line 210; its strings sit in the inline-function pool at 0x2cc4a0, so
   it is written inside the inline GetCell); the cell's value comes from its third virtual (slot +16). */
extern "C" {
extern char DAT_00377108[];
extern char DAT_00377134[];
extern char DAT_00377148[];
extern char DAT_002cc4cc[];
extern char DAT_002cc4b0[];
extern char DAT_002cc4a0[];
void FUN_0006600c(const char *fmt, ...);
}

#define ASSERT(c, fmt, text, file, line) \
    if (!(c)) { FUN_0006600c(fmt, text, file, line); for (;;) {} }

struct Cell {
    virtual void v0();
    virtual void v1();
    virtual float GetFloat();
};

struct Row {
    Cell **cells;
    int count;
    int pad8;
};

struct CsvReader {
    int f0;
    Row *rows;
    int nrows;
    int GetNumRow() const { return nrows; }
    const Row &GetRow(int row) const { return rows[row]; }
    int GetNumColumn(int row) const { return GetRow(row).count; }
    Cell *GetCell(int row, int column) const
    {
        ASSERT(column < GetNumColumn(row), DAT_002cc4cc, DAT_002cc4b0, DAT_002cc4a0, 210);
        return GetRow(row).cells[column];
    }
};

extern "C" float FUN_000660f0(CsvReader *self, int row, int column)
{
    ASSERT(row < self->GetNumRow(), DAT_00377108, DAT_00377134, DAT_00377148, 204);
    return self->GetCell(row, column)->GetFloat();
}
