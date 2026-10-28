/* HSTMATCH module=hstp_trans_main.prx start=0x0026c924 end=0x0026d050 symbol=FUN_0026c924 lang=c++ data=0x003a64b8 */
/* Hand-written reconstruction (port of src/eboot/init_adhoc_menu_02_0025c474.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (37 strings, 0x003a64b8-0x003a665d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/adhoc_menu.h"

extern "C" {
extern u8 DAT_003a64b4;
extern u8 DAT_003b264c;
extern u8 DAT_003b2c84;
extern u8 * DAT_003e1a08;
extern u32 DAT_003ea8e8;
extern char DAT_003a6444[];
extern char DAT_003a6464[];
extern char DAT_003a646c[];
extern char DAT_003a6474[];
extern char DAT_003a647c[];
extern char DAT_003a6484[];
extern char DAT_003a6490[];
extern char DAT_003a649c[];
extern char DAT_003a64a8[];
extern void FUN_000143b0(...);
extern Item * FUN_00108124(Group *, const char *);
extern u32 * FUN_0010873c(...);
extern Group * FUN_00109304(...);
extern void FUN_00109a44(...);
extern void FUN_00113a50(...);
extern int FUN_00263794(...);
extern u32 * FUN_00263a68(...);
extern void FUN_0029134c(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_3 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_4 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_5 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_6 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_7 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_8 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_9 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

/* Constructor of the ad-hoc menu: loads the screen groups, looks up every named item and widget,
   and primes the parameter, arrow and member-list items. */
