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
/* Leaf entry: its name at +0x18 and the handle currently bound to it. */
struct Node {
    char pad[0x18];
    int *name;   /* 0x18 */
    int handle;  /* 0x1c */
};
struct Group {
    struct Hdr { char pad[8]; unsigned short count; } *hdr;
};
#define LIST_HEAD_OFFSET 0x10 /* the nested list starts this far into the list member */
#define BAD_HANDLE (-1)
#define REBIND_LOAD_ARG 0x40

/* Owner of a nested name list plus the handles and names of the entries rebound so far. */
struct Owner {
    char pad[8];
    char *list;          /* 0x08 */
    char pad2[8];
    unsigned char done;  /* 0x14 set after a rebind pass */
    char pad3[3];
    IntVec handles;      /* 0x18 new handles, in rebind order */
    PtrVec names;        /* 0x24 names of the rebound entries */
};
#define NAME_BUF_SIZE 128
struct Str { char buf[NAME_BUF_SIZE]; };
/* A name fragment to look for and the text that replaces it. */
struct Pair { int *find; int *replace; };
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

/* Walks every entry of the nested list; each entry whose name contains rule->find gets that fragment replaced by
   rule->replace, is loaded again under the new name and rebound to the new handle. Old handles are released once at the end. */
extern "C" void FUN_00053b04(Owner *self, int arg, Pair *rule, int extra)
{
    if (self->list) {
        LocalVec old; /* distinct handles that were replaced */
        FUN_00049194();
        int g;
        char *list = self->list + LIST_HEAD_OFFSET;
        int ng = FUN_0002e840(list);
        for (g = 0; g < ng; g++) {

            Group *grp = FUN_0002e650(list, g);
            int nn = FUN_0002e40c(grp);
            for (int i = 0; i < nn; i++) {
                Node *node = *FUN_0002e3d0(grp, i);
                Str s;
                FUN_000149a8(&s, node->name);
                char *hit = FUN_00014d64(&s, rule->find);
                if (hit && !FUN_00014934(hit, rule->find)) {
                    FUN_000149a8(hit, rule->replace);
                    FUN_000491cc();
                    int h = FUN_0004f6b4(DAT_00311170, &s, arg, 0, 0, extra, REBIND_LOAD_ARG, 0);
                    self->handles.push_back(h);
                    self->names.push_back(node->name);
                    int prev = node->handle;
                    for (int j = 0; j < old.size; j++) {
                        if (prev == old[j]) {
                            prev = BAD_HANDLE;
                            break;
                        }
                    }
                    if (prev >= 0) /* remember each old handle once */
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
