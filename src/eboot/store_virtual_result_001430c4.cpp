/* HSTMATCH module=EBOOT.BIN start=0x001430c4 end=0x00143104 symbol=FUN_001430c4 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: virtual slot 2 with the forwarded argument registers and the repeated value in the fifth argument; exact match verified; names and types await human review. */
struct Receiver_1430c4 {
  virtual int f0();
  virtual int f1();
  virtual unsigned char Read(int,int,int,int,int,int);
};
struct Owner_1430c4 { char pad[12]; Receiver_1430c4 *receiver; };
extern "C" void FUN_001430c4(Owner_1430c4 *self,int a,int b,int c) {
  unsigned char r = self->receiver->Read(a,b,c,b,0,0);
  *((unsigned char *)self + 0xd1d) = r;
}
