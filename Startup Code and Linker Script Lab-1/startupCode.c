extern uint32_t _stack;
extern uint32_t __data_load__;
extern uint32_t __data_start__ ;
extern uint32_t __data_end__ ;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;




void Reset_Handler(void)
{
 
  uint32_t *src, *dest;
 
  src = &__data_load__;
  
  /*Init .DATA */
  for(dest = &__data_start__; dest < &__data_end__;)
  {
    *(dest++) = *(src++);
  }
 
  /* Init .BSS */
  for(dest = &__bss_start__ ; dest < &_bss_end__;) 
  {
    *(dest++) = 0;
  }
 
  main();
  
  while (1);
}


