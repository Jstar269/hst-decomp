/* HSTMATCH module=EBOOT.BIN start=0x00053b04 end=0x00053e08 symbol=FUN_00053b04 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
struct IntVec;
struct PtrVec;
extern "C" {
void FUN_00054510(IntVec *, const int *, Tag);
void FUN_000545bc(PtrVec *, int *const *, Tag);
void FUN_00054554(IntVec *, int);
}
struct IntVec {
    int *data;
    unsigned size;
    unsigned cap;
    void grow(const int &v, Tag t) { FUN_00054510(this, &v, Tag()); }
    void push_back(const int &x) {
        if (size < cap) {
            size++;
            data[size - 1] = x;
        } else {
            grow(x, Tag());
        }
    }
};
struct LocalVec : IntVec {
    void push_back(const int &x, Tag t) { if (size < cap) { size++; data[size - 1] = x; } else grow(x, t); }
    using IntVec::push_back;
    int &operator[](unsigned i) { return data[i]; }
    LocalVec() { data = 0; size = 0; cap = 0; }
    ~LocalVec() { FUN_00054554(this, 0); }
};
struct PtrVec {
    int **data;
    unsigned size;
    unsigned cap;
    void grow(int *const &v, Tag t) { FUN_000545bc(this, &v, Tag()); }
    void push_back(int *const &x) {
        if (size < cap) {
            size++;
            data[size - 1] = x;
        } else {
            grow(x, Tag());
        }
    }
};
struct Node {
    char pad[0x18];
    int *name;
    int handle;
};
struct Group {
    struct Hdr { char pad[8]; unsigned short count; } *hdr;
};
struct Owner {
    char pad[8];
    char *list;
    char pad2[8];
    unsigned char done;
    char pad3[3];
    IntVec handles;
    PtrVec names;
};
struct Str { char buf[128]; };
struct Pair { int *a; int *b; };
extern char DAT_00311170[];
extern "C" {
void FUN_00049194();
void FUN_000491cc();
int FUN_0002e840(char *);
Group *FUN_0002e650(char *, int);
int FUN_0002e40c(Group *);
Node **FUN_0002e3d0(Group *, int);
void FUN_000149a8(void *, int *);
char *FUN_00014d64(Str *, int *);
int FUN_00014934(char *, int *);
int FUN_0004f6b4(char *, Str *, int, int, int, int, int, int);
void FUN_0004fe04(char *, int);
}

extern "C" void FUN_00053b04(Owner *self, int a, Pair *p, int b)
{
    if (self->list) {
        LocalVec old;
        FUN_00049194();
        int g;
        char *list = self->list + 0x10;
        int ng = FUN_0002e840(list);
        for (g = 0; g < ng; g++) {

            Group *grp = FUN_0002e650(list, g);
            int nn = FUN_0002e40c(grp);
            for (int i = 0; i < nn; i++) {
                Node *node = *FUN_0002e3d0(grp, i);
                Str s;
                FUN_000149a8(&s, node->name);
                char *hit = FUN_00014d64(&s, p->a);
                if (hit && !FUN_00014934(hit, p->a)) {
                    FUN_000149a8(hit, p->b);
                    FUN_000491cc();
                    int h = FUN_0004f6b4(DAT_00311170, &s, a, 0, 0, b, 0x40, 0);
                    self->handles.push_back(h);
                    self->names.push_back(node->name);
                    int prev = node->handle;
                    for (int j = 0; j < old.size; j++) {
                        if (prev == old[j]) {
                            prev = -1;
                            break;
                        }
                    }
                    if (prev >= 0)
                        old.push_back(prev, Tag());
                    node->handle = h;
                    FUN_00049194();
                }
            }
            grp->hdr->count++;
        }
        FUN_000491cc();
        for (int j = 0; j < old.size; j++)
            FUN_0004fe04(DAT_00311170, old[j]);
        self->done = 1;
    }
}
