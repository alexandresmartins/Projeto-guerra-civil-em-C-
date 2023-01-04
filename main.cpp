#include "mylib.h"
#include "rlutil.h"
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace rlutil;

//Struct heroi usado para declarar os vetores que receber�o cada her�i lido dos arquivos.
struct heroi
{
    char CodigoHeroi;
    char NomeHeroi[30];
    int ForcaHeroi;
    int InteligenciaHeroi;
    int AgilidadeHeroi;
};

//Fun��o utilizada para fazer a leitura dos her�is do arquivo "HeroisHomemDeFerro.txt.
void LerHeroisHomemDeFerro(heroi Time[])
{
    //Vari�veis usadas na leitura do arquivo.
    srand(time(NULL));
    char buff;
    ifstream fin;
    int auxiliar;
    //Sorteio de her�is.
    do
    {
        auxiliar=0;
        //Estrutura de repeti��o usada para sortear os do Time Homem de Ferro.
        for(int contador=0; contador<5; contador++)
        {
            Time[contador].CodigoHeroi= rand () % 10 + 48;
        }
        //Estruturas de repeti��o usadas para proibir a repeti��o de her�is no sorteio.
        for(int contador2=4; contador2>=0; contador2--)
        {
            for(int contador3=contador2-1; contador3>=0; contador3--)
            {
                if(Time[contador2].CodigoHeroi==Time[contador3].CodigoHeroi)
                    auxiliar++;
            }
        }
    }
    while(auxiliar!=0);
    //Leitura do arquivo.
    for(int contador=0; contador<5; contador++)
    {
        fin.open("HeroisHomemDeFerro.txt");
        if (fin.is_open())
        {
            while(fin.good())
            {
                while(Time[contador].CodigoHeroi!=buff)
                {
                    //Grava��o dos dados no vetor do tipo heroi.
                    fin>>buff;
                    fin>>Time[contador].NomeHeroi;
                    fin>>Time[contador].AgilidadeHeroi;
                    fin>>Time[contador].ForcaHeroi;
                    fin>>Time[contador].InteligenciaHeroi;
                }
                fin.close();
            }
            fin.close();
        }
        else
        {
            cout<<"O arquivo n�o pode ser aberto.";
        }
    }
}

//Fun��o utilizada para fazer a leitura dos her�is do arquivo "HeroisCapitaoAmerica.txt.
void LerHeroisCapitaoAmerica(heroi Time[])
{
    //Vari�veis usadas na leitura do arquivo.
    srand(time(NULL));
    char buff;
    ifstream fin;
    int auxiliar;
    //Sorteio de her�is.
    do
    {
        auxiliar=0;
        //Estrutura de repeti��o usada para sortear os do Time Capit�o Am�rica.
        for(int contador=0; contador<5; contador++)
        {
            Time[contador].CodigoHeroi= rand () % 10 + 48;
        }
        //Estruturas de repeti��o usadas para proibir a repeti��o de her�is no sorteio.
        for(int contador2=4; contador2>=0; contador2--)
        {
            for(int contador3=contador2-1; contador3>=0; contador3--)
            {
                if(Time[contador2].CodigoHeroi==Time[contador3].CodigoHeroi)
                    auxiliar++;
            }
        }
    }
    while(auxiliar!=0);
    //Leitura do arquivo.
    for(int contador=0; contador<5; contador++)
    {
        fin.open("HeroisCapitaoAmerica.txt");
        if (fin.is_open())
        {
            while(fin.good())
            {
                while(Time[contador].CodigoHeroi!=buff)
                {
                    //Grava��o dos dados no vetor do tipo heroi.
                    fin>>buff;
                    fin>>Time[contador].NomeHeroi;
                    fin>>Time[contador].AgilidadeHeroi;
                    fin>>Time[contador].ForcaHeroi;
                    fin>>Time[contador].InteligenciaHeroi;
                }
                fin.close();
            }
            fin.close();
        }
        else
        {
            cout<<"O arquivo n�o pode ser aberto.";
        }
    }
}

