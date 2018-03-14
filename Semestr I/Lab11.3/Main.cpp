// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Vector3, VectorTrans3 i Matrix3 to obiekty tylko trojwymiarowe.

// Vector3 to wektor "pionowy", natomiast VectorTrand3, to wektor
// "poziomy". Iloczyny tych obiektow wykonuje sie z godnie z zasadami
// mnozenia macierzy.

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab05. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Powinien działać dla dowolnej
// liczby przekształceń.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// /home/dokt/dog/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_05


#include<iostream>
#include"lab05.h"

int main ()
{
  using namespace std;
  cout<<"===== START ====="<<endl;
  
  Vector3 speed (1, 2.2, 3);
  VectorTrans3 speedTrans (3, 2, 1);
  
  cout <<"speed:\n"<<speed<<"\n";
  cout <<"speedTrans:\n"<<speedTrans<<"\n\n";

  number_t scalar = speedTrans*speed; //speedTrans * speed == speedTrans.operator*(speed)
  cout <<speedTrans<<"\n*\n"<<speed<<"\n=\n" <<scalar<<"\n\n";
  
  Matrix3 matrix = speed*speedTrans;
  cout <<speed<<"\n*\n"<<speedTrans<< "\n=\n"<<matrix<<"\n";

  cout<<"===== END ====="<<endl;
  
  return 0;
  cout<<"bye bye"<<endl;
}
/*
false start
===== START =====
speed:
(1)
(2.2)
(3)
speedTrans:
(3, 2, 1)

(3, 2, 1)
*
(1)
(2.2)
(3)
=
10.4

(1)
(2.2)
(3)
*
(3, 2, 1)
=
(3, 2, 1)
(6.6, 4.4, 2.2)
(9, 6, 3)

===== END =====
bye bye
*/
