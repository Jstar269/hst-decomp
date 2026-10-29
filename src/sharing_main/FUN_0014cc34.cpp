/* HSTMATCH module=hstp_trans_main.prx start=0x0014cc34 end=0x0014cd64 symbol=FUN_0014cc34 lang=c++ */
/* Clone of src/eboot/FUN_001415e8.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: the open result is a callee returning unsigned char tested with an explicit != 0 (gives retail's andi 0xff and keeps the CSV-values block first); exact match verified; names and types await human review. */
struct CsvFile { int pad[4]; };

extern "C" {
void FUN_00065884(CsvFile *);
unsigned char FUN_00065ab8(CsvFile *, const char *, int, const char *);
int FUN_00065fa4(CsvFile *);
float FUN_000660f0(CsvFile *, int, int);
void FUN_000658cc(CsvFile *, int);
}

extern const char DAT_00382d94[];

struct Obj {
    char pad0[0x1300];
    float min_a;
    float max_a;
    float min_b;
    float max_b;
    float max_c;
    float min_c;
};

/* Loads one row of the area-clip table into three min/max pairs; falls back to +-3, +-3, +-1000 when the file or row is missing. */
extern "C" void FUN_0014cc34(Obj *self, int row, const char *name)
{
    CsvFile csv;

    FUN_00065884(&csv);
    if (FUN_00065ab8(&csv, name, 1, DAT_00382d94) != 0 && FUN_00065fa4(&csv) > row) {
        self->min_a = -FUN_000660f0(&csv, row, 1);
        self->max_a = -FUN_000660f0(&csv, row, 0);
        self->min_b = FUN_000660f0(&csv, row, 2);
        self->max_b = FUN_000660f0(&csv, row, 3);
        self->min_c = FUN_000660f0(&csv, row, 4);
        self->max_c = FUN_000660f0(&csv, row, 5);
    } else {
        self->min_a = -3.0f;
        self->max_a = 3.0f;
        self->min_b = -3.0f;
        self->max_b = 3.0f;
        self->min_c = -1000.0f;
        self->max_c = 1000.0f;
    }
    FUN_000658cc(&csv, -1);
}
