/*
----------------------------------------------------------------------------
A LICENÇA BEER-WARE ou A LICENÇA DA CERVEJA (Revisão 43 em Portugués Brasil):
<pedrogaya@gmail.com> escreveu este arquivo. Enquanto esta nota estiver na coisa você poderá utilizá-la
como quiser. Caso nos encontremos algum dia e você me reconheça e ache que esta coisa tem algum
valor, você poderá me pagar uma cerveja em retribuição (ou mais de uma), Pedro Gaya.
----------------------------------------------------------------------------
*/
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


void clear(){
	#ifdef _WIN32
	    system("cls");
	#else
	    system ("clear");
	#endif
}

void abertura(){
	cout << " .88888.                               dP                        dP          dP                                                   " << endl;
	cout << "d8'   `88                              88                        88          88                                                   " << endl;
	cout << "88       .d8888b.88d888b..d8888b..d888b88.d8888b.88d888b.  .d888b88.d8888b.  8888d8b.d8b..d8888b..d8888b..d8888b.88d888b..d8888b. " << endl;
	cout << "88   YP8888ooood888'  `8888'  `8888'  `8888'  `8888'  `88  88'  `8888ooood8  8888'`88'`8888'  `8888'  `8888ooood888'  `88Y8ooooo. " << endl;
	cout << "Y8.   .8888.  ...88      88.  .8888.  .8888.  .8888        88.  .8888.  ...  8888  88  8888.  .8888.  .8888.  ...88    88      88 " << endl;
	cout << " `88888' `88888P'dP      `88888P8`88888P8`88888P'dP        `88888P8`88888P'  dPdP  dP  dP`88888P8`8888P88`88888P'dP    dP`88888P' " << endl;
	cout << "                                                                                                      .88                         " << endl;
	cout << "                                                                                                  d8888P                          " << endl;
}

void limpar(){
	clear();
	abertura();
}

int menu(){
	int user;
	do{
	limpar();
	cout << "\n\n\tSeja bem-vindo ao gerador de imagens. Selecione a opcao desejada:" << endl;
	cout << endl << "\t\t1-Gerar imagem basica." << endl;
	cout << "\t\t2-Gerar figura geometrica." << endl;
	cin >> user;
	}while(user != 1 && user != 2);
	return user;
}

