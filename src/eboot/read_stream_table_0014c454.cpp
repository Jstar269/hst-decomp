/* HSTMATCH module=EBOOT.BIN start=0x0014c454 end=0x0014c610 symbol=FUN_0014c454 lang=c++ */
/* Hand-written reconstruction: C++ Table with inline constructor, unrolled loops off, and inline push_back with empty tag temporary for frame size; exact match verified; names and types await human review. */

#pragma opt_unroll_loops off

struct Entry {
    int id;
    void *item;
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
extern char DAT_002dc174;
extern char DAT_002dc17c[];
extern char DAT_002dc1a4[];
extern char DAT_002dc1d0[];

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

extern "C" Table *FUN_0014c454(void *param_1, unsigned param_2, int param_3)
{
    unsigned local_4 = param_2;
    unsigned end = param_2 + param_3;

    if (FUN_00014a58(param_2, &DAT_002dc174, 4) != 0) {
        FUN_0014c610(DAT_002dc17c, local_4);
        return 0;
    }

    local_4 += 4;
    int v1 = FUN_0014f03c(&local_4);
    if (v1 != 1) {
        FUN_0014c610(DAT_002dc1a4, v1);
        return 0;
    }

    int v2 = FUN_0014f03c(&local_4);
    if (v2 != param_3) {
        FUN_0014c610(DAT_002dc1d0, v2, param_3);
        return 0;
    }

    local_4 += 4;
    Table *t = new Table;

    while (local_4 < end) {
        Res *r = FUN_0014c63c(param_1, &local_4);
        Entry e;
        e.id = r->id;
        e.item = r;
        push_back(t, e, Tag());
    }

    return t;
}
