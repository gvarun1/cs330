/* This test case is to check lseek implementation for SEEK_CUR whence*/

#include<ulib.h>
int main(u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5)
{
    int pid;
    char buf1[30];
    char *filename="alan.txt";
    int create_fd = open(filename, O_CREAT|O_RDWR, O_READ|O_WRITE);
    char *buf = "Turing was born in Maida Vale, London,[7] while his father, Julius Mathison Turing (1873–1947), was on leave from his position with the Indian Civil Service (ICS) at Chatrapur, then in the Madras Presidency and presently in Odisha state, in India.[17][18] Turing's father was the son of a clergyman, the Rev. John Robert Turing, from a Scottish family of merchants that had been based in the Netherlands and included a baronet. Turing's mother, Julius' wife, was Ethel Sara Turing (née Stoney 1881–1976),[7] daughter of Edward Waller Stoney, chief engineer of the Madras Railways. The Stoneys were a Protestant Anglo-Irish gentry family from both County Tipperary and County Longford, while Ethel herself had spent much of her childhood in County Clare";
    
    int written = write(create_fd, buf, 750);
    if(written < 0){
        printf("Write failed, You can evaluate this student later\n");
        exit(0);
    }
    
    int tot_bytes = written;
    
    int val = lseek(create_fd,-tot_bytes,SEEK_CUR);

    int readr = read(create_fd,buf1,29);
    
    if(readr < 0){
        printf("Read failed, You can evaluate this student later\n");
        exit(0);
    }

    if(!ustrcmp(buf1,"Turing was born in Maida Vale"))
        printf("Testcase Passed\n");
    else
        printf("Testcase failed\n");
	
    close(create_fd);
    return 0;
  }
