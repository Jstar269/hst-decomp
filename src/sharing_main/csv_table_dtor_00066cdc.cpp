/* HSTMATCH module=hstp_trans_main.prx start=0x00066cdc end=0x00066dc0 symbol=__dt__17CsvTable_00066cdcFv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Destructor of the CSV table reader that npc_voice_load_000b6f54.cpp and load_ai_param_table_00246158.cpp
   build on the stack (vtable DAT_003b0388, base vtable DAT_003b0398): MWCC deleting-destructor form (this +
   short flag, delete when flag > 0). Two tree-backed members (+0x10, +0x20, out-of-line tree dtor 0x6778c) are
   destroyed in reverse order, then the base destructor (0x658cc out of line) is inlined: it calls virtual slot 1
   and destroys the vector at +4 (0x673f4). Every inlined destructor layer keeps its own `if (this)`, which is
   where retail's four (map) and two (vector) repeated null tests come from; `#pragma inline_depth(8)` lets the
   innermost layer inline as in retail. The vptr stores are written out like the sibling sources do. */
#pragma inline_depth(8)

extern unsigned char DAT_003b0388;
extern unsigned char DAT_003b0398;
extern "C" void FUN_0006778c(void *, int);
extern "C" void FUN_000673f4(void *, int);

struct VBase
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
};

struct TreeRep { int w[4]; ~TreeRep() { FUN_0006778c(this, 0); } };
struct TreeBase { TreeRep rep; };
struct TreeHolder { TreeBase tree; };
struct Map { TreeHolder impl; };

struct VecRep { int w[3]; ~VecRep() { FUN_000673f4(this, 0); } };
struct Vec { VecRep rep; };

struct CsvBase {
  void *vptr;
  Vec rows;
  ~CsvBase()
  {
    vptr = &DAT_003b0398;
    ((VBase *)this)->Slot1();
  }
};

struct CsvTable_00066cdc : CsvBase {
  Map m10;
  Map m20;
  ~CsvTable_00066cdc();
};

CsvTable_00066cdc::~CsvTable_00066cdc()
{
  vptr = &DAT_003b0388;
}
