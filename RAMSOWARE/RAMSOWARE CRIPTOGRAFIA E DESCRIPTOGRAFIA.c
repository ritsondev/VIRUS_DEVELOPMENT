#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<windows.h>
#include<dirent.h>



int main(int argc,char **argv[]){

int i;

FILE *a=fopen("ronaldol.txt","rb");
fseek(a,0,SEEK_END);
long tamanho=ftell(a);
rewind(a);
void *ab=malloc(tamanho);
fread(ab,tamanho,1,a);
fclose(a);



/*criptografia*/

for(i=0;i<tamanho;i++){
	
	* (char*) (ab + i) +=3;
	
}

///*DESCRIPTOGRAFIA*/
//
//for(i=0;i<tamanho;i++){
//	
//	* (char*) (ab + i) -=3;
//	
//}
//

FILE *b=fopen("ronaldoL.txt","wb");
fwrite(ab,tamanho,1,b);
fclose(b);
return 0;

}


