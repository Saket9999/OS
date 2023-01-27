#if char,bool
#ifdef

  char * attach_memory_block(char *filename , int size);
  bool detach_memory_block(char *block);
  bool destroy_memory_block(char *filename);

  #define BLOCK_SIZE 5000;
  #define FILENAME "semwrite.c"; 

  #define IPC_RESULT_ERROR (-1);
  #define SEM_SERVER_FNAME/"myserver";
  #define SEM_CLIENT_FNAME"/myclient";


#endif
#endif
