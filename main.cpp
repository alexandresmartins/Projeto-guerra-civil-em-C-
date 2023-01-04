#include "mylib.h"
#include "rlutil.h"
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace rlutil;

//Struct heroi usado para declarar os vetores que receberão cada herói lido dos arquivos.
struct heroi
{
    char CodigoHeroi;
    char NomeHeroi[30];
    int ForcaHeroi;
    int InteligenciaHeroi;
    int AgilidadeHeroi;
};

//Função utilizada para fazer a leitura dos heróis do arquivo "HeroisHomemDeFerro.txt.
void LerHeroisHomemDeFerro(heroi Time[])
{
    //Variáveis usadas na leitura do arquivo.
    srand(time(NULL));
    char buff;
    ifstream fin;
    int auxiliar;
    //Sorteio de heróis.
    do
    {
        auxiliar=0;
        //Estrutura de repetição usada para sortear os do Time Homem de Ferro.
        for(int contador=0; contador<5; contador++)
        {
            Time[contador].CodigoHeroi= rand () % 10 + 48;
        }
        //Estruturas de repetição usadas para proibir a repetição de heróis no sorteio.
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
                    //Gravação dos dados no vetor do tipo heroi.
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
            cout<<"O arquivo não pode ser aberto.";
        }
    }
}

//Função utilizada para fazer a leitura dos heróis do arquivo "HeroisCapitaoAmerica.txt.
void LerHeroisCapitaoAmerica(heroi Time[])
{
    //Variáveis usadas na leitura do arquivo.
    srand(time(NULL));
    char buff;
    ifstream fin;
    int auxiliar;
    //Sorteio de heróis.
    do
    {
        auxiliar=0;
        //Estrutura de repetição usada para sortear os do Time Capitão América.
        for(int contador=0; contador<5; contador++)
        {
            Time[contador].CodigoHeroi= rand () % 10 + 48;
        }
        //Estruturas de repetição usadas para proibir a repetição de heróis no sorteio.
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
                    //Gravação dos dados no vetor do tipo heroi.
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
            cout<<"O arquivo não pode ser aberto.";
        }
    }
}

