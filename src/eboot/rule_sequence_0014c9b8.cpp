/* HSTMATCH module=EBOOT.BIN start=0x0014c9b8 end=0x0014cce0 symbol=FUN_0014c9b8 lang=c++ data=0x002dc208 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the child Update takes (Seq *, float) — the delta time the earlier wip had dropped. Data: its string literals (2 strings, 0x002dc208-0x002dc23f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Seq;

struct Child {
    virtual ~Child();
    virtual int Update(Seq *, float);
    virtual int Q2();
    virtual int Q3();
};

struct Rule;

struct Node {
    Node *prev;
    Node *next;
    Rule *rule;
};

struct List {
    int f0;
    Node head;
};

struct Info {
    int f0, f4;
    int mode;
};

struct Seq {
    int f0;
    List *list;
    Child *child;
    int fc;
    unsigned char f10;
    char pad11[3];
    Node *cur;
    int f18;
    Info *f1c;
};

struct Rule {
    virtual ~Rule();
    virtual Child *Start(float, Seq *);
    virtual int C2();
    virtual int C3();
    virtual int C4();
};

extern "C" {
void FUN_0014c610(const char *, Rule *);
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003403f4;
extern unsigned char DAT_003403f5;
}

inline int Mode12(Info *i) { int t = i->mode == 1; if (t == 0) t = i->mode == 2; return t; }
extern "C" unsigned char FUN_0014c9b8(Seq *self, Node **stop, float dt)
{
    if (self->list == 0) return 1;
    bool b;
    if (self->child != 0) {
        b = true;
        unsigned char done = self->child->Update(self, dt);
        if (done || (DAT_003403f4 != 0 && self->child->Q3() == 0)) {
            if (self->child != 0) {
                delete self->child;
                self->child = 0;
            }
            self->cur = self->cur->next;
            if (self->cur == &self->list->head) {
                if (DAT_003402f0 != 0) FUN_0014c610("SCRIPT: End Module [%s]\n", self->list->head.rule);
                return 1;
            }
            b = false;
        }
        if (b) return 0;
    }
    if (DAT_003402f0 != 0) {
        List *l = self->list;
        if (self->cur == l->head.next && self->cur != &l->head)
            FUN_0014c610("SCRIPT: Start Module [%s]\n", l->head.rule);
    }
    b = stop != 0 && *stop != &self->list->head;
    unsigned char r = 1;
    while (self->cur != &self->list->head) {
        Rule *item = self->cur->rule;
        r = 1;
        if (b) {
            if (item->C2() == 0) {
                self->cur = self->cur->next;
                if (self->cur == *stop) {
                    r = 0;
                    break;
                }
                continue;
            }
        }
        if (self->f18 != 0 && Mode12(self->f1c) && item->C3() == 0) {
            self->cur = self->cur->next;
            continue;
        }
        Child *c = 0;
        if (DAT_003403f5 == 0 || item->C4() != 0) {
            c = item->Start(dt, self);
            if (self->f10 != 0) return 0;
        }
        if (c != 0) {
            self->child = c;
            r = FUN_0014c9b8(self, 0, dt);
            break;
        }
        self->cur = self->cur->next;
        if (DAT_003402f0 != 0 && self->cur == &self->list->head)
            FUN_0014c610("SCRIPT: End Module [%s]\n", self->list->head.rule);
    }
    return r;
}
