// TestDLL.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <InputOutputLibrary.h>

#pragma comment(lib, "..\\Debug\\InputOutputLibrary.lib")


int main()
{
	mp3_to_wav(L"C:\\Users\\gabon\\Music\\wanna_be_like_you_sim_gretina.mp3", L"C:\\Users\\gabon\\Music\\wav\\wanna_be_like_you_sim_gretina.wav");
	wav_to_mp3("C:\\Users\\gabon\\Music\\wav\\wanna_be_like_you_sim_gretina.wav", "C:\\Users\\gabon\\Music\\wav\\wanna_be_like_you_sim_gretina.mp3");
    return 0;
}