int main(){
	int opcao,linhas,colunas,userbasica,cor,R,G,B,final,forma,centrox,centroy,dx,dy,corcirculo;
	string arquivo,completo;
	do{
		opcao = menu();
		if(opcao == 1){
			do{
				limpar();
				cout << "Favor informar tamanho desejado para a imagem (x e y):" << endl;
				cin >> linhas;
				cin >> colunas;
			}while(linhas <= 0 || colunas <= 0);
			do{
				limpar();
				cout << "Favor informar nome desejado:" << endl;
				cin >> arquivo;
				completo = arquivo + ".ppm";
			}while(arquivo.empty());
			FILE *arquivoFoto = fopen(completo.c_str(), "wb");
			fprintf(arquivoFoto, "P6\n%d %d\n255\n", linhas, colunas);
			do{
				limpar();
				cout << "Selecione opcao desejada:" << endl;
				cout << "\t1-Imagem gerada aleatoria." << endl;
				cout << "\t2-Imagem com cor solida." << endl;
				cin >> userbasica;
			}while(userbasica != 1 && userbasica != 2);
			if(userbasica==1){
				for(int i = 0;i < linhas; i++){
					for(int j = 0;j < colunas; j++){
						static unsigned char cor[3];
						cor[0] = (i) % 256;
						cor[1] = (j) % 256;
						cor[2] = (i+j) % 256;
						fwrite(cor, 1, 3, arquivoFoto);
					}
				}
			}
			else{
				R=0;
				G=0;
				B=0;
				do{
				limpar();
				cout << "Selecione a opcao desejada:" << endl;
				cout << "\t1-Branco" << endl;
				cout << "\t2-Azul" << endl;
				cout << "\t3-Vermelho" << endl;
				cout << "\t4-Verde" << endl;
				cout << "\t5-Amarelo" << endl;
				cout << "\t6-Magenta" << endl;
				cout << "\t7-Ciano" << endl;
				cout << "\t8-Preto" << endl;
				cin >> cor;
				}while(cor < 1 || cor > 8);
				if(cor == 1 || cor == 3 || cor == 5 || cor == 6){
					R = 255;
				}
				if(cor == 1 || cor == 4 || cor == 5 || cor == 7){
					G = 255;
				}
				if(cor == 1 || cor == 2 || cor == 6 || cor == 7){
					B = 255;
				}
				for(int i = 0;i < linhas; i++){
					for(int j = 0;j < colunas; j++){
						static unsigned char cor[3];
						cor[0] = R;
						cor[1] = G;
						cor[2] = B;
						fwrite(cor, 1, 3, arquivoFoto);
					}
				}
			}
			fclose(arquivoFoto);
		}
		else{
			do{
				limpar();
				cout << "Escolha a figura desejada:" << endl;
				cout << "\t1-Circulo" << endl;
				cin >> forma;
			}while(forma != 1);
			do{
				limpar();
				cout << "Favor informar tamanho desejado para a imagem (x e y):" << endl;
				cin >> linhas;
				cin >> colunas;
			}while(linhas <= 0 || colunas <= 0);
			do{
				limpar();
				cout << "Favor informar nome desejado:" << endl;
				cin >> arquivo;
				completo = arquivo + ".ppm";
			}while(arquivo.empty());
			FILE *arquivoFoto = fopen(completo.c_str(), "wb");
			fprintf(arquivoFoto, "P6\n%d %d\n255\n", linhas, colunas);
			if(forma == 1){
				do{
					limpar();
					cout << "Favor informar a cor desejada:" << endl;
					cout << "\t1-Branco" << endl;
					cout << "\t2-Azul" << endl;
					cout << "\t3-Vermelho" << endl;
					cout << "\t4-Verde" << endl;
					cout << "\t5-Amarelo" << endl;
					cout << "\t6-Magenta" << endl;
					cout << "\t7-Ciano" << endl;
					cout << "\t8-Preto" << endl;
					cout << "\t9-Gradiente aleatorio" << endl;
					cin >> corcirculo;
				}while(corcirculo < 1 && corcirculo > 9);
				R=0;
				G=0;
				B=0;
				if(corcirculo == 1 || corcirculo == 3 || corcirculo == 5 || corcirculo == 6){
					R = 255;
				}
				if(corcirculo == 1 || corcirculo == 4 || corcirculo == 5 || corcirculo == 7){
					G = 255;
				}
				if(corcirculo == 1 || corcirculo == 2 || corcirculo == 6 || corcirculo == 7){
					B = 255;
				}
				centrox = linhas/2;
				centroy = colunas/2;
				for(int i = 0;i < linhas; i++){
					for(int j = 0;j < colunas; j++){
						dx = centrox - i;
						dy = centroy - j;
						static unsigned char cor[3];
						if((dx*dx + dy*dy) <= (centrox*centrox)){
							if(corcirculo == 9){
								cor[0] = (i) % 256;
								cor[1] = (j) % 256;
								cor[2] = (i+j) % 256;
							}
							else{
								cor[0] = R;
								cor[1] = G;
								cor[2] = B;
							}
						}
						else{
							cor[0] = 255;
							cor[1] = 255;
							cor[2] = 255;
						}
						fwrite(cor, 1, 3, arquivoFoto);
					}
				}
			}
		}
		do{
			limpar();
			cout << "\tImagem gerada com sucesso. Deseja retornar ao menu principal?" << endl;
			cout << "\t\t1-Sim" << endl << "\t\t2-Nao" << endl;
			cin >> final;
			}while(final != 1 && final != 2);
		}while(final == 1);
	clear();
	return 0;
}
