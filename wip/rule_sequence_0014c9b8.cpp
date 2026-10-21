/* HSTMATCH module=EBOOT.BIN start=0x0014c9b8 end=0x0014cce0 symbol=FUN_0014c9b8 lang=c++ */
struct Seq;

struct Child {
    virtual ~Child();
    virtual int Update(Seq *);
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
extern char DAT_002dc208[];
extern char DAT_002dc224[];
}

inline int Mode12(Info *i) { int t = i->mode == 1; if (t == 0) t = i->mode == 2; return t; }
extern "C" unsigned char FUN_0014c9b8(Seq *self, Node **stop, float dt)
{
    if (self->list == 0) return 1;
    bool b;
    if (self->child != 0) {
        b = true;
        unsigned char done = self->child->Update(self);
        if (done || (DAT_003403f4 != 0 && self->child->Q3() == 0)) {
            if (self->child != 0) {
                delete self->child;
                self->child = 0;
            }
            self->cur = self->cur->next;
            if (self->cur == &self->list->head) {
                if (DAT_003402f0 != 0) FUN_0014c610(DAT_002dc208, self->list->head.rule);
                return 1;
            }
            b = false;
        }
        if (b) return 0;
    }
    if (DAT_003402f0 != 0) {
        List *l = self->list;
        if (self->cur == l->head.next && self->cur != &l->head)
            FUN_0014c610(DAT_002dc224, l->head.rule);
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
            FUN_0014c610(DAT_002dc208, self->list->head.rule);
    }
    return r;
}

// NEAR MISS (agent snS5-00): 2 words differ, both in the prologue. Retail: `move s4,a1; move s5,a0; bnez v0,..; mov.s $f20,$f12`
// (the float copy sits in the branch delay slot); ours: `move s4,a1; mov.s $f20,$f12; bnez v0,..; move s5,a0`.
// Everything else (3-way virtual dispatch, delete/zero double check, rotated while loop, both debug prints,
// recursion with (self, 0, dt)) matches. Key findings that got here from 182 differing words:
//   - the Update() virtual must return a non-bool integer assigned to an `unsigned char` (andi after the call);
//   - `b = stop != 0 && *stop != &list->head;` as ONE expression (bool b shared with the first `b = true`);
//   - `r = 1;` at the top of the while body (a second `li s3,1` in the delay slot of `beqz s0`);
//   - the `mode == 1 || mode == 2` test is NOT folded to a range test only through the inline Mode12() helper
//     `int t = m == 1; if (t == 0) t = m == 2; return t;` (xori/sltiu twice, f18 tested first).
// Ruled out for the prologue order: all six parameter orders, a local copy of dt or self, reordering the first
// return, `!self->list`.
// (lane sn2) EBOOT twin of Sharing 0x001584a0 (copied from wip/rule_sequence_run_001584a0.cpp, symbols re-addressed). Same 2 words:
// ours `move s4,a1; mov.s $f20,$f12; bnez; move s5,a0`, retail `move s4,a1; move s5,a0; bnez; mov.s $f20,$f12`.
// Tried here as well: declared param order (dt,self,stop)=5 off and (self,dt,stop)=3 off (both change the pair order, not fixed),
// `int` return = 3 off, local copy of list for the first test, `float d=dt` local, locals hoisted to the top (17-193 off).
// A reduced probe (list test + while loop) reproduces retail's `move s0,a1; move s1,a0; bnez; mov.s` order, so the order depends on
// something later in the body (unidentified). Cutting the recursion (`r = 1`) does not change it.
// near miss from lane sn2 (unreviewed)
