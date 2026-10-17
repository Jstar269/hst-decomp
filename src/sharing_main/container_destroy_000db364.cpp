/* HSTMATCH module=hstp_trans_main.prx start=0x000db364 end=0x000db490 symbol=FUN_000db364 lang=c++ */
/* Clone of src/eboot/container_destroy_000d7674.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
struct Alloc {};
struct Vec3 {
    char *data;
    int size;
    int x;
    void shrink(int n, Alloc) { size -= n; }
    ~Vec3() { int n = size; shrink(n, Alloc()); if (data) operator delete(data); }
};
struct W3 { Vec3 v; };
struct W2 { W3 w; };
typedef W2 W1;
struct Base {
    unsigned flags;
    int pad;
    char *p8;
    ~Base() { if (flags & 1) delete p8; }
};
struct Elem : Base {
    W1 sub;
};
struct Vec {
    Elem *data;
    int size;
    int pad[2];
    int start;
};
extern "C" int FUN_000db5b0(Vec *);

extern "C" Vec *FUN_000db364(Vec *self, short flag)
{
    if (self != 0) {
        Elem *first = self->data + self->start;
        Elem *last = first + self->size;
        if (first < last) {
            do {
                last--;
                last->~Elem();
            } while (first < last);
        }
        self->size = 0;
        if (self != 0) {
            FUN_000db5b0(self);
            if (self->data != 0) operator delete(self->data);
        }
        if (0 < flag) operator delete(self);
    }
    return self;
}
