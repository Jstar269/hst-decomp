/* HSTMATCH module=EBOOT.BIN start=0x00065888 end=0x0006596c symbol=__dt__17CsvTable_00065888Fv lang=c++ */
/* Hand-written reconstruction from the disassembly (written together with the exact Sharing twin src/sharing_main/csv_table_dtor_00066cdc.cpp, EBOOT addresses); exact match verified; names and types await human review. */
/* Destructor of the CSV table reader that npc_voice_load_000b3cf4.cpp and load_ai_param_table_00235ff4.cpp
   build on the stack (vtable DAT_003070bc, base vtable DAT_003070cc): MWCC deleting-destructor form (this +
   short flag, delete when flag > 0). Two tree-backed members (+0x10, +0x20, out-of-line tree dtor 0x66338) are
   destroyed in reverse order, then the base destructor (0x64a08 out of line) is inlined: it calls virtual slot 1
   and destroys the vector at +4 (0x65fa0). Every inlined destructor layer keeps its own `if (this)`, which is
   where retail's four (map) and two (vector) repeated null tests come from; `#pragma inline_depth(8)` lets the
   innermost layer inline as in retail. The vptr stores are written out like the sibling sources do. */
#pragma inline_depth(8)

extern unsigned char DAT_003070bc;
extern unsigned char DAT_003070cc;
extern "C" void FUN_00066338(void *, int);
extern "C" void FUN_00065fa0(void *, int);

struct VBase
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
};

struct TreeRep { int w[4]; ~TreeRep() { FUN_00066338(this, 0); } };
struct TreeBase { TreeRep rep; };
struct TreeHolder { TreeBase tree; };
struct Map { TreeHolder impl; };

struct VecRep { int w[3]; ~VecRep() { FUN_00065fa0(this, 0); } };
struct Vec { VecRep rep; };

struct CsvBase {
  void *vptr;
  Vec rows;
  ~CsvBase()
  {
    vptr = &DAT_003070cc;
    ((VBase *)this)->Slot1();
  }
};

struct CsvTable_00065888 : CsvBase {
  Map m10;
  Map m20;
  ~CsvTable_00065888();
};

CsvTable_00065888::~CsvTable_00065888()
{
  vptr = &DAT_003070bc;
}
