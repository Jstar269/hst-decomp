/* HSTMATCH module=hstp_trans_main.prx start=0x0028bd30 end=0x0028bdc0 symbol=FUN_0028bd30 lang=c++ */
/* Clone of src/eboot/swap_records_0027aa4c.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Record {
  unsigned char bytes[5];
  unsigned char padding[3];
  unsigned int words[5];
  float values[5];
};
extern "C" Record *FUN_0028bdc0(Record *dst, Record *src);

/* Swap of two 48-byte records through a temporary: copy-construct (inline), then the out-of-line assignment
   operator 0x27aadc twice. Matching idiom: an unused empty Tag by-value parameter (never-written 4-byte slot) gives
   retail's 80-byte frame with the temporary at sp+32; without it the frame is 64. */
struct Tag {};
extern "C" void FUN_0028bd30(Record *param_1, Record *param_2, Tag)
{
  Record t = *param_1;
  FUN_0028bdc0(param_1, param_2);
  FUN_0028bdc0(param_2, &t);
}
