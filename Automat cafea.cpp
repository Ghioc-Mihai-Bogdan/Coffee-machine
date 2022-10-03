#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//functii
int admin();
int meniu_principal();




//variabile globale
int pret[10], cant[6];
int zahar=3, apa=1, cafea=2, lapte=4, crema=5;
int i=1;
int bani, rest, ZaharAles;
int numar;

int main()
{
    //fisiere
        fstream resurse;

        resurse.open ("resurse.txt",ios::in);//citeste resursele
    if (resurse.is_open())
    {
    string cantitate;
    while (getline(resurse,cantitate))
    {
        stringstream preia(cantitate);
        preia >> cant[i];

        i++;

    }
        resurse.close();
    }
    i=1;

    fstream preturi;

        preturi.open ("preturi.txt",ios::in);//citeste preturile
    if (preturi.is_open())
    {
        string cantitate;
    while (getline(preturi,cantitate))
    {

        stringstream preia(cantitate);
        preia >> pret[i];
        i++;
        }
        preturi.close();
    }




    meniu_principal();
    int meniucafea;
    cout << "\n\n=====Meniu Cafea=====\n"<<"(1)Expresso scurt "<<pret[1]<<"lei\n"<<"(2)Expresso lung "<<pret[2]<<"lei\n"<<"(3)Cafea cu lapte "<<pret[3]<<"lei\n"<<"(4)Irish coffee "<<pret[4]<<"lei\n\n"<<endl;

    Alege:

    cin>>meniucafea;

    switch(meniucafea)
    {
            case 1:
            if(bani<pret[1])
            {
                cout <<"Fonduri insuficiente! Alege alta bautura\n"<<endl;
                goto Alege;
            }
            else
            {
                Again1:
                cout << "Alege de la 0 la 5 cat zahar doresti"<<endl;
                cin >> ZaharAles;
                if (ZaharAles>=0 && ZaharAles<=5){
                cout << "Expresso scurt se prepara ..."<<endl;
                cant[apa]-=30;
                cant[zahar]-=ZaharAles;
                cant[cafea]-=15;
                }
                else
                {
                    goto Again1;
                }

            }
            if (bani-pret[1]==1)
                {
                 cout << "Ai primit rest un leu"<<endl;
                }
            else if(bani > pret[1])
            {
                rest = bani-pret[1];
                cout<<"Ai primit rest "<<rest<<" lei"<<endl;
            }
            break;

            case 2:
            if(bani<pret[2])
            {
                cout <<"Fonduri insuficiente! Alege alta bautura\n"<<endl;
                goto Alege;
            }
            else
            {
                Again2:
                cout << "Alege de la 0 la 5 cat zahar doresti"<<endl;
                cin >> ZaharAles;
                if (ZaharAles>=0 && ZaharAles<=5){
                cout << "Expresso lung se prepara ..."<<endl;
                cant[apa]-=60;
                cant[zahar]-=ZaharAles;
                cant[cafea]-=15;
                }
                else
                {
                    goto Again2;
                }
            }
            if (bani-pret[2]==1)
                {
                 cout << "Ai primit rest un leu"<<endl;
                }
            else if(bani > pret[2])
            {
                rest = bani-pret[2];
                cout<<"Ai primit rest "<<rest<<" lei"<<endl;
            }
            break;

            case 3:
            if(bani<pret[3])
            {
                cout <<"Fonduri insuficiente! Alege alta bautura\n"<<endl;
                goto Alege;
            }
            else
            {
                Again3:
                cout << "Alege de la 0 la 5 cat zahar doresti"<<endl;
                cin >> ZaharAles;
                if (ZaharAles>=0 && ZaharAles<=5){
                cout << "Cafea cu lapte se prepara ..."<<endl;
                cant[apa]-=70;
                cant[zahar]-=ZaharAles;
                cant[cafea]-=15;
                cant[lapte]-=20;
                }
                else
                {
                    goto Again3;
                }
            }
            if (bani-pret[3]==1)
                {
                 cout << "Ai primit rest un leu"<<endl;
                }
            else if(bani > pret[3])
            {
                rest = bani-pret[3];
                cout<<"Ai primit rest "<<rest<<" lei"<<endl;
            }
            break;

            case 4:
            if(bani<pret[4])
            {
                cout <<"Fonduri insuficiente! Alege alta bautura\n"<<endl;
                goto Alege;
            }
            else
            {
                Again4:
                cout << "Alege de la 0 la 5 cat zahar doresti"<<endl;
                cin >> ZaharAles;
                if (ZaharAles>=0 && ZaharAles<=5){
                cout << "Irish coffee se prepara ..."<<endl;
                cant[apa]-=70;
                cant[zahar]-=ZaharAles;
                cant[cafea]-=15;
                cant[lapte]-=20;
                cant[crema]-=5;
                }
                else
                {
                    goto Again4;
                }
            }
            if (bani-pret[4]==1)
                {
                 cout << "Ai primit rest un leu"<<endl;
                }
            else if(bani > pret[4])
            {
                rest = bani-pret[4];
                cout<<"Ai primit rest "<<rest<<" lei"<<endl;
            }
            break;

        default: cout<<"Nu ai selectat o bautura din meniu! Alege una din bauturile din lista"<<endl;
        goto Alege;
    }

    resurse.open("resurse.txt",ios::out);
        if (resurse.is_open())
        {
            resurse << cant[apa] << endl << cant[cafea] << endl << cant[zahar] << endl << cant[lapte] << endl << cant[crema];
            resurse.close();
        }




    return 0;
}

