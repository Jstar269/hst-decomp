/* HSTMATCH module=hstp_trans_main.prx start=0x00159158 end=0x001592a4 symbol=__ct__10C_00159158FP11ModuleTableUii lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of the 40-byte script "Call" command that the factory 0x159024 (script_command.cpp, "SCRIPT: Call %d")
   creates: base vtable 0x3b1698 (C_001583b4), own vtable 0x3b1614, then the module context member at +4, built
   empty by its out-of-line ctor 0x15827c and assigned the context returned by value from 0x157be4 (which asserts
   "moduleNo < size()"). The context's copy assignment (out of line at 0x1583fc) and destructor (0x158308) are
   inlined here: drop the owned object through its virtual deleting destructor, copy the scalar fields, clear the
   node list through the out-of-line erase 0x15b32c (iterators with a user copy ctor are passed by reference).
   Matching idiom: #pragma exceptions off - retail keeps no exception-cleanup register for the member (with exceptions on MWCC holds
   &ctx in s4 and shifts every saved register), and the factory 0x159024 has no cleanup store around its new either. */
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
extern "C" LIter FUN_0015b32c(NodeList *self, LIter first, LIter last);

struct NodeList {
    int size;
    LNode head;
    LIter begin() { return LIter(head.next); }
    LIter end() { return LIter(&head); }
    void clear() { FUN_0015b32c(this, begin(), end()); }
    ~NodeList() { FUN_0015b32c(this, begin(), end()); }
};

struct Module;
struct ModuleTable;
struct ModuleCtx;
extern "C" ModuleCtx *FUN_0015827c(ModuleCtx *self, ModuleTable *table, Module *module, int arg);

struct ModuleCtx {
    ModuleTable *table;
    Module *module;
    Owned *owned;
    int arg;
    unsigned char flag;
    void *code;
    NodeList nodes;

    ModuleCtx(ModuleTable *t, Module *m, int a) { FUN_0015827c(this, t, m, a); }
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

extern "C" ModuleCtx FUN_00157be4(ModuleTable *table, unsigned moduleNo, int arg);

struct Seq;
class C_001583b4 {
public:
    virtual ~C_001583b4();
    virtual int Init(float dt, Seq *seq) = 0;
};

class C_00159158 : public C_001583b4 {
public:
    C_00159158(ModuleTable *table, unsigned moduleNo, int arg);
    virtual ~C_00159158();
    virtual int Init(float dt, Seq *seq);
    ModuleCtx ctx;
};

C_00159158::C_00159158(ModuleTable *table, unsigned moduleNo, int arg) : ctx(0, 0, 0)
{
    ctx = FUN_00157be4(table, moduleNo, arg);
}
