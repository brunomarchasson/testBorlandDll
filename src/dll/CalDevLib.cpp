//   Remarque importante sur la gestion m�moire de la DLL quand votre DLL utilise la
//   version statique de la biblioth�que d'ex�cution (RTL) :
//
//   Si votre DLL exporte des fonctions qui passent des objets cha�ne (ou des classes structs/
//   contenant des cha�nes imbriqu�es) par le biais de param�tres ou de r�sultats de fonctions,
//   vous devrez ajouter la biblioth�que MEMMGR.LIB au projet DLL et aux autres
//   projets qui utilisent la DLL.  Il sera aussi n�cessaire d'utiliser MEMMGR.LIB
//   si d'autres projets utilisant la DLL effectuent des op�rations new ou delete
//   sur des classes ne d�rivant pas de TObject qui sont export�es depuis la
//   DLL. Ajouter MEMMGR.LIB � votre projet changera la DLL et son EXE appelant
//   afin d'utiliser BORLNDMM.DLL en tant que gestionnaire de m�moire.  Dans ces cas,
//   le fichier BORLNDMM.DLL doit �tre d�ploy� avec votre DLL.
//
//   Pour �viter l'emploi de BORLNDMM.DLL, passez des informations cha�ne par
//   le biais de param�tres "char *" ou ShortString.
//
//   Si votre DLL utilise la version dynamique de la RTL, il n'est pas n�cessaire
//   d'ajouter explicitement MEMMGR.LIB car cela sera fait implicitement

#include <vcl.h>
#include <windows.h>
#include "CalDevLib.h"
 #include "CalDev.h"
#pragma hdrstop
#pragma argsused

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}

 CalDev *instance;

void __stdcall init(const wchar_t * name) {
		 instance = new CalDev(name);
 }


wchar_t* __stdcall hi() {
		 return instance->sayHi();
 }

wchar_t* __stdcall hello(){
 return L"Wello";
 } ;
