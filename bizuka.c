#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

    void to_lowercase(char*str){
        for (int i = 0; str[i]; i++){
            str[i] = tolower((unsigned char)str[i]); // serve para o char funcionar com letras maiusculas e minusculas
        }
    }

int main(){
    int numeropc, npcmax = 3, npcmin = 0, numerojogador, soma, chutesomajog, jogmax = 3, chutesomapc, supnumjog;
    char menu[5];
    srand(time(NULL)); // para gerar numeros aleatorios

    while(1){
        printf("Vamos jogar bizuka!\n");
        printf("Digite o que deseja fazer:\n> jogar\n> regras\n> sair\n");
        scanf("%s", menu);
        to_lowercase(menu);

        if(strcmp(menu,"jogar") == 0){

                // Criar repeticao alternada entre jogador chutar primeiro e pc chutar primeiro:
            for(int rodada = 1; rodada <=100; rodada++){
                sleep(1.5);
                printf("------------------- Rodada %d -------------------\n", rodada);
                printf("O jogador pode jogar de 0 a %d.\nO computador pode jogar de 0 a %d.\n\n", jogmax, npcmax);
                sleep(3);
            if(rodada % 2 == 1){
// ----------------------------------------------------------------------------------------------------------------
                // Rodada do jogador chutar primeiro --------------------------------------------------------------
                printf("Voce sera o primeiro a tentar acertar a soma.\n");
                printf("Digite seu numero:\n");
                scanf("%d", &numerojogador);

                while(numerojogador > jogmax || numerojogador < 0){
                    printf("Numero invalido, digite novamente:\n");
                    scanf("%d", &numerojogador);
                }
                printf("O computador vai escolher um numero... \n");
                numeropc = (rand() % (npcmax - npcmin + 1)) + npcmin; // escolhe um numero aleatorio entre 0 e 3 para o computador

                sleep(1.5);
                printf("Numero escolhido!\n");
                sleep(1);
                printf("Quanto vai dar a soma?\n");
                scanf("%d", &chutesomajog); // pergunta para o jogador o chute para soma ---------------------

                supnumjog = (rand() % (jogmax + 1)); // gera um numero aleatorio que chuta qual o numero escolhido pelo jogador
                chutesomapc = supnumjog + numeropc; // soma o numero escolhido pelo pc com o numero que ele acredita que o jogador escolheu
            
                while (chutesomapc == chutesomajog){
                    supnumjog = (rand() % (jogmax + 1));
                    chutesomapc = supnumjog + numeropc;
                } // evita que o computador escolha um numero igual ao do jogador

                printf("O computador acha que a soma vai dar: %d\n", chutesomapc);
                sleep(2);
                printf("O computador escolheu: %d\n", numeropc);
                sleep(2);

                soma = numeropc + numerojogador;

                if(soma==0){printf("Deu bizuka! (Soma = 0)\n");} // Mostra o resultado da soma
                else{printf("A soma foi igual a: %d\n", soma);}

                sleep(2);

                if(chutesomajog==soma){jogmax--;}
                else if(chutesomapc==soma){npcmax--;}

                if(jogmax != 0 && npcmax != 0){ // se nao for o fim do jogo, faça:
                    if(chutesomajog==soma){
                        printf("PARABENS! Voce marcou 1 ponto. Agora voce deve escolher um numero de 0 ate %d.\n\n", jogmax);
                    }
                    else if(chutesomapc==soma){
                        printf(":(\nO computador acertou o chute. Agora ele pode escolher um numero de 0 ate %d.\n\n", npcmax);
                    }
                    else{
                        printf("Ninguem pontuou, o jogo continua.\n\n");
                    }
                }
                else if(jogmax == 0){
                    printf("VOCE GANHOU O JOGO! BIZUQUEIRO GALO!");
                    return 0;  // se for o fim do jogo jogador
                }
                else if(npcmax == 0){
                    printf("Bah, tu e ruim pia. Perdeu pro computador.");
                    return 0;  // se for o fim do jogo pc
                } }
            // Rodada do jogador chutar primeiro --------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------


                if(rodada % 2 == 0){
// ----------------------------------------------------------------------------------------------------------------
                // Rodada do jogador chutar por segundo --------------------------------------------------------------
                printf("Voce sera o segundo a tentar acertar a soma.\n");
                printf("Digite seu numero:\n");
                scanf("%d", &numerojogador);

                while(numerojogador > jogmax || numerojogador < 0){
                    printf("Numero invalido, digite novamente:\n");
                    scanf("%d", &numerojogador);
                }
                printf("O computador vai escolher um numero... \n");
                numeropc = (rand() % (npcmax - npcmin + 1)) + npcmin; // escolhe um numero aleatorio entre 0 e 3 para o computador

                sleep(1.5);
                printf("Numero escolhido!\n");
                sleep(1);

                supnumjog = (rand() % (jogmax + 1)); // gera um numero aleatorio que chuta qual o numero escolhido pelo jogador
                chutesomapc = supnumjog + numeropc; // soma o numero escolhido pelo pc com o numero que ele acredita que o jogador escolheu
                
                printf("O computador acha que a soma vai dar: %d\n", chutesomapc);
                sleep(2);

                printf("Quanto vai dar a soma?\n");
                scanf("%d", &chutesomajog); // pergunta para o jogador o chute para soma ---------------------

                while (chutesomajog == chutesomapc){
                    printf("Voce nao pode escolher o mesmo numero que o computador.\n Digite outro numero para soma:\n");
                    scanf("%d", &chutesomajog);
                } // evita que o jogador escolha um numero igual ao do pc
                sleep(2);
                printf("O computador escolheu: %d\n", numeropc);
                sleep(2);

                soma = numeropc + numerojogador;

                if(soma==0){printf("Deu bizuka! (Soma = 0)\n");} // Mostra o resultado da soma
                else{printf("A soma foi igual a: %d\n", soma);}

                sleep(2);

                if(chutesomajog==soma){jogmax--;}
                else if(chutesomapc==soma){npcmax--;}

                if(jogmax != 0 && npcmax != 0){ // se nao for o fim do jogo, faça:
                    if(chutesomajog==soma){
                        printf("PARABENS! Voce marcou 1 ponto. Agora voce deve escolher um numero de 0 ate %d.\n\n", jogmax);
                    }
                    else if(chutesomapc==soma){
                        printf(":(\nO computador acertou o chute. Agora ele pode escolher um numero de 0 ate %d.\n\n", npcmax);
                    }
                    else{
                        printf("Ninguem pontuou, o jogo continua.\n\n");
                    }
                }
                else if(jogmax == 0){
                    printf("VOCE GANHOU O JOGO! BIZUQUEIRO GALO!");
                    return 0;  // se for o fim do jogo jogador
                }
                else if(npcmax == 0){
                    printf("Bah, tu e ruim pia. Perdeu pro computador.");
                    return 0;  // se for o fim do jogo pc
                } }
            // Rodada do jogador chutar por segundo --------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

            } // chave que fecha o "for" que alterna as rodadas do computador e do jogador;
              

        }

        else if(strcmp(menu, "regras") == 0){
            printf("1: Para jogar, escolha um numero inteiro de 0 a 3.\n");
            printf("2: O computador escolhera um numero inteiro aleatorio de 0 a 3.\n");
            printf("3: Para pontuar voce deve acertar a soma do numero que voce escolheu com o que o computador escolheu.\n");
            printf("4: Na primeira rodada voce comeca tentando adivinhar a soma e o computador tenta apos voce.\n");
            printf("5: Na segunda rodada o computador comeca tentando adivinhar a soma e voce tenta apos o chute dele.\n");
            printf("6: O seu chute de soma e do computador nao podem ser iguais.\n");
            printf("7: Caso voce acerte a soma, o numero maximo que voce pode jogar diminui 1 unidade.\n");
            printf("8: Caso o computador acerte a soma, o numero maximo que ele pode jogar diminui 1 unidade.\n");
            printf("9: Caso nenhum dos dois acerte a soma, ambos continuam podendo escolher numeros de 0 ate no maximo 3.\n");
            printf("10: Ganha o jogo quem so puder escolher o numero 0.\n");
            printf("11: Para comecar um jogo, compile o codigo novamente e envie 'jogar'\n");
            break; // finaliza o programa
        }

        else if(strcmp(menu, "sair") == 0){
            printf("Programa encerrado pelo usuario.");
            break;
        }

        else if(strcmp(menu, "secreto") == 0){
            printf("");
        }

    } // essa chave fecha o while que repete o programa caso o infeliz do usuario digite algo diferente dos comandos do menu

    return 0;

}