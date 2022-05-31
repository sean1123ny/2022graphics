#include <stdio.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;

int main()
{
    mp3.Load("07071064.mp3");
    mp3.play();

    printf("隨便等你輸入數字，程式就卡住囉: ");
    int N;///為了卡住程式不要直接就結束了
    scanf("%d", &N);
}
