/* HSTMATCH module=EBOOT.BIN start=0x0014c454 end=0x0014c610 symbol=FUN_0014c454 lang=c++ data=0x002dc174 */
/* Hand-written reconstruction: C++ Table with inline constructor, unrolled loops off, and inline push_back with empty tag temporary for frame size; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002dc174-0x002dc208) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

#pragma opt_unroll_loops off

/* Version of the script data format that is accepted. */
enum { SCRIPT_DATA_VERSION = 1 };

struct Entry {
    int id;
    void *item; /* loaded module resource */
};

void *operator new(unsigned size);

struct Table {
    Entry *entries;
    int size;
    int capacity;
    int arr1[64];
    int arr2[64];

    Table() : entries(0), size(0), capacity(0) {
        for (unsigned i = 0; i < 64; ++i) {
            arr1[i] = 0;
        }
        for (unsigned i = 0; i < 64; ++i) {
            arr2[i] = 0;
        }
    }
};

struct Res {
    char pad[12];
    int id;
};

struct Tag {};

extern "C" {

int FUN_00014a58(unsigned ptr, const void *sig, int len);
void FUN_0014c610(const char *fmt, ...);
int FUN_0014f03c(unsigned *ptr);
Res *FUN_0014c63c(void *ctx, unsigned *ptr);
void FUN_0014f0d8(Table *t, const Entry *e, Tag = Tag());
}

inline void push_back(Table *t, const Entry &e, Tag) {
    if ((unsigned)t->size < (unsigned)t->capacity) {
        Entry *slot = &t->entries[t->size];
        if (slot != 0) {
            *slot = e;
        }
        t->size++;
    } else {
        FUN_0014f0d8(t, &e, Tag());
    }
}

/* Read a script data file ("ESD " header, version, size) into a table of modules keyed by id; 0 on a bad header. */
extern "C" Table *FUN_0014c454(void *ctx, unsigned data, int size)
{
    unsigned cursor = data;
    unsigned end = data + size;

    if (FUN_00014a58(data, "ESD ", 4) != 0) {
        FUN_0014c610("error! Script data code is wrong -> %s\n", cursor);
        return 0;
    }

    cursor += 4;
    int version = FUN_0014f03c(&cursor);
    if (version != SCRIPT_DATA_VERSION) {
        FUN_0014c610("error! Script data version is wrong -> %d\n", version);
        return 0;
    }

    int storedSize = FUN_0014f03c(&cursor);
    if (storedSize != size) {
        FUN_0014c610("error! Script data size is wrong -> (data:%d, file:%d)\n", storedSize, size);
        return 0;
    }

    cursor += 4;
    Table *table = new Table;

    while (cursor < end) {
        Res *res = FUN_0014c63c(ctx, &cursor);
        Entry entry;
        entry.id = res->id;
        entry.item = res;
        push_back(table, entry, Tag());
    }

    return table;
}
