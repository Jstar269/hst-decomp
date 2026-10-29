/* HSTMATCH module=hstp_trans_main.prx start=0x001584a0 end=0x001587c8 symbol=FUN_001584a0 lang=c++ data=0x00383680 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the child Update takes (ModuleCtx *, float) — the delta time the earlier wip had dropped. Data: its string literals (2 strings, 0x002dc208-0x002dc23f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/module_ctx.h"

struct ModuleChild {
    virtual ~ModuleChild();
    virtual int Update(ModuleCtx *, float);
    virtual int Q2();
    virtual int Q3();
};

struct ModuleRule {
    virtual ~ModuleRule();
    virtual ModuleChild *Start(float, ModuleCtx *);
    virtual int C2();
    virtual int C3();
    virtual int C4();
};

/* View of a queued node: its links, then the mode word of the queued record. */
struct NodeInfo {
    int prev, next;
    int mode;
};

/* Modes of the last queued node that make the walk consult rule->C3() before starting a rule. */
enum { NODE_MODE_A = 1, NODE_MODE_B = 2 };

extern "C" {
void FUN_00157280(const char *, ModuleRule *);
extern unsigned char DAT_003e9630; /* script trace flag */
extern unsigned char DAT_003e9734;
extern unsigned char DAT_003e9735;
}

inline int Mode12(NodeInfo *i) { int t = i->mode == NODE_MODE_A; if (t == 0) t = i->mode == NODE_MODE_B; return t; }

/* Run the rules of a module: update the running child, then start rules until one yields a child or the module ends.
   Returns 1 when the module is finished. */
extern "C" unsigned char FUN_001584a0(ModuleCtx *self, ModuleNode **stopAt, float dt)
{
    if (self->module == 0) return 1;
    bool flag;
    if (self->owned != 0) {
        flag = true;
        unsigned char done = self->owned->Update(self, dt);
        if (done || (DAT_003e9734 != 0 && self->owned->Q3() == 0)) {
            if (self->owned != 0) {
                delete self->owned;
                self->owned = 0;
            }
            self->cur = self->cur->next;
            if (self->cur == &self->module->head) {
                if (DAT_003e9630 != 0) FUN_00157280("SCRIPT: End Module [%s]\n", self->module->head.rule);
                return 1;
            }
            flag = false;
        }
        if (flag) return 0;
    }
    if (DAT_003e9630 != 0) {
        ModuleRules *module = self->module;
        if (self->cur == module->head.next && self->cur != &module->head)
            FUN_00157280("SCRIPT: Start Module [%s]\n", module->head.rule);
    }
    flag = stopAt != 0 && *stopAt != &self->module->head;
    unsigned char result = 1;
    while (self->cur != &self->module->head) {
        ModuleRule *rule = self->cur->rule;
        result = 1;
        if (flag) {
            if (rule->C2() == 0) {
                self->cur = self->cur->next;
                if (self->cur == *stopAt) {
                    result = 0;
                    break;
                }
                continue;
            }
        }
        if (self->nodes.size != 0 && Mode12((NodeInfo *)self->nodes.sentinel.prev) && rule->C3() == 0) {
            self->cur = self->cur->next;
            continue;
        }
        ModuleChild *newChild = 0;
        if (DAT_003e9735 == 0 || rule->C4() != 0) {
            newChild = rule->Start(dt, self);
            if (self->flag != 0) return 0;
        }
        if (newChild != 0) {
            self->owned = newChild;
            result = FUN_001584a0(self, 0, dt);
            break;
        }
        self->cur = self->cur->next;
        if (DAT_003e9630 != 0 && self->cur == &self->module->head)
            FUN_00157280("SCRIPT: End Module [%s]\n", self->module->head.rule);
    }
    return result;
}