int admin()
{
    fstream preturi;
    int pin;
    cout << "Introdu codul pin"<<endl;

    Pin:
    cin >> pin;

    if (pin==1234){
            int admin;

            Admin:
    cout << "(1)Lista preturi"<<endl;
    cout << "(2)Schimba pret"<<endl;
    cout << "(3)Inapoi"<<endl;


    cin >> admin;
    switch (admin)
    {
        case 1: cout << "(1)Expresso scurt "<<pret[1]<<"lei\n"<<"(2)Expresso lung "<<pret[2]<<"lei\n"<<"(3)Cafea cu lapte "<<pret[3]<<"lei\n"<<"(4)Irish coffee "<<pret[4]<<"lei"<<endl<<endl<<endl;
        goto Admin;

        case 2: cout << "Alege numarul bauturii\n"<<endl;

        Bautura:
        cin >> numar;

        switch (numar)
        {
        case 1: cout << "Seteaza pretul: ";
            cin >> pret[1];
            preturi.open("preturi.txt",ios::out);
        if (preturi.is_open())
        {
           preturi << pret[1] << endl << pret[2] << endl << pret[3] << endl << pret[4];
           preturi.close();
        }
            meniu_principal();
            break;

        case 2: cout << "Seteaza pretul: ";
            cin >> pret[2];
            preturi.open("preturi.txt",ios::out);
        if (preturi.is_open())
        {
           preturi << pret[1] << endl << pret[2] << endl << pret[3] << endl << pret[4];
           preturi.close();
        }
            meniu_principal();
            break;

        case 3: cout << "Seteaza pretul: ";
            cin >> pret[3];
            preturi.open("preturi.txt",ios::out);
        if (preturi.is_open())
        {
           preturi << pret[1] << endl << pret[2] << endl << pret[3] << endl << pret[4];
           preturi.close();
        }
            meniu_principal();
            break;

        case 4: cout << "Seteaza pretul: ";
            cin >> pret[4];

        preturi.open("preturi.txt",ios::out);
        if (preturi.is_open())
        {
           preturi << pret[1] << endl << pret[2] << endl << pret[3] << endl << pret[4];
           preturi.close();
        }
            meniu_principal();
            break;

        default: cout << "Nu ai selectat o bautura existenta! Introdu din nou numarul bauturii"<<endl;
        goto Bautura;

        }
        break;
        case 3: meniu_principal();
        break;
        }
    }
    else {
        cout << "Codul pin introdus este gresit\n"<<"Reintrodu codul pin: "<<endl;
        goto Pin;
    }

}

int meniu_principal()
{

int meniu;

    cout<<"Apasati 1 pentru a intra in meniu"<<endl;

    Meniu:

    cin>>meniu;
    switch(meniu)
    {
        case 1: cout<<"Introduceti suma dorita: "<<endl;
            cin>>bani;
            cout<<"Balance: "<<bani<<" lei."<<endl;
            break;
        case 2: cout<<"Ati intrat in meniul administratorului\n"<<endl;
                admin();
                break;
        default: cout <<"Apasati 1 pentru a intra in meniu"<<endl;
        goto Meniu;



    }
return 0;
}
