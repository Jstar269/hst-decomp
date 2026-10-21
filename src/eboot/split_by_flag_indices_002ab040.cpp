/* HSTMATCH module=EBOOT.BIN start=0x002ab040 end=0x002ab180 symbol=FUN_002ab040 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: register loop counter k kept beside the address-taken push value idx (k = idx + 1; idx = k) so the counter lives in s2; clear loop via int n = size; shrink(n, Alloc()); names and types await human review. */
struct Tag {};
struct Alloc {};
struct IntVec;
extern "C" void FUN_00054510(IntVec *, const int *, Tag);
struct IntVec {
    int *data;
    unsigned size;
    unsigned cap;
    void push_back(const int &x, Tag) {
        if (size < cap) {
            size++;
            data[size - 1] = x;
        } else {
            FUN_00054510(this, &x, Tag());
        }
    }
    void shrink(int n, Alloc) { size -= n; }
};
struct Item {
    char pad[0xd8];
    unsigned char flag;
};
struct Obj {
    char pad[0x30ec];
    IntVec vec[2];
};
extern char *DAT_003415a8;
extern "C" {
int FUN_002af31c(char *);
Item *FUN_002af32c(char *, int);
}

extern "C" void FUN_002ab040(Obj *self)
{
    int i = 0;
    do {
        int n = self->vec[i].size;
        self->vec[i].shrink(n, Alloc());
        i++;
    } while (i < 2);
    char *list = DAT_003415a8 + 0x87128;
    int idx = 0;
    int k = 0;
    if (FUN_002af31c(list) > 0) {
        do {
            Item *it = FUN_002af32c(list, k);
            if (it->flag != 0) {
                self->vec[0].push_back(idx, Tag());
            } else {
                self->vec[1].push_back(idx, Tag());
            }
            k = idx + 1;
            idx = k;
        } while (k < FUN_002af31c(list));
    }
}
