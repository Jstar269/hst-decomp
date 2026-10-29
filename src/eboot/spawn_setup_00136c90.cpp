/* HSTMATCH module=EBOOT.BIN start=0x00136c90 end=0x00136e94 symbol=FUN_00136c90 lang=c++ */
/* Hand-written reconstruction from the disassembly; readability pass; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

#include "hst/court_spawn.h"

extern "C" {
void *operator new(unsigned int size);
AreaObj *FUN_0024b5a0(void *mem, int arg);
void FUN_0024ba68(AreaObj *obj, AlignedVec4 *v1, AlignedVec4 *v2);
void FUN_0001f21c(void *owner, void *obj);
PropObj *FUN_0023ed34(void *mem, int id);
void FUN_0023fe08(PropObj *obj, int a1, int a2, int a3, float f1, float f2, int a6, int a7);
}

extern "C" void FUN_0013cb30(AreaObjVec *v, AreaObj *const *x, EmptyTag a);
extern "C" void FUN_0013ca84(PropObjVec *v, PropObj *const *x, EmptyTag a);

inline void AreaObjVec::push_back(AreaObj *const &x)
{
    if (size < capacity) {
        unsigned idx = ++size - 1;
        data[idx] = x;
    } else {
        FUN_0013cb30(this, &x, EmptyTag());
    }
}

inline void PropObjVec::push_back(PropObj *const &x)
{
    if (size < capacity) {
        ++size;
        data[size - 1] = x;
    } else {
        FUN_0013ca84(this, &x, EmptyTag());
    }
}

/* Creates the area object and one prop object per record, registering each with the owner. */
extern "C" void FUN_00136c90(SpawnCourt *self) {
    PropObj *prop;
    AreaObj *area;
    AlignedVec4 v[3];   /* v[0], v[1]: opposite corners handed to the area object */

    for (unsigned i = 0; i < self->count; i++) {
        PropObj *prop_mem = (PropObj *)operator new(0x330);
        if (prop_mem)
            prop_mem = FUN_0023ed34(prop_mem, self->records[i].id);
        prop = prop_mem;
        PropRecord *r = &self->records[i];
        FUN_0023fe08(prop, r->unk4, r->unk8, r->unkc, r->unk10, r->unk14, r->unk18, r->unk1c);
        if (self->records[i].flagged)
            prop->SetFlags();
        self->props.push_back(prop);
        FUN_0001f21c(self, prop);
    }

    AreaObj *area_mem = (AreaObj *)operator new(0x280);
    if (area_mem)
        area_mem = FUN_0024b5a0(area_mem, 10);
    area = area_mem;

    v[1].x = 12.0f;
    v[1].y = -7.0f;
    v[0].y = -7.0f;
    v[1].z = -9.12f;
    v[0].z = -9.12f;
    v[1].w = 1.0f;
    v[0].w = 1.0f;
    v[0].x = -12.0f;

    FUN_0024ba68(area, &v[1], &v[0]);

    float f1 = self->unk1354;
    AreaObj *o = area;
    o->unk24c = self->unk1350;
    o->unk250 = f1;

    self->areas.push_back(area);

    FUN_0001f21c(self, area);
}
