///Week15-1_PlaySound.cpp
///#include <mmsystem.h>///上週教
#include <windows.h>///另一種寫法,結果一樣
int main()
{           ///先放不存在的檔     上週教 SND_ASYNC
    ///PlaySound("badbadbad.wav", NULL, SND_SYNC );
    PlaySound("07042111.wav", NULL, SND_SYNC );
}///Compile成功,      但是 link 失敗!!
/// .c .cpp =compile=> .o  =link=> .exe
///Setting-Compiler Setting 的 Linker Setting 加 winmm

