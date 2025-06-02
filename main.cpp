/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: larissa-avila
 *
 * Created on 17 de junho de 2024, 17:01
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "imagens.h"

using namespace std;

/*
 * Projeto criado para manipular imagens. O programa recebe e lê uma imagem em formato pgm,
 * e a partir dela, realiza diferentes ações: escurecer ou clarear imagem, encontrar a 
 * imagem negativa, binarizar a imagem, iconizar, criar ruídos na imagem, ou suavizar. Todas
 * as funcionalidades estão dispostas em um menu de opções que repete continuamente cada ação,
 * até que a opção digitada seja 0, que informa o final do programa. Há ainda a opção 1, que faz
 * a leitura da imagem inicial.
 */



int main(int argc, char** argv) {
    
    Timagem img;
    string nome;
    int coluna, linha, tons, opcao;


    do{
        cout<<endl<<"Menu de Opções"<<endl<<"--------------------------------"<<endl;
        cout<<"Opção 1: Ler imagem"<<endl;
        cout<<"Opção 2: Escurecer ou clarear imagem"<<endl;
        cout<<"Opção 3: Encontrar a imagem negativa"<<endl;
        cout<<"Opção 4: Binarizar imagem"<<endl;
        cout<<"Opção 5: Iconizar a imagem"<<endl;
        cout<<"Opção 6: Criar ruídos na imagem"<<endl;
        cout<<"Opção 7: Aplicar filtro para suavizar a imagem"<<endl;
        cout<<"Opção 0: Sair do programa"<<endl;
        cout<<"Digite sua opção: ";
        cin>>opcao;
        cout<<"----------------------------------"<<endl;
        switch(opcao){
            
            case 1: {
                ifstream arquivo("stanford2.pgm");
                if(!arquivo.is_open()){
                    cout << "Erro: não foi possível abrir o arquivo stanford2.pgm" << endl;
                    break;
                }
                cout<<"Arquivo aberto"<<endl;
                arquivo >> nome;
                arquivo >> coluna;
                arquivo >> linha;
                arquivo >> tons;
                for (int i = 0; i< linha; i++ ){
                    for (int j=0; j<coluna; j++){
                        arquivo >> img[i][j];
                    }
                }
                arquivo.close();  
                break;
            }

            case 2: {
                int caso, fator;
                ofstream arquivo2("tonalizada.pgm");
                cout<<"Digite 0 para clarear a imagem e 1 se quiser escurecer."<<endl;
                cin>>caso;
                if(caso == 0){
                    cout<<endl<<"Digite quantos tons você deseja clarear: ";
                    cin>>fator;
                    clarear_imagem(img, linha, coluna, tons, fator);
                }else{
                    cout<<"Digite quantos tons você deseja escurecer: ";
                    cin>>fator;
                    escurecer_imagem(img, linha, coluna, tons, fator);
                }
                arquivo2 << nome << endl;
                arquivo2 << coluna << " " << linha << endl;
                arquivo2 << tons << endl;
                for(int i=0; i<linha; i++){
                    for(int j=0; j<coluna; j++){
                        arquivo2<<img[i][j]<<" ";
                    }
                }
                arquivo2.close();
                break;
            }

            case 3: {
                ofstream arquivo3("negativa.pgm");
                imagem_negativa(img, linha, coluna, tons);
                arquivo3 << nome << endl;
                arquivo3 << coluna << " " << linha << endl;
                arquivo3 << tons << endl;
                for(int i=0; i<linha; i++){
                    for(int j=0; j<coluna; j++){
                        arquivo3<<img[i][j]<<" ";
                    }
                }
                arquivo3.close();
                break;
            }
            
            case 4: {
                int fator;
                ofstream arquivo4("binarizada.pgm");
                cout<<"Digite o fator que você deseja para binarizar a imagem. ";
                cin>>fator;
                binarizar_imagem(img, linha, coluna, tons, fator);
                arquivo4 << nome << endl;
                arquivo4 << coluna << " " << linha << endl;
                arquivo4 << "2" << endl;
                for(int i=0; i<linha; i++){
                    for(int j=0; j<coluna; j++){
                        arquivo4<<img[i][j]<<" ";
                    }
                }
                arquivo4.close();
                break;
            }
            
            case 5: {
                ofstream arquivo5("iconizada.pgm");
                int img2[64][64];
                iconizar_imagem(img, linha, coluna, img2);
                arquivo5<< nome << endl;
                arquivo5 << "64 64" << endl;
                arquivo5 << tons << endl;
                for(int i=0; i<64; i++){
                    for(int j=0; j<64; j++){
                        arquivo5 <<img2[i][j]<<" ";
                    }
                }
                arquivo5.close();
                break;
            }
            
            case 6: {
                ofstream arquivo6("ruidos.pgm");
                ruidos(img, linha, coluna);
                arquivo6<<nome<<endl;
                arquivo6<<coluna<<" "<<linha<<endl;
                arquivo6<<tons<<endl;
                for(int i=0; i<linha; i++){
                    for(int j=0; j<coluna; j++){
                        arquivo6<<img[i][j]<<" ";
                    }
                }
                arquivo6.close();
                break;
            }
            
            case 7: {
                ofstream arquivo7("suavizada.pgm");
                filtro(img, linha, coluna);
                arquivo7<<nome<<endl;
                arquivo7<<coluna<<" "<<linha<<endl;
                arquivo7<<tons<<endl;
                for(int i=0; i<linha; i++){
                    for(int j=0; j<coluna; j++){
                        arquivo7<<img[i][j]<<" ";
                    }
                }
                arquivo7.close();
                break;
            }

        }
    }while(opcao != 0);

    return 0;
}
