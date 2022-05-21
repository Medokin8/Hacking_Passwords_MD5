#include <iostream>
#include <fstream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>

using namespace std;

void hashfunc(char* word1, char* word2, char* output) {
    //zloaczenie slow
    char concat[100];
    strcpy(concat, word1);
    strcat(concat, word2);

    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5,concat,strlen(concat));
    MD5_Final(output,&md5);    
}


int main()
{
  // 1) wczytanie hasel do tablicy
  // 2) wczytanie slownika do tablicy dynamicznej
  // 3) robienie hasel ze slownika
  // 4) translacja hasel przez MD5
  // 5) porownanie hasel
  // 6) zapis znalezionego


  // 1) wczytanie hasel do tablicy
  string hasla[1000]; //statyczna tablica hasel
  ifstream odczyt_h("hasla.txt");
  int ilosc_hasel=0;
  if(odczyt_h.is_open())
    {
      int i=0; //dla wyrazow
      int j=0; //dla wpisywania hasel
      char wyraz[100]; //maksymalnie 99 znaków
      while(odczyt_h>>wyraz) //dopóki jest co czytać
	{
	  i++;
	  if(i%2==0) //ignorowanie pierwszego wyrazu - maila
	    {
	      hasla[j]=wyraz; //wpisanie hasla do tablicy
	      j++;
	      ilosc_hasel++;
	    }
	}
    }
  else
    cout<<"Nie udało się otworzyć pliku (hasla)"; //jak brak pliku

  //for(int i=0;i<ilosc_hasel;i++) //sprawdzenie wywolania hasel
  //  cout<<hasla[i]<<endl;

  // 2) wczytanie slownika do tablicy dynamicznej
  ifstream odczyt_s("slownik.txt"); //otworzenie slownika
  int ilosc_slow=0;
  if(odczyt_s.is_open()) //jak otwarto
    {
      char wyraz[100];
      while(odczyt_s>>wyraz) //dopoki sa wyrazy
	{
	  ilosc_slow++; // liczymy slowka
	}
    }
  else
    cout<<"Nie udało się otworzyć pliku (slownik)";
  
  odczyt_s.close();
  
  odczyt_s.open("slownik.txt"); // by jeszcze raz przejsc plik
  string * slownik = new string [ilosc_slow]; //dynamiczna tablica slownika
  if(odczyt_s.is_open())
    {
      int i=0;
      string wyraz;
      while(i<ilosc_slow)
	{
	  // getline(odczyt_s, wyraz, '\n'); // zczytuje slowa, jedno slowo = jedna linia
	  //slownik[i]=wyraz; //zapisuje slowa
	  i++;
	}
    }

  //for(int i=0;i<ilosc_slow;i++) //sprawdzenie zczytnaia slownika
  //  cout<<slownik[i]<<endl;


  // 3) robienie hasel ze slownika
  char slowno_md5[100];
  a=slownik[19];
  b=slownik[41910];
  cout<<a<<" "<<b<<endl;
  hashfunc(a,b,ret);
  return 0;
}
