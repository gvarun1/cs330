 #include<ulib.h>



int fn_2()
{
	printf("In fn2\n");	
	return 0;
}

int fn_1()
{
	printf("In fn1\n");	
	return 0;
}


int main(u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5)
{
	int cpid;
	long ret = 0;
	int i, bt_count;
	
	ret = become_debugger();
	
	cpid = fork();
	
	if(cpid < 0){
		printf("Error in fork\n");
	}
	else if(cpid == 0){
		printf("fn_1 : %x\n", fn_1);
		printf("fn_2 : %x\n", fn_2);
		fn_1();
		fn_2();
	}
	else{
		ret = set_breakpoint(fn_1);
		ret = set_breakpoint(fn_2);
		// fn_1 
		ret = wait_and_continue();
		printf("Breakpoint hit at : %x\n", ret);
		remove_breakpoint(fn_1);
		ret = set_breakpoint(fn_1);

		// fn_2
		ret = wait_and_continue();
		printf("Breakpoint hit at : %x\n", ret);
		
		// for exit
		ret = wait_and_continue();	
	}
	
	return 0;
}