extern "C" AdhocMenu * FUN_0026c924(AdhocMenu *self)
{
  Item *item;
  Group *grp;
  UiWidget *widget;
  u32 i;
  int offset; /* byte offset of the slot being filled */
  char name[64];

  FUN_0010873c();
  self->vtbl = &DAT_003b264c;
  self->unk54 = 0;
  self->unk55 = 0;
  self->unk58 = 0;
  self->vtbl = &DAT_003b2c84;
  self->unk5c = *(void **)(DAT_003e1a08 + 0x40);
  self->unk64 = 0;
  FUN_00263794(&self->crbg,0);
  self->arrowL.unk0 = 0;
  self->arrowL.unk4 = 0;
  self->arrowL.unk8 = 0;
  self->arrowL.unkc = 0;
  self->arrowR.unk0 = 0;
  self->arrowR.unk4 = 0;
  self->arrowR.unk8 = 0;
  self->arrowR.unkc = 0;
  FUN_00263a68(&self->unk18c);
  self->unk3c8 = 0;
  FUN_00109a44(self,DAT_003a6444,0);
  grp = FUN_00109304(self,DAT_003a6464,0);
  self->grpRoom = grp;
  grp = FUN_00109304(self,DAT_003a646c,0);
  self->grpCourt = grp;
  grp = FUN_00109304(self,DAT_003a6474,0);
  self->grpItems = grp;
  grp = FUN_00109304(self,DAT_003a647c,0);
  self->grpMembers = grp;
  grp = FUN_00109304(self,DAT_003a6484,0);
  self->grpArrows = grp;
  item = FUN_00108124(self->grpCourt,DAT_003a6490);
  widget = item->widget;
  self->unk58 = widget;
  widget->unkd8 = 2;
  widget->unk114 = 1;
  item = FUN_00108124(self->grpCourt,DAT_003a649c);
  widget = item->widget;
  self->unk7c = widget;
  widget->unkf8 = (void *)(DAT_003ea8e8 + 0x20);
  widget->unk138 = 1;
  FUN_00113a50();
  ((VC_0 *)(self->unk7c))->m((int)(0x80000000));
  item = FUN_00108124(self->grpCourt,DAT_003a64a8);
  widget = item->widget;
  self->unk80 = widget;
  widget->unkf8 = &DAT_003a64b4;
  widget->unk138 = 1;
  FUN_00113a50();
  item = FUN_00108124(self->grpCourt,"crbg0");
  self->crbg = item->widget;
  item = FUN_00108124(self->grpCourt,"crtype0");
  self->crtype = item;
  i = 0;
  offset = 0;
  self->crtypeValue = item->unk24;
  {
    int base = (int)self; /* crparaball0..9 live in two runs of five slots */
    do {
      FUN_000143b0(name,"crparaball%d",i);
      *(Item **)(base + offset + 0x94) = FUN_00108124(self->grpCourt,name);
      i = i + 1;
      offset = offset + 4;
    } while (i < 5);
    i = 0;
    offset = 0;
    do {
      FUN_000143b0(name,"crparaball%d",i + 5);
      *(Item **)(base + offset + 0xa8) = FUN_00108124(self->grpCourt,name);
      i = i + 1;
      offset = offset + 4;
    } while (i < 5);
  }
  self->unk84 = 0;
  item = FUN_00108124(self->grpCourt,"sanka_num0");
  self->sankaNum = item;
  self->sankaNumValue = item->unk24;
  item = FUN_00108124(self->grpCourt,"shiaitype0");
  self->shiaiType = item;
  self->shiaiTypeValue = item->unk24;
  item = FUN_00108124(self->grpCourt,"sdtype0");
  self->sdType = item;
  self->sdTypeValue = item->unk24;
  item = FUN_00108124(self->grpCourt,"shiaibg0");
  self->shiaiBg = item;
  self->shiaiBgValue = item->unk24;
  item = FUN_00108124(self->grpCourt,"ranger_l0");
  self->rangerL0 = item;
  item = FUN_00108124(self->grpCourt,"ranger_l1");
  self->rangerL1 = item;
  item = FUN_00108124(self->grpCourt,"ranger_r0");
  self->rangerR0 = item;
  item = FUN_00108124(self->grpCourt,"ranger_r1");
  self->rangerR1 = item;
  self->rangerL0Value = self->rangerL0->value;
  self->rangerL1Value = self->rangerL1->value;
  self->rangerR0Value = self->rangerR0->value;
  self->rangerR1Value = self->rangerR1->value;
  self->rangerBase = self->rangerL0->unk24;
  {
    int v = self->rangerBase + 1;
    Item *r0 = self->rangerR0;
    r0->unk24 = v;
    r0->unk28 = v;
  }
  {
    int v = self->rangerBase + 1;
    Item *r1 = self->rangerR1;
    r1->unk24 = v;
    r1->unk28 = v;
  }
  item = FUN_00108124(self->grpCourt,"courtname0");
  widget = item->widget;
  self->courtName = widget;
  ((VC_1 *)(widget))->m((int)(0x80000000));
  item = FUN_00108124(self->grpArrows,"yajirushi_l0");
  self->yajirushiL = item;
  item = FUN_00108124(self->grpArrows,"yajirushi_r0");
  self->yajirushiR = item;
  FUN_0029134c(&self->arrowL,self->yajirushiL,1);
  FUN_0029134c(&self->arrowR,self->yajirushiR,0);
  item = FUN_00108124(self->grpItems,"koumoku0");
  widget = item->widget;
  self->koumoku[0] = widget;
  ((VC_2 *)(widget))->m((int)(0x80000000));
  item = FUN_00108124(self->grpItems,"koumoku1");
  widget = item->widget;
  self->koumoku[1] = widget;
  ((VC_3 *)(widget))->m((int)(0x80000000));
  item = FUN_00108124(self->grpItems,"koumoku2");
  widget = item->widget;
  self->koumoku[2] = widget;
  ((VC_4 *)(widget))->m((int)(0x80000000));
  self->unk18c = 0;
  item = FUN_00108124(self->grpItems,"iromonoinfo0");
  self->iromonoInfo0 = item->widget;
  item = FUN_00108124(self->grpItems,"iromonoinfo1");
  self->iromonoInfo1 = item->widget;
  ((VC_5 *)(self->iromonoInfo0))->m((int)(0x80000000));
  ((VC_6 *)(self->iromonoInfo1))->m((int)(0x80000000));
  item = FUN_00108124(self->grpItems,"iromonobg0");
  self->iromonoBg0 = item;
  item = FUN_00108124(self->grpItems,"iromonobg1");
  self->iromonoBg1 = item;
  self->iromonoBgValue = self->iromonoBg0->unk24;
  {
    int idx = 0;
    int off = 0;
    int b0 = (int)self;
    do {
      FUN_000143b0(name,"sankasyaname%d",idx);
      item = FUN_00108124(self->grpMembers,name);
      widget = item->widget;
      *(UiWidget **)(b0 + off + 0x1f8) = widget;
      ((VC_7 *)(widget))->m((int)(0x80000000));
      FUN_000143b0(name,"rank%d",idx);
      item = FUN_00108124(self->grpMembers,name);
      *(Item **)((u32)b0 + off + 0x208) = item;
      self->rankValue = item->unk24 + -1;
      FUN_000143b0(name,"regulation%d",idx);
      item = FUN_00108124(self->grpMembers,name);
      widget = item->widget;
      *(UiWidget **)((unsigned long)b0 + (unsigned long)off + 0x21c) = widget;
      ((VC_8 *)(widget))->m((int)(0x80000000));
      idx = idx + 1;
      off = off + 4;
    } while (idx < 4);
  }
  item = FUN_00108124(self->grpRoom,"roomnum10");
  self->roomnum[0] = item;
  item = FUN_00108124(self->grpRoom,"roomnum11");
  self->roomnum[1] = item;
  item = FUN_00108124(self->grpRoom,"roomnum30");
  self->roomnum[2] = item;
  item = FUN_00108124(self->grpRoom,"roomnum31");
  self->roomnum[3] = item;
  self->roomnumValue[0] = self->roomnum[0]->value;
  self->roomnumValue[1] = self->roomnum[1]->value;
  self->roomnumValue[2] = self->roomnum[2]->value;
  self->roomnumValue[3] = self->roomnum[3]->value;
  item = FUN_00108124(self->grpMembers,"nodate0");
  self->nodate[0] = item;
  item = FUN_00108124(self->grpMembers,"nodate1");
  self->nodate[1] = item;
  item = FUN_00108124(self->grpMembers,"nodate2");
  self->nodate[2] = item;
  item = FUN_00108124(self->grpMembers,"nodate3");
  self->nodate[3] = item;
  item = FUN_00108124(self->grpMembers,"nodate4");
  self->nodate[4] = item;
  item = FUN_00108124(self->grpMembers,"nodate5");
  self->nodate[5] = item;
  item = FUN_00108124(self->grpMembers,"nodate6");
  self->nodate[6] = item;
  item = FUN_00108124(self->grpMembers,"nodate7");
  self->nodate[7] = item;
  item = FUN_00108124(self->grpRoom,"titlebg0");
  self->titleBg = item;
  ((VC_9 *)(self))->m();
  return self;
}
