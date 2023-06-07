//   Remarque importante sur la gestion mémoire de la DLL quand votre DLL utilise la
//   version statique de la bibliothèque d'exécution (RTL) :
//
//   Si votre DLL exporte des fonctions qui passent des objets chaîne (ou des classes structs/
//   contenant des chaînes imbriquées) par le biais de paramètres ou de résultats de fonctions,
//   vous devrez ajouter la bibliothèque MEMMGR.LIB au projet DLL et aux autres
//   projets qui utilisent la DLL.  Il sera aussi nécessaire d'utiliser MEMMGR.LIB
//   si d'autres projets utilisant la DLL effectuent des opérations new ou delete
//   sur des classes ne dérivant pas de TObject qui sont exportées depuis la
//   DLL. Ajouter MEMMGR.LIB à votre projet changera la DLL et son EXE appelant
//   afin d'utiliser BORLNDMM.DLL en tant que gestionnaire de mémoire.  Dans ces cas,
//   le fichier BORLNDMM.DLL doit être déployé avec votre DLL.
//
//   Pour éviter l'emploi de BORLNDMM.DLL, passez des informations chaîne par
//   le biais de paramètres "char *" ou ShortString.
//
//   Si votre DLL utilise la version dynamique de la RTL, il n'est pas nécessaire
//   d'ajouter explicitement MEMMGR.LIB car cela sera fait implicitement

#include <vcl.h>
#include <windows.h>
#include "CalDevLib.h"
#include "CalDevDefs.h"
 #include "CalDev.h"
#pragma hdrstop
#pragma argsused


int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	return 1;
}

 CalDev *instance;

void __stdcall CalDev_init(const wchar_t * name) {
		 instance = new CalDev(name);
 }

wchar_t* __stdcall CalDev_hi() {
		 return instance->sayHi();
 }

wchar_t* __stdcall CalDev_hello(){
 return L"Wello";
 } ;

 void __stdcall CalDev_load(Type type,const wchar_t * id ) {
		 instance = new CalDev(type, id);
 }

 void __stdcall CalDev_set( ) {

 }

 P_RESULT __stdcall CalDev_compute(P_OPTIONS opts ) {
	P_RESULT r;
	r->str="computed";
	if(opts->autoOut) r->str="computed with auto out";
	r->num=42;
	return r ;
 }
