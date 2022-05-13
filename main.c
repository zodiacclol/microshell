#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#define BG_GREEN "\x1b[102m"
#define GREEN "\x1b[92m"
#define BG_BLUE "\x1b[104m"
#define BLUE "\x1b[34m"
#define BG_RED "\x1b[41m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define BG_YELLOW "\x1b[103m"
#define COLOR_RESET "\x1b[0m"
char program[1024];
char path[100];
char pcd[2][255];
char *f,*l;
char c[]=" ",d[]=" ";
int u,x,i;
char p[255];
void help(){
    printf(BLUE);
    printf("Miłosz Chudziński Gr 1 \n");
    printf("Moje funkcje to: \n");
    printf("-cd\n -cd ~ (lub cd)= katalog domowy\n -cd . = bieżąca lokacja\n -cd .. = nadrzędna lokacja\n -cd - = poprzedni katalog\n");
    printf("-data = pokazuje datę i godzinę\n");
    printf("-help = pokazuje wszystkie możliwe funkcje\n");
    printf("-touch = tworzy plik\n");
    printf("-exit = wylacza program\n");
	printf(COLOR_RESET);
	return;
}
void data(){
    time_t czas = time(NULL);
    struct tm *tm = localtime(&czas);
    char s[64];
    assert(strftime(s, sizeof(s),"%c", tm));
    printf(RED"%s\n"COLOR_RESET, s);
    return;
}
void cd(){
if(strlen(program)==2){
    chdir(getenv("HOME"));
}
    else{
    f=strtok(program,c);
    strcpy(f,strtok(NULL,c));
    u=open(f,O_RDONLY);
    if(strcmp(f, "~")==0 )
        chdir(getenv("HOME"));
    else if(strcmp(f,"-")==0 )
        chdir(p);
    else if(u==-1)
        printf(YELLOW"nie ma takiej lokalizacji\n"COLOR_RESET);
    else
        chdir(f);
    strcpy(p,path);
return;
}
}
void touch(char *program){
	l = strtok(program, c);
	l = strtok(NULL, c);
	if(open(l,O_RDONLY) != -1){
		printf(YELLOW"oj byczq pliczek juz jest\n"COLOR_RESET);
		return;
	}
	else{
		creat(l,0673);
	}
return;
}
void exxxc(){
    pid_t childpid=fork();
    int childstatus;
    if(childpid==0){
    char *exxec[1000] = {0};
    exxec[0]=strtok(program,c);
    i=1;
    while(i<strlen(program)){
    exxec[i]=strtok(NULL,c);
    i++;
    }
    execvp(exxec[0], exxec);
    printf(YELLOW"bład, nie ma komendy\n"COLOR_RESET);
    exit(0);
}
    else{
        pid_t tpid=wait(childstatus);
        if(tpid!=childpid)
        return;
}
}


int main(){
while(1){
    getcwd(path,sizeof(path));
    printf(GREEN"{%s}\n$ "COLOR_RESET,path);
    fgets(program, sizeof(program), stdin);
    int len=strlen(program);
    if(program[len-1]=='\n')
        program[len-1]='\0';
    if(strcmp(program,"help")==0){help();
    }
    else if(strcmp(program,"data")==0){data();
    }
    else if(strncmp(program,"cd",2)==0){cd();
    }
    else if(strcmp(program,"exit")==0){
    printf(YELLOW"Naura\n"COLOR_RESET);
    break;
    }
    else if(strncmp(program,"touch",5)==0){touch(program);
    }
    else if(strlen(program)==0){
    printf(YELLOW"czemu nic nie piszesz\n"COLOR_RESET);
    }
    else{exxxc();
    }
    }
    }
