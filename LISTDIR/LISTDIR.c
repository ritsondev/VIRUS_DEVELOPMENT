#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<dirent.h>
#include<windows.h>	

int main(int argc,char **argv[]){
	
	DIR *direct;
struct dirent *dirs;

direct=opendir("../");
dirs=readdir(direct);

while(direct){
	
	dirs=readdir(direct);
	printf("%s\n",dirs->d_name);
	
}
	
}
