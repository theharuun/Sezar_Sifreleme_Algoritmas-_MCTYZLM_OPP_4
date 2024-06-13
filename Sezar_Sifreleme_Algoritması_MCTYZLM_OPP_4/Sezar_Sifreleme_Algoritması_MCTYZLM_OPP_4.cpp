#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <stdio.h>

using namespace std;

class sezar
{
private:
	char metin[1024];
	char sifreliMetin[1024];
	char desifrelimetin[1024];
	string alfabe = "abcdefghijklmnopqrstuvywxz";    // abc=def üç kaydırmayla yapılan bir sifreleme sistemidir 

public:
	void sifrele();
	void desifreli();
};

void sezar::sifrele()
{
	cout << "Metin : ";   gets_s(metin);     // kullanıcadan metin aldık
	int n = strlen(metin);    //metin karakter sayısını sayıya dönüştürdük
	metin[n] = '\0';         //metinin son karakterini 0 atadık 
	int i=0, j;

	while (i < n)                                
	{
		int sonuc = 0;
		for (j = 0; j < 26; j++)
		{
		  int	indis = j;   
		  if (metin[i] == alfabe[j])                      //eğer alfabedeki değerlerden biri metindeki bir değere eşit olduğunda
		   {                                             // örnek: metindeki 3 karakter diyelimki alfabedeki 8. harfe denk geldi  
			  sonuc = 1;                               // indisi +3 olarak değiştiriyoruz böylece oradaki indisi aldık ve 
			  indis += 3;                               // sifrelimetinin 3 yerindeki yerine 8 + 3den dolayı 11 indisi yazmış oluyoruz
			    if (indis >= 26)                           //indis 26 ya eşit ve geçtiğinde sıfırlayıp  z den sonra tekrar a ya dönmesini sağlamaıyız
		        indis = indis % 26;                             //yoksa program 26dan sonra hatalı çalışır
		
				
			  sifreliMetin[i] = alfabe[indis];
			    
		   }
		  if (sonuc == 0)                          
		   {
			  sifreliMetin[i] = metin[i];          //sifreli metindeki indesleri metindeki indeslerin old yerlere doğru şekilde taşımamızı sağladı
		   }

		}
		i++;

	}
	sifreliMetin[i] = '\0';
	cout << "\nSifreli Metin :" << sifreliMetin << endl;

}

void sezar::desifreli()
{
	int n = strlen(sifreliMetin);

	int i = 0, j;

	while (i < n)
	{
		int sonuc = 0;
		for (j = 0; j < 26; j++)
		{
			int	indis = j;
			if (sifreliMetin[i] == alfabe[j])
			{
				sonuc = 1;
				indis -= 3;
				   if (indis  <0)
				   indis = indis + 26;
			  desifrelimetin[i] = alfabe[indis];
				
			}
			if (sonuc == 0)
			{
				desifrelimetin[i] = sifreliMetin[i];
			}

		}
		i++;

	}
	desifrelimetin[i] = '\0';
	cout << "\n\nDesifreli Metin :" << desifrelimetin << endl;


}

int main()
{
	sezar s2;
	s2.sifrele();
	s2.desifreli();

	return 0;
}