//Função utilizada para mostrar os heróis de cada time, de acordo com a sua utilização.
void MostrarHerois(heroi Time[], int cemiterio[])
{
    for (int contador=0; contador<5; contador++)
    {
        int verifica=0;
        //Função usada para verificar se um herói já foi utilizado.
        for(int contador2=0; contador2<5; contador2++)
        {
            if(contador==cemiterio[contador2])
                verifica++;
        }
        if(verifica==0)
            //Impressão de heróis não utilizados.
            cout<<endl<<"Herói "<<contador+1<<": "<<Time[contador].NomeHeroi<<", A: "<<Time[contador].AgilidadeHeroi<<", F: "<<Time[contador].ForcaHeroi<<", I: "<<Time[contador].InteligenciaHeroi<<endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int OpcaoMenu, rodadas, caracteristica=0, EscolhaHeroi=0, PontuacaoJogador=0, PontuacaoComputador=0, EscolhaTime=0, VerificaEscolha, HeroiSorteado, CemiterioJogador[5], CemiterioComputador[5], VerificaSorteio;
    //Vetores do tipo Struct heroi onde os dados dos arquivos são armazenados.
    heroi TimeJogador[5], TimeComputador[5];
    do
    {
        do
        {
            //Menu de opções.
            cout<<"----------------------------------Guerra Civil----------------------------------";
            cout<<endl<<endl<<"Escolha a opção: ";
            cout<<endl<<"1 - Iniciar novo jogo.";
            cout<<endl<<"2 - Ler instruções.";
            cout<<endl<<"3 - Finalizar o jogo."<<endl;
            readInteger(">> ", OpcaoMenu);
            system("cls");
            if(OpcaoMenu==1)
            {
                rodadas=0;
                //Escolha do time por parte do jogador.
                do
                {
                    cout<<endl<<endl<<"Escolha o time: "<<endl<<"1 - Time Homem de Ferro."<<endl<<"2 - Time Capitão América."<<endl;
                    readInteger(">> ", EscolhaTime);
                }
                while(EscolhaTime!=1 && EscolhaTime!=2);
                //Estrutura de repetição e vetores CemiterioComputador e CemiterioJogador usados para verificação de heróis já utilizados na partida.
                for(int contador=0; contador<5; contador++)
                {
                    CemiterioComputador[contador]=5;
                    CemiterioJogador[contador]=5;
                }
                //Leitura de herois para cada time.
                if(EscolhaTime==1)
                {
                    cout<<endl<<"Time escolhido: Homem de Ferro.";
                    cout<<endl<<"Time adversário: Capitão América.";
                    LerHeroisHomemDeFerro(TimeJogador);
                    LerHeroisCapitaoAmerica(TimeComputador);
                }
                else
                {
                    cout<<endl<<"Time escolhido: Capitão América.";
                    cout<<endl<<"Time advesário: Homem de Ferro.";
                    LerHeroisHomemDeFerro(TimeComputador);
                    LerHeroisCapitaoAmerica(TimeJogador);
                }
                do
                {
                    cout<<endl<<endl<<"Escolha um herói do seu time: ";
                    cout<<endl<<endl<<"Time escolhido: "<<endl;
                    MostrarHerois(TimeJogador, CemiterioJogador);
                    cout<<endl<<endl<<"Time adversário: "<<endl;
                    MostrarHerois(TimeComputador, CemiterioComputador);
                    cout<<endl;
                    //Escolha do heroi por parte do jogador.
                    do
                    {
                        VerificaEscolha=0;
                        readInteger(">> ", EscolhaHeroi);
                        for(int contador=0; contador<5; contador++)
                        {
                            //Verificação de heróis utilizados
                            if(EscolhaHeroi-1==CemiterioJogador[contador])
                            {
                                VerificaEscolha++;
                            }
                        }
                        if(VerificaEscolha!=0)
                            cout<<"Herói indisponível, escolha outro: "<<endl;
                    }
                    while(VerificaEscolha!=0 || (EscolhaHeroi!=1 && EscolhaHeroi!=2 && EscolhaHeroi!=3 && EscolhaHeroi!=4 && EscolhaHeroi!=5));
                    CemiterioJogador[rodadas]=EscolhaHeroi-1;
                    //Escolha de característica para ser comparada.
                    do
                    {
                        cout<<endl<<"Escolha uma característica: "<<endl<<"1 - Agilidade."<<endl<<"2 - Força."<<endl<<"3 - Inteligência."<<endl;
                        readInteger(">> ", caracteristica);
                    }
                    while(caracteristica!=1 && caracteristica!=2 && caracteristica!=3);
                    //Sorteio e verificação de heróis para o Time Computador.
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
                    //Impressão dos heróis escolhidos.
                    cout<<endl<<"Característica escolhida: "<<caracteristica<<endl;
                    cout<<"Herói escolhido: "<<TimeJogador[EscolhaHeroi-1].NomeHeroi<<endl;
                    cout<<"Herói adversário: "<<TimeComputador[HeroiSorteado].NomeHeroi<<endl;
                    //Comparação das características e impressão dos resultado da rodada.
                    if(caracteristica==1)
                    {
                        if(TimeJogador[EscolhaHeroi-1].AgilidadeHeroi>TimeComputador[HeroiSorteado].AgilidadeHeroi)
                        {
                            PontuacaoJogador++;
                            cout<<"Você ganhou a rodada.";
                        }
                        else if(TimeJogador[EscolhaHeroi-1].AgilidadeHeroi<TimeComputador[HeroiSorteado].AgilidadeHeroi)
                        {
                            PontuacaoComputador++;
                            cout<<"Você perdeu a rodada.";
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
                            cout<<"Você ganhou a rodada.";
                        }
                        else if(TimeJogador[EscolhaHeroi-1].ForcaHeroi<TimeComputador[HeroiSorteado].ForcaHeroi)
                        {
                            PontuacaoComputador++;
                            cout<<"Você perdeu a rodada.";
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
                            cout<<"Você ganhou a rodada.";
                        }
                        else if(TimeJogador[EscolhaHeroi-1].InteligenciaHeroi<TimeComputador[HeroiSorteado].InteligenciaHeroi)
                        {
                            PontuacaoComputador++;
                            cout<<"Você perdeu a rodada.";
                        }
                        else
                        {
                            PontuacaoJogador++;
                            PontuacaoComputador++;
                            cout<<"Rodada empatada.";
                        }
                    }
                    cout<<endl<<"Pontuação Jogador: "<<PontuacaoJogador<<endl;
                    cout<<"Pontuação Computador: "<<PontuacaoComputador<<endl;
                    rodadas++;
                }
                while(PontuacaoJogador<3 && PontuacaoComputador<3);
                //Impressão do resultado da partida.
                if(PontuacaoJogador==3)
                {
                    cout<<endl<<"Parabéns, você venceu o jogo."<<endl;
                }
                else if(PontuacaoComputador==3)
                {
                    cout<<endl<<"O time adversário venceu o jogo."<<endl;
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
                //Instruções do jogo.
                cout<<endl<<"Instruções: ";
                cout<<endl<<"1 - O jogador deve escolher entre Time Homem de Ferro e o Time Capitão América.";
                cout<<endl<<"2 - Após a escolha, cada time recebe 5 heróis sorteados entre 10 hérois com 3 características diferentes: Agilidade(A), Força(F) e Inteligência(I).";
                cout<<endl<<"3 - O jogador escolhe um héroi e depois uma característica para ser comparada com o herói adversário, ganha a rodada o time que tiver o herói com mais pontos na característica escolhida.";
                cout<<endl<<"4 - Após um herói ser utilizado ele é automaticamente removido da partida.";
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
