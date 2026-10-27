/* HSTMATCH module=hstp_trans_main.prx start=0x002b70fc end=0x002b718c symbol=FUN_002b70fc lang=c++ */
/* Hand-written reconstruction from the disassembly (port of the matched EBOOT twin src/eboot/setup_obj_mode_002a796c.c, typed as structs, the lower bound as an inline Max(const T &, const T &) returning a reference, which gives retail's select of the stack-temporary address; the address argument is computed before the two zero stores); exact match verified; names and types await human review. */
struct Sub {
  char pad0[0xd8];
  int fd8;
  int fdc;
};

struct Obj {
  char pad0[0x35c];
  Sub *sub;
  char pad1[0x1668 - 0x360];
  int f1668;
  int f166c;
  int f1670;
};

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" {
extern int DAT_003aad2c;
extern char *DAT_003ea8e8;
void FUN_002b6adc(Obj *);
void FUN_002b6dac(Obj *);
int FUN_002beb30(void *);

void FUN_002b70fc(Obj *self)
{
  char *addr = DAT_003ea8e8 + 0x87128;
  self->f1668 = 0;
  self->f166c = 0;
  int val = Max(DAT_003aad2c, FUN_002beb30(addr));
  self->f1670 = val;
  Sub *sub = self->sub;
  sub->fd8 = val;
  sub->fdc = 0xc;
  FUN_002b6adc(self);
  FUN_002b6dac(self);
}
}
