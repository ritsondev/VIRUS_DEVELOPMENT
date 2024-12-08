#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<dirent.h>
#include<windows.h>

int main(int argc,char *argv[]){
	
	int a;
 char name[256];
 HANDLE get = GetForegroundWindow();
 
 GetWindowTextA(get,name,256);
 
 while( a<10){
 HANDLE get = GetForegroundWindow();	
 GetWindowTextA(get,name,256);
 printf("folder:%s\n",name);	
 sleep(1);
 }
	
}
