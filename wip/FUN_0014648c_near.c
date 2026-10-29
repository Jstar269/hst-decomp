/* HSTMATCH module=EBOOT.BIN start=0x0014648c end=0x001464ac symbol=FUN_0014648c lang=c99 */
extern char DAT_002dbb3c;
extern void FUN_000143b0(int,void *,void *,void *,int);
void FUN_0014648c(int self,int a1)
{
  int s = self;
  FUN_000143b0(a1,&DAT_002dbb3c,(void *)(s + 0xd68),(void *)(s + 0xd28),*(int *)(s + 0xd24));
}
// near miss from lane dsn3 (unreviewed)