//Fun��o utilizada para mostrar os her�is de cada time, de acordo com a sua utiliza��o.
void MostrarHerois(heroi Time[], int cemiterio[])
{
    for (int contador=0; contador<5; contador++)
    {
        int verifica=0;
        //Fun��o usada para verificar se um her�i j� foi utilizado.
        for(int contador2=0; contador2<5; contador2++)
        {
            if(contador==cemiterio[contador2])
                verifica++;
        }
        if(verifica==0)
            //Impress�o de her�is n�o utilizados.
            cout<<endl<<"Her�i "<<contador+1<<": "<<Time[contador].NomeHeroi<<", A: "<<Time[contador].AgilidadeHeroi<<", F: "<<Time[contador].ForcaHeroi<<", I: "<<Time[contador].InteligenciaHeroi<<endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int OpcaoMenu, rodadas, caracteristica=0, EscolhaHeroi=0, PontuacaoJogador=0, PontuacaoComputador=0, EscolhaTime=0, VerificaEscolha, HeroiSorteado, CemiterioJogador[5], CemiterioComputador[5], VerificaSorteio;
    //Vetores do tipo Struct heroi onde os dados dos arquivos s�o armazenados.
    heroi TimeJogador[5], TimeComputador[5];
    do
    {
        do
        {
            //Menu de op��es.
            cout<<"----------------------------------Guerra Civil----------------------------------";
            cout<<endl<<endl<<"Escolha a op��o: ";
            cout<<endl<<"1 - Iniciar novo jogo.";
            cout<<endl<<"2 - Ler instru��es.";
            cout<<endl<<"3 - Finalizar o jogo."<<endl;
            readInteger(">> ", OpcaoMenu);
            system("cls");
            if(OpcaoMenu==1)
            {
                rodadas=0;
                //Escolha do time por parte do jogador.
                do
                {
                    cout<<endl<<endl<<"Escolha o time: "<<endl<<"1 - Time Homem de Ferro."<<endl<<"2 - Time Capit�o Am�rica."<<endl;
                    readInteger(">> ", EscolhaTime);
                }
                while(EscolhaTime!=1 && EscolhaTime!=2);
                //Estrutura de repeti��o e vetores CemiterioComputador e CemiterioJogador usados para verifica��o de her�is j� utilizados na partida.
                for(int contador=0; contador<5; contador++)
                {
                    CemiterioComputador[contador]=5;
                    CemiterioJogador[contador]=5;
                }
                //Leitura de herois para cada time.
                if(EscolhaTime==1)
                {
                    cout<<endl<<"Time escolhido: Homem de Ferro.";
                    cout<<endl<<"Time advers�rio: Capit�o Am�rica.";
                    LerHeroisHomemDeFerro(TimeJogador);
                    LerHeroisCapitaoAmerica(TimeComputador);
                }
                else
                {
                    cout<<endl<<"Time escolhido: Capit�o Am�rica.";
                    cout<<endl<<"Time adves�rio: Homem de Ferro.";
                    LerHeroisHomemDeFerro(TimeComputador);
                    LerHeroisCapitaoAmerica(TimeJogador);
                }
                do
                {
                    cout<<endl<<endl<<"Escolha um her�i do seu time: ";
                    cout<<endl<<endl<<"Time escolhido: "<<endl;
                    MostrarHerois(TimeJogador, CemiterioJogador);
                    cout<<endl<<endl<<"Time advers�rio: "<<endl;
                    MostrarHerois(TimeComputador, CemiterioComputador);
                    cout<<endl;
                    //Escolha do heroi por parte do jogador.
                    do
                    {
                        VerificaEscolha=0;
                        readInteger(">> ", EscolhaHeroi);
                        for(int contador=0; contador<5; contador++)
                        {
                            //Verifica��o de her�is utilizados
                            if(EscolhaHeroi-1==CemiterioJogador[contador])
                            {
                                VerificaEscolha++;
                            }
                        }
                        if(VerificaEscolha!=0)
                            cout<<"Her�i indispon�vel, escolha outro: "<<endl;
                    }
                    while(VerificaEscolha!=0 || (EscolhaHeroi!=1 && EscolhaHeroi!=2 && EscolhaHeroi!=3 && EscolhaHeroi!=4 && EscolhaHeroi!=5));
                    CemiterioJogador[rodadas]=EscolhaHeroi-1;
                    //Escolha de caracter�stica para ser comparada.
                    do
                    {
                        cout<<endl<<"Escolha uma caracter�stica: "<<endl<<"1 - Agilidade."<<endl<<"2 - For�a."<<endl<<"3 - Intelig�ncia."<<endl;
                        readInteger(">> ", caracteristica);
                    }
                    while(caracteristica!=1 && caracteristica!=2 && caracteristica!=3);
                    //Sorteio e verifica��o de her�is para o Time Computador.
                    do
                    {
                        VerificaSorteio=0;
                        HeroiSorteado=rand() % 5;
                        for(int contador2=0; contador2<5; contador2++)
                        {
                            if(HeroiSorteado==CemiterioComputador[contador2])
                                VerificaSorteio++;
                        }
                    }
                    while(VerificaSorteio!=0);
                    CemiterioComputador[rodadas]=HeroiSorteado;
                    //Impress�o dos her�is escolhidos.
                    cout<<endl<<"Caracter�stica escolhida: "<<caracteristica<<endl;
                    cout<<"Her�i escolhido: "<<TimeJogador[EscolhaHeroi-1].NomeHeroi<<endl;
                    cout<<"Her�i advers�rio: "<<TimeComputador[HeroiSorteado].NomeHeroi<<endl;
                    //Compara��o das caracter�sticas e impress�o dos resultado da rodada.
                    if(caracteristica==1)
                    {
                        if(TimeJogador[EscolhaHeroi-1].AgilidadeHeroi>TimeComputador[HeroiSorteado].AgilidadeHeroi)
                        {
                            PontuacaoJogador++;
                            cout<<"Voc� ganhou a rodada.";
                        }
                        else if(TimeJogador[EscolhaHeroi-1].AgilidadeHeroi<TimeComputador[HeroiSorteado].AgilidadeHeroi)
                        {
                            PontuacaoComputador++;
                            cout<<"Voc� perdeu a rodada.";
                        }
                        else
                        {
                            PontuacaoJogador++;
                            PontuacaoComputador++;
                            cout<<"Rodada empatada.";
                        }
                    }
                    else if(caracteristica==2)
                    {
                        if(TimeJogador[EscolhaHeroi-1].ForcaHeroi>TimeComputador[HeroiSorteado].ForcaHeroi)
                        {
                            PontuacaoJogador++;
                            cout<<"Voc� ganhou a rodada.";
                        }
                        else if(TimeJogador[EscolhaHeroi-1].ForcaHeroi<TimeComputador[HeroiSorteado].ForcaHeroi)
                        {
                            PontuacaoComputador++;
                            cout<<"Voc� perdeu a rodada.";
                        }
                        else
                        {
                            PontuacaoJogador++;
                            PontuacaoComputador++;
                            cout<<"Rodada empatada.";
                        }
                    }
                    else if(caracteristica==3)
                    {
                        if(TimeJogador[EscolhaHeroi-1].InteligenciaHeroi>TimeComputador[HeroiSorteado].InteligenciaHeroi)
                        {
                            PontuacaoJogador++;
                            cout<<"Voc� ganhou a rodada.";
                        }
                        else if(TimeJogador[EscolhaHeroi-1].InteligenciaHeroi<TimeComputador[HeroiSorteado].InteligenciaHeroi)
                        {
                            PontuacaoComputador++;
                            cout<<"Voc� perdeu a rodada.";
                        }
                        else
                        {
                            PontuacaoJogador++;
                            PontuacaoComputador++;
                            cout<<"Rodada empatada.";
                        }
                    }
                    cout<<endl<<"Pontua��o Jogador: "<<PontuacaoJogador<<endl;
                    cout<<"Pontua��o Computador: "<<PontuacaoComputador<<endl;
                    rodadas++;
                }
                while(PontuacaoJogador<3 && PontuacaoComputador<3);
                //Impress�o do resultado da partida.
                if(PontuacaoJogador==3)
                {
                    cout<<endl<<"Parab�ns, voc� venceu o jogo."<<endl;
                }
                else if(PontuacaoComputador==3)
                {
                    cout<<endl<<"O time advers�rio venceu o jogo."<<endl;
                }
                else
                {
                    cout<<endl<<"A partida terminou empatada."<<endl;
                }
                PontuacaoComputador=0;
                PontuacaoJogador=0;
            }
            else if(OpcaoMenu==2)
            {
                //Instru��es do jogo.
                cout<<endl<<"Instru��es: ";
                cout<<endl<<"1 - O jogador deve escolher entre Time Homem de Ferro e o Time Capit�o Am�rica.";
                cout<<endl<<"2 - Ap�s a escolha, cada time recebe 5 her�is sorteados entre 10 h�rois com 3 caracter�sticas diferentes: Agilidade(A), For�a(F) e Intelig�ncia(I).";
                cout<<endl<<"3 - O jogador escolhe um h�roi e depois uma caracter�stica para ser comparada com o her�i advers�rio, ganha a rodada o time que tiver o her�i com mais pontos na caracter�stica escolhida.";
                cout<<endl<<"4 - Ap�s um her�i ser utilizado ele � automaticamente removido da partida.";
                cout<<endl<<"5 - Caso a rodada termine empatada cada time ganha 1 ponto.";
                cout<<endl<<"6 - Ganha a partida o time que atingir 3 pontos primeiro."<<endl;
            }
            //Encerramento do programa.
            else if(OpcaoMenu==3)
            {
                cout<<"Jogo finalizado.";
            }
        }
        while(OpcaoMenu<1 || OpcaoMenu>3);
    }
    while(OpcaoMenu!=3);
    return 0;
}
