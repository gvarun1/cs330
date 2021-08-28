#include<ulib.h>

int fn_1()
{
	int a = 10, b = 20, c;
	c = a + b;
	return c;
}

int fn_2()
{
	int a = 1, b = 2, c;
	c = a + b;
	return c;
}

int main(u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5)
{
	// checks if error is returned 
	// on remove_breakpoint	on non existing breakpoint
	long ret = 0;
	ret = become_debugger();
	
	ret = set_breakpoint(fn_1);
	
	ret = remove_breakpoint(fn_2);
	// check if the list is modified on remove
	
	if(ret == -1)
		printf("Test passed\n");
	else 
		printf("Test failed\n");
	return 0;
}
