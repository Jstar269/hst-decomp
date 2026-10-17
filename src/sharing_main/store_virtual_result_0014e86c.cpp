/* HSTMATCH module=hstp_trans_main.prx start=0x0014e86c end=0x0014e8ac symbol=FUN_0014e86c lang=c++ */
/* Clone of src/eboot/store_virtual_result_001430c4.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: virtual slot 2 with the forwarded argument registers and the repeated value in the fifth argument; exact match verified; names and types await human review. */
struct Receiver_1430c4 {
  virtual int f0();
  virtual int f1();
  virtual unsigned char Read(int,int,int,int,int,int);
};
struct Owner_1430c4 { char pad[12]; Receiver_1430c4 *receiver; };
extern "C" void FUN_0014e86c(Owner_1430c4 *self,int a,int b,int c) {
  unsigned char r = self->receiver->Read(a,b,c,b,0,0);
  *((unsigned char *)self + 0xd1d) = r;
}
