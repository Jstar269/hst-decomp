/* HSTMATCH module=hstp_trans_main.prx start=0x0004f1b0 end=0x0004f3f8 symbol=FUN_0004f1b0 lang=c++ */
/* Hand-written reconstruction from the disassembly: VRAM first-fit allocator of i3d.cpp (log strings "Vram: total/max", "Vram::Alloc: Vram overflow. Use heap", asserts "First" line 810 and "First->m_Prev == 0" line 811); the block split is an inline Block ctor; on overflow the address comes from FUN_00010184(0x40, size); exact match verified; names and types await human review. */
extern "C" void FUN_0004efe0(...);
extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_0004f5f0(unsigned *, unsigned *);
extern "C" unsigned FUN_00010184(int, unsigned); /* aligned heap allocation (alignment, size) */
extern char DAT_0037638c[];
extern char DAT_00376470[];
extern char DAT_00376478[];
extern char DAT_003763c8[];
extern char DAT_00376490[];
extern char DAT_003764b0[];

#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_0004efe0(DAT_0037638c, text, DAT_003763c8, line); for (;;) {} } } while (0)

struct Block;
extern "C" Block *DAT_003d4574;

struct Block {
  Block *m_Prev;
  Block *m_Next;
  unsigned char m_Free;
  unsigned m_Start;
  unsigned m_End;
  Block(Block *prev, unsigned start, unsigned end, unsigned char free)
  {
    Block *next = prev->m_Next;
    m_Prev = prev;
    m_Next = next;
    if (m_Prev) {
      m_Prev->m_Next = this;
      m_Prev->m_End = start;
    } else {
      DAT_003d4574 = this;
    }
    if (m_Next) {
      m_Next->m_Prev = this;
      m_Next->m_Start = end;
    }
    m_Free = free;
    m_Start = start;
    m_End = end;
  }
  void *operator new(unsigned n) { return FUN_00000bcc(n); }
};

extern "C" unsigned FUN_0004f1b0(unsigned size, unsigned align)
{
  unsigned addr = 0;
  if (size != 0) {
    size = (size + 15) & ~15;
    for (Block *b = DAT_003d4574; b != 0; b = b->m_Next) {
      if (b->m_Free) {
        unsigned off = size & (align - 1);
        unsigned start = (~(align - 1) & (align + (b->m_Start + off) - 1)) - off;
        unsigned end = start + size;
        if (end <= b->m_End) {
          if (start > b->m_Start) {
            b = new Block(b, start, b->m_End, 0);
          } else {
            b->m_Free = 0;
          }
          if (end < b->m_End) {
            new Block(b, end, b->m_End, 1);
          }
          unsigned max = 0;
          unsigned total = 0;
          FUN_0004f5f0(&max, &total);
          FUN_0004efe0(DAT_00376490, total, max);
          HST_ASSERT(DAT_003d4574, DAT_00376470, 810);
          HST_ASSERT(DAT_003d4574->m_Prev == 0, DAT_00376478, 811);
          addr = b->m_Start;
          break;
        }
      }
    }
    if (addr == 0) {
      FUN_0004efe0(DAT_003764b0);
      addr = FUN_00010184(0x40, size);
    }
  }
  return addr;
}
