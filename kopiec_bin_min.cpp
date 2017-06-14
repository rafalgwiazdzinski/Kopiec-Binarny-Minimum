//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;

string cr,cl,cp;      // łańcuchy do znaków ramek
int rozmiar;
int *tablica;
int n=0;

void zapytanieOrozmiarTablicy() {
	while(1) {
		system("cls");
		cout << "Podaj maksymalna liczbe elementow w strukturze: " << endl;
		cin >> rozmiar;
		if(rozmiar>0) {
			rozmiar = rozmiar;
			tablica = new int[rozmiar];
			break;
		}
	}
}

int parent(int index)
{
	if(index%2 == 0) {
		return ((index-1)/2);
	} else {
		return (index/2);
	}
}

int rightChild(int a)
{
	return ((2*a)+2);
}

int leftChild(int a)
{
	return ((2*a)+1);
}

void minHeapify(int a) {
	int smallest;
	if(leftChild(a) <= n-1 && tablica[leftChild(a)] < tablica[a]) {
		smallest = leftChild(a);
	} else {
		smallest = a;
	}
	if (rightChild(a) <= n-1 && tablica[rightChild(a)] < tablica[smallest]) {
		smallest = rightChild(a);
	}
	if (smallest != a) {
		int temp = tablica[a];
		tablica[a] = tablica[smallest];
		tablica[smallest] = temp;
		minHeapify(smallest);
	}
}

void insert(int key)
{
	n++;
	int i = n - 1;
	while (i > 0 && tablica[parent(i)] > key) {
		tablica[i] = tablica[parent(i)];
		i=parent(i);
	}
	tablica[i] = key;
}

int pobierzLiczbe() {
	int liczba;
	while(1) {
    	system("cls");
		cout << "Podaj liczbe: " << endl;
		cin >> liczba;
		if(liczba>=0) {
			break;
		}
	}
	return liczba;
}


void printTree(string sp, string sn, int v) {
  string s;

  if(v < n)
  {
	s = sp;
	if(sn == cr) s[s.length() - 2] = ' ';
	printTree(s + cp, cr, 2 * v + 2);

	s = s.substr(0,sp.length()-2);

	cout << s << sn << tablica[v] << endl;

	s = sp;
	if(sn == cl) s[s.length() - 2] = ' ';
	printTree(s + cp, cl, 2 * v + 1);
  }
}

void printArray() {
	int i;
	for(i = 0; i < n; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}

void buildMinHeap() {
	 for (int i = (n/2); i >= 1; i--) {
		minHeapify(i-1);
	 }
}

void getMinKey() {
	/*int minKey = tablica[0];
	int element = 0;
	for(int i = 0; i<rozmiar; i++) {
		if( tablica[i] < minKey ) {
			minKey = tablica[i];
			element = i + 1;
		}
	}
	cout << "Najmniejszy element kopca to " << element <<" o wartosci: " << minKey << endl; */
	cout << "Najmniejszym elementem kopca jest: " << tablica[0] << endl;
}

int main()
{
	int i, v;
	zapytanieOrozmiarTablicy();
	for(int i = 0; i<rozmiar; i++) {
        tablica[i] = 0;
	}
	/*srand(time(NULL));
	rozmiar = 100;
	tablica = new int[rozmiar];
	for(int i = 0; i<rozmiar; i++) {
		int v1 = rand() % 1000 + 1;
		insert(v1);
	}*/
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	int wybranaopcja = 0;
	char znak;
    
	while( wybranaopcja != 5 )
    {
		system( "cls" );
		if( wybranaopcja == 0 ) cout << "-->insert\n";
		else cout << "insert\n";
        
		if( wybranaopcja == 1 ) cout << "-->printTree\n";
		else cout << "printTree\n";
        
		if( wybranaopcja == 2 ) cout << "-->printArray\n";
		else cout << "printArray\n";

		if( wybranaopcja == 3 ) cout << "-->buildMinHeap\n";
		else cout << "buildMinHeap\n";

		if( wybranaopcja == 4 ) cout << "-->getMinKey\n";
		else cout << "getMinKey\n";

		znak = getch();

		switch( znak )
		{
        case 72: //strzalka w gore
            wybranaopcja--;
            break;
		case 80: //strzalka w dol
            wybranaopcja++;
			break;
		case 13: //enter
            if(wybranaopcja == 0) {
				system("cls");
				if(n < rozmiar) {
					insert(pobierzLiczbe());
				} else {
					cout <<"Nie mozna wstawic wiecej elementow do kopca" << endl;
                	system("PAUSE");
				}
			} else if(wybranaopcja == 1) {
				system( "cls" );
				printTree("","",0);
				system("PAUSE");
			} else if(wybranaopcja == 2) {
				system( "cls" );
				printArray();
				system("PAUSE");
			} else if(wybranaopcja == 3) {
				buildMinHeap();
				system("PAUSE");
			} else if(wybranaopcja == 4) {
				system( "cls" );
				getMinKey();
				system("PAUSE");
            }
			break;
		}
		if( wybranaopcja < 0 ) wybranaopcja++;
        
		if( wybranaopcja > 4 ) wybranaopcja--;
	}
}
