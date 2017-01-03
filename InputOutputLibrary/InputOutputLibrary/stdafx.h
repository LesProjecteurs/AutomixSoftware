// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclure les en-t�tes Windows rarement utilis�s
// Fichiers d'en-t�te Windows�:
#include <windows.h>



// TODO: faites r�f�rence ici aux en-t�tes suppl�mentaires n�cessaires au programme
#define WINVER _WIN32_WINNT_WIN7


#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <stdio.h>
#include <mferror.h>
#include "InputOutputLibrary.h"
#include <lame.h>

template <class T> void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}


HRESULT WriteWaveFile(
	IMFSourceReader *,   // Pointer to the source reader.
	HANDLE,               // Handle to the output file.
	LONG           // Maximum amount of audio data to write, in msec.
);

HRESULT ConfigureAudioStream(
	IMFSourceReader *,   // Pointer to the source reader.
	IMFMediaType **   // Receives the audio format.
);

HRESULT WriteWaveHeader(
	HANDLE,               // Output file.
	IMFMediaType *,   // PCM audio format.
	DWORD *           // Receives the size of the header.
);

HRESULT WriteToFile(HANDLE, void*, DWORD);

DWORD CalculateMaxAudioDataSize(
	IMFMediaType *,    // The PCM audio format.
	DWORD,              // The size of the WAVE file header.
	DWORD           // Maximum duration, in milliseconds.
);

HRESULT WriteWaveData(
	HANDLE,               // Output file.
	IMFSourceReader *,   // Source reader.
	DWORD,       // Maximum amount of audio data (bytes).
	DWORD *       // Receives the amount of data written.
);

HRESULT FixUpChunkSizes(
	HANDLE,           // Output file.
	DWORD,         // Size of the 'fmt ' chuck.
	DWORD        // Size of the 'data' chunk.
);