///Week15-3 希望能播放 mp3
///MP3檔案小 vs. WAV 檔案大 PlaySound()
///有壓縮/難     原始資料
#include "CMP3_MCI.h" ///下載,放在同目錄
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("現在正在播放羊的聲音\n");
    int N;///找一個人卡住,不要結束
    scanf("%d", &N);
}
