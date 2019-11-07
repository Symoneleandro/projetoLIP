#include<iostream>
#include <cstring>
#include<fstream>


using namespace std;
const int STRMAX = 512;
const int MAX=250;
struct Pixel
{
    int r;
    int g;
    int b;
};
struct Img
{
    Pixel m[STRMAX][STRMAX];
    int altura;
    int largura;

};

void abre_img(Img& img);
void salva_img(Img img);

int main()
{
    Img img;
    abre_img(img);
    salva_img(img);
    int limiar;
    cout<<"Digite o limiar:";
    cin>>limiar;

    return 0;
}


void abre_img(Img& img)
{
    char nome[MAX];
    char tipo[2];
    cout<<"insira o nome" <<endl;//(alguma coisa.ppm)
    cin.getline(nome,STRMAX);
    fstream entrada;
    entrada.open(nome);

    if(entrada.is_open())
    {
        entrada >> tipo;

        if(strcmp(tipo,"P3")==0)
        {
            cout<<"Foto carregada com sucesso";
            entrada >> img.largura >> img.altura;
            for (int i =0; i<img.largura; i++)
            {
                for(int j=0; i<img.altura; i++)
                {
                    entrada>>img.m[i][j].r>>img.m[i][j].g>>img.m[i][j].b;

                }
            }

        }

    }
    else
    {
        cout<<"erro na imagem"<<endl;
    }
    entrada.close();
}
void salva_img(Img img)
{
    char nome[STRMAX];
    cout<<"insira o nome do arquivo salvo";
    cin.getline(nome,STRMAX);
    ofstream entrada;
    entrada.open(nome);
    entrada<<"P3"<<endl;
    entrada<<img.largura<<" "<<img.altura<<endl;
    for(int i=0; i<img.largura; i++)
    {
        for(int j=0; j<img.altura; j++)
        {
            entrada<<img.m[i][j].r<<" "<<img.m[i][j].g<<" "<<img.m[i][j].b<<" ";
        }
    }
    entrada.close();
}



