// Le bloc ifdef suivant est la fa�on standard de cr�er des macros qui facilitent l'exportation 
// � partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compil�s avec le symbole INPUTOUTPUTLIBRARY_EXPORTS
// d�fini sur la ligne de commande. Ce symbole ne doit pas �tre d�fini pour un projet
// qui utilisent cette DLL. De cette mani�re, les autres projets dont les fichiers sources comprennent ce fichier consid�rent les fonctions 
// INPUTOUTPUTLIBRARY_API comme �tant import�es � partir d'une DLL, tandis que cette DLL consid�re les symboles
// d�finis avec cette macro comme �tant export�s.
#ifdef INPUTOUTPUTLIBRARY_EXPORTS
#define INPUTOUTPUTLIBRARY_API __declspec(dllexport)
#else
#define INPUTOUTPUTLIBRARY_API __declspec(dllimport)
#endif

// Cette classe est export�e de InputOutputLibrary.dll
class INPUTOUTPUTLIBRARY_API CInputOutputLibrary {
public:
	CInputOutputLibrary(void);
	// TODO: ajoutez ici vos m�thodes.
};

extern INPUTOUTPUTLIBRARY_API int nInputOutputLibrary;

//INPUTOUTPUTLIBRARY_API int fnInputOutputLibrary(void);
INPUTOUTPUTLIBRARY_API int mp3_to_wav(wchar_t* sourcefile, wchar_t* destinationfile);
