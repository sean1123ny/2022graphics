#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("07071064.wav", NULL, SND_ASYNC);///ASYNCぃ单
    while(1){
        printf("叫块计: ");
        int N;
        scanf("%d", &N);
        if(N==1) PlaySound("do.wav", NULL, SND_ASYNC);///ASYNCぃ单
        if(N==2) PlaySound("re.wav", NULL, SND_ASYNC);///ASYNCぃ单
        if(N==3) PlaySound("mi.wav", NULL, SND_ASYNC);///ASYNCぃ单
    }
}
