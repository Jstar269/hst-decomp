/* HSTMATCH module=EBOOT.BIN start=0x0014d630 end=0x0014d77c symbol=__ct__10C_0014d630FP11ModuleTableUii lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of the 40-byte script "Call" command that the factory 0x14d53c creates (release twin of the Sharing
   script_command.cpp source, 0x159158 there): base vtable 0x3083cc (C_0014c8cc), own vtable 0x308348, then the module
   context member at +4, built empty by its out-of-line ctor 0x14c794 and assigned the context returned by value from
   0x14c214. The context's copy assignment (out of line at 0x14c914) and destructor (0x14c820) are inlined here: drop the
   owned object through its virtual deleting destructor, copy the scalar fields, clear the node list through the
   out-of-line erase 0x14f32c (iterators with a user copy ctor are passed by reference).
   Matching idiom: #pragma exceptions off - retail keeps no exception-cleanup register for the member (with exceptions on MWCC holds
   &ctx in s4 and shifts every saved register), and the factory 0x14d53c has no cleanup store around its new either. */
#pragma exceptions off

struct Owned {
    virtual ~Owned();
};

struct LNode {
    LNode *prev;
    LNode *next;
};

struct LIter {
    LNode *node;
    LIter(LNode *n) : node(n) {}
    LIter(const LIter &o) : node(o.node) {}
};

struct NodeList;
extern "C" LIter FUN_0014f32c(NodeList *self, LIter first, LIter last);

struct NodeList {
    int size;
    LNode head;
    LIter begin() { return LIter(head.next); }
    LIter end() { return LIter(&head); }
    void clear() { FUN_0014f32c(this, begin(), end()); }
    ~NodeList() { FUN_0014f32c(this, begin(), end()); }
};

struct Module;
struct ModuleTable;
struct ModuleCtx;
extern "C" ModuleCtx *FUN_0014c794(ModuleCtx *self, ModuleTable *table, Module *module, int arg);

struct ModuleCtx {
    ModuleTable *table;
    Module *module;
    Owned *owned;
    int arg;
    unsigned char flag;
    void *code;
    NodeList nodes;

    ModuleCtx(ModuleTable *t, Module *m, int a) { FUN_0014c794(this, t, m, a); }
    ~ModuleCtx()
    {
        if (owned) {
            delete owned;
            owned = 0;
        }
    }
    ModuleCtx &operator=(const ModuleCtx &o)
    {
        if (owned) {
            delete owned;
            owned = 0;
        }
        table = o.table;
        module = o.module;
        arg = o.arg;
        flag = o.flag;
        code = o.code;
        owned = 0;
        nodes.clear();
        return *this;
    }
};

extern "C" ModuleCtx FUN_0014c214(ModuleTable *table, unsigned moduleNo, int arg);

struct Seq;
class C_0014c8cc {
public:
    virtual ~C_0014c8cc();
    virtual int Init(float dt, Seq *seq) = 0;
};

class C_0014d630 : public C_0014c8cc {
public:
    C_0014d630(ModuleTable *table, unsigned moduleNo, int arg);
    virtual ~C_0014d630();
    virtual int Init(float dt, Seq *seq);
    ModuleCtx ctx;
};

C_0014d630::C_0014d630(ModuleTable *table, unsigned moduleNo, int arg) : ctx(0, 0, 0)
{
    ctx = FUN_0014c214(table, moduleNo, arg);
}
