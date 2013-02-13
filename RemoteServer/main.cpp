#include <stdio.h>
#include <shellexecutor.h>

int main(int argc, char* argv)
{
	ExecCommand command("calc.exe");
	DirCommand	command2("C:\\");

	IResult res;



	ShellExecutor executor;

	executor.ExecComm(&command, &res);
	executor.ExecComm(&command2, &res);

	return 0;
}